#include <iostream>
#include "Gamma/Gamma.h"
#include "Gamma/AudioIO.h"
#include "Gamma/Envelope.h"
#include "Gamma/Oscillator.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Include GLFW support

// My includes
#include "vena_utility.h"
#include "synth.h"

// Global control variable
bool isAudioActive = true;
float mainVol = 0.1f;
gam::Seg<> smoothGain(0.05f, mainVol, mainVol);

// Audio io proccessing
void audioCB(gam::AudioIOData& io) {
    if (isAudioActive) {
        // my synth with proccessing code insdie
		Synth& synth = *(Synth *)io.user();
		for(int i=0; i<io.framesPerBuffer(); ++i) {
            float sample = synth.generate();
            sample *= smoothGain();
			io.out(0,i) = sample; // Left channel
			io.out(1,i) = sample; // Right channel
		}
    } else {
        // Output silence
        for(int i = 0; i < io.framesPerBuffer(); ++i) {
            io.out(0, i) = 0;
            io.out(1, i) = 0;
        }
    }
}

// main loop
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
	int blockSize = (256*8);		// how many samples per block?
	float sampleRate = 44100;		// sampling rate (samples/second)
	int outputChannels = 2;			// how many output channels to open
	int inputChannels = 0;			// how many input channels to open
	Synth synth;                	// external data to be passed into callback

    print("SETTING SYNTH ATTRIBUTES!!");
    //Set Synth Attributes!

    //synth.osc1.changeOscillator(Oscillator4::SINE);
    //synth.osc1.setSmoothingLen(0.5f);
	//////////////////////////////

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

        // Create a checkbox to control audio and slider for main volume
        ImGui::Checkbox("Enable Audio", &isAudioActive);
        if (ImGui::SliderFloat("Global Volume", &mainVol, 0.f, 1.0f, "%.2f")) {
            smoothGain = std::clamp(mainVol, 0.f, 0.5f);
        }
		
        // Main synth Ui
        synth.renderUI();

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
