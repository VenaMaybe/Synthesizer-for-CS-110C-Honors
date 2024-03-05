#include <iostream>
#include "Gamma/Gamma.h"
#include "Gamma/AudioIO.h"
#include "Gamma/Envelope.h"
#include "Gamma/Oscillator.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Include GLFW support

// Global control variable
bool isAudioActive = true;

struct Synth {
    float targetFreq;
	float frequency = 440.0f;
    
    gam::Sine<> sine;
    gam::Sine<> mod;

    // Envelop segment to linearly smooth
    gam::Seg<> smoothInputFreq; // This is the garget value!

    Synth() : targetFreq(frequency) { // Initial frequency set to frequency Hz
        smoothInputFreq.length(0.05f);   // Set envelope segment length to 0.5 seconds
        smoothInputFreq = targetFreq;  // Set initial target value of the envelope to 440 Hz
    }

    // Function to update the target frequency and start smoothing
    void setFrequency(float newFreq) {
        targetFreq = newFreq;
        smoothInputFreq = newFreq; // Assign new target frequency to envelope
    }

    // Generate and return the current audio sample
    // Anything in here happens at audio rate per Callback!
    float generate() {
        // Use the current value of the frequency envelope to set the oscillator's frequency
        smoothInputFreq = targetFreq;
        frequency = smoothInputFreq();

        mod.freq(frequency*2);
        sine.freq(frequency + mod());


        return sine() * 0.1; // Return oscillator output (scaled down)
    }
};

void audioCB(gam::AudioIOData& io) {
    if (isAudioActive) {
        // my synth with proccessing code insdie
		Synth& synth = *(Synth *)io.user();
		// Generate sine wave and mix or replace input signal
		for(int i=0; i<io.framesPerBuffer(); ++i){
			// Output the mixed signal or just the sine wave
			io.out(0,i) = synth.generate();; // Left channel
			io.out(1,i) = synth.generate();; // Right channel
		}
    } else {
        // Output silence
        for(int i = 0; i < io.framesPerBuffer(); ++i) {
            io.out(0, i) = 0;
            io.out(1, i) = 0;
        }
    }
}

int main() {
	if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    } else {
		std::cout << "Initalized GLFW\n";
	}

    // Setup window and ImGui context (using GLFW & OpenGL3)
    // Note: These are placeholder functions; refer to ImGui and GLFW documentation for details
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

	// Make the window's context current
    glfwMakeContextCurrent(window);

	ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130"); // Use your OpenGL version here

    // Audio setup
	int blockSize = (256*4);		// how many samples per block?
	float sampleRate = 44100;		// sampling rate (samples/second)
	int outputChannels = 2;			// how many output channels to open
	int inputChannels = 0;			// how many input channels to open
	Synth synth;                	// external data to be passed into callback
	
	//Get default output/input
	gam::AudioDevice adevi = gam::AudioDevice::defaultInput();
	gam::AudioDevice adevo = gam::AudioDevice::defaultOutput();
	
	// create an audio i/o object using default input and output devices
	gam::AudioIO io(blockSize, sampleRate, audioCB, &synth, outputChannels, inputChannels);

	//Set it explicitly
	io.deviceIn(adevi);
	io.deviceOut(adevo);


	// set the global sample rate "subject"
	gam::sampleRate(io.framesPerSecond());

    io.start();

    while (!glfwWindowShouldClose(window)) { // Checks if the window has been instructed to close.
        glfwPollEvents(); // Processes window events like keyboard and mouse input.

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a checkbox to control audio
        ImGui::Checkbox("Enable Audio", &isAudioActive);
		ImGui::SliderFloat("Frequency", &synth.targetFreq, 20.0f, 1000.0f, "%.1f Hz");

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}
