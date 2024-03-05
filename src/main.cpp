#include <iostream>
#include "Gamma/Gamma.h"
#include "Gamma/AudioIO.h"
#include "Gamma/Oscillator.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Include GLFW support

// Global control variable
bool isAudioActive = true;

struct UserData {
    float ampL, ampR;
	float frequency = 440.0f;
    gam::Sine<> sine;
};

void audioCB(gam::AudioIOData& io) {
    UserData& user = *(UserData*)io.user();
    if (isAudioActive) {
        // Your existing audio processing code...
		UserData& user = *(UserData *)io.user();

		// Processing!!
		user.sine.freq(user.frequency);
		float ampL = user.ampL;
		float ampR = user.ampR;

		// Generate sine wave and mix or replace input signal
		for(int i=0; i<io.framesPerBuffer(); ++i){
			float sine = user.sine(); // Generate sine wave sample
			//float input = io.in(0,i); // Original input signal
			float mixedSignal = (sine * 0.5f); // + (input * 0.f); // Example: mix sine with input signal

			// Output the mixed signal or just the sine wave
			io.out(0,i) = mixedSignal * ampL; // Left channel
			io.out(1,i) = mixedSignal * ampR; // Right channel
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
	int blockSize = (256*8);		// how many samples per block?
	float sampleRate = 44100;		// sampling rate (samples/second)
	int outputChannels = 2;			// how many output channels to open
	int inputChannels = 1;			// how many input channels to open
	UserData user = {-0.5, 0.5};	// external data to be passed into callback
	
	//Get default output/input
	gam::AudioDevice adevi = gam::AudioDevice::defaultInput();
	gam::AudioDevice adevo = gam::AudioDevice::defaultOutput();
	
	// create an audio i/o object using default input and output devices
	gam::AudioIO io(blockSize, sampleRate, audioCB, &user, outputChannels, inputChannels);

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
		ImGui::SliderFloat("Frequency", &user.frequency, 20.0f, 1000.0f, "%.1f Hz");

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
