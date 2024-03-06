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

// A utility function to print a string
// Base case for the variadic template print function
void print() {
    // Prints newline when there are no more arguments
    std::cout << std::endl;
}

template<typename T, typename... Args>
void print(const T &firstArg, const Args &... args) {
    std::cout << firstArg;
    // A recursive call on all the arguments (I think)
    print(args...);
}

template <typename OscillatorType>
struct smoothOsc {
    OscillatorType osc;
    float targetFreq = 440.f;
	float frequency = targetFreq;
    float modIndex;

    // Envelop segment to linearly smooth
    gam::Seg<> smoothInputFreq; // This is the garget value!

    smoothOsc(float speed, float freq = 440.f)
    : targetFreq(freq), frequency(freq), smoothInputFreq(speed, freq, freq, 0.f) {
            // calling Seg constructor so default = freq
        smoothInputFreq.length(speed);
        smoothInputFreq = targetFreq;
    }

    void updateSmoothFreq() {
        smoothInputFreq = targetFreq;
    }

    void setSmoothingLen(float targetLen) {
        smoothInputFreq.length(targetLen);
    }

    void setSmoothFreq(float targetFreq) {
        this->targetFreq = targetFreq;
        updateSmoothFreq();
    }

    float generate() {
        frequency = smoothInputFreq();

        osc.freq(frequency);
        return osc(); // Generate and return oscillator output
    }

};

class Oscillator {
public:
    enum OscillatorType { SINE, SAW, SQUARE };
    OscillatorType currentOscType;

    Oscillator(OscillatorType oscType) : currentOscType(oscType) {
        // Initialize oscillator based on the selected type
        changeOscillator(oscType);
    }

    void changeOscillator(OscillatorType oscType) {
        currentOscType = oscType;
        // Initialize oscillator based on the selected type
        switch (currentOscType) {
        case SINE:
            currentGenerateFunc = std::bind(&smoothOsc<gam::Sine<>>::generate, &osc_sine1);
            currentSetSmoothFreqFunc = std::bind(&smoothOsc<gam::Sine<>>::setSmoothFreq, &osc_sine1, std::placeholders::_1);
            currentUpdateSmoothFreqFunc = std::bind(&smoothOsc<gam::Sine<>>::updateSmoothFreq, &osc_sine1);
            currentSetSmoothingLenFunc = std::bind(&smoothOsc<gam::Sine<>>::setSmoothingLen, &osc_sine1, std::placeholders::_1);
            break;
        case SAW:
            currentGenerateFunc = std::bind(&smoothOsc<gam::Saw<>>::generate, &osc_saw1);
            currentSetSmoothFreqFunc = std::bind(&smoothOsc<gam::Saw<>>::setSmoothFreq, &osc_saw1, std::placeholders::_1);
            currentUpdateSmoothFreqFunc = std::bind(&smoothOsc<gam::Saw<>>::updateSmoothFreq, &osc_saw1);
            currentSetSmoothingLenFunc = std::bind(&smoothOsc<gam::Saw<>>::setSmoothingLen, &osc_saw1, std::placeholders::_1);
            break;
        case SQUARE:
            currentGenerateFunc = std::bind(&smoothOsc<gam::Square<>>::generate, &osc_square1);
            currentSetSmoothFreqFunc = std::bind(&smoothOsc<gam::Square<>>::setSmoothFreq, &osc_square1, std::placeholders::_1);
            currentUpdateSmoothFreqFunc = std::bind(&smoothOsc<gam::Square<>>::updateSmoothFreq, &osc_square1);
            currentSetSmoothingLenFunc = std::bind(&smoothOsc<gam::Square<>>::setSmoothingLen, &osc_square1, std::placeholders::_1);
            break;
        }
    }

    float generate() { return currentGenerateFunc(); }
    void setSmoothFreq(float freqToSet) { currentSetSmoothFreqFunc(freqToSet); }
    void updateSmoothFreq() { currentUpdateSmoothFreqFunc(); }
    void setSmoothingLen(float desiredLen) { currentSetSmoothingLenFunc(desiredLen); }

    bool windowOpen = true; // Add this flag at a global scope or within your class

    // Method to render the oscillator's ImGui controls
    void renderUI() {
        
        // Impliment the X functionality later!

        // if (!windowOpen) return;
        
        ImGui::Begin("Oscillator Controls", &windowOpen, ImGuiWindowFlags_AlwaysAutoResize);
        
        // Render a dropdown to change the oscillator type
        const char* oscTypes[] = { "Sine", "Saw", "Square" };
        int currentItem = static_cast<int>(currentOscType);
        if (ImGui::Combo("Type", &currentItem, oscTypes, IM_ARRAYSIZE(oscTypes))) {
            changeOscillator(static_cast<OscillatorType>(currentItem));
            setSmoothingLen(smoothingLength);
        }

        //print("RENDERING SLIDERS");
        // Render a slider to control the frequency
        if (ImGui::SliderFloat("Frequency", &this->targetFreq, 20.0f, 1000.0f, "%.1f Hz")) {
            setSmoothFreq(targetFreq);
            updateSmoothFreq();
        }

        // Optionally, render additional controls as needed
        if (ImGui::SliderFloat("Smoothing Length", &this->smoothingLength, 0.f, 1.0f, "%.2f")) {
            setSmoothingLen(smoothingLength);
        }

        ImGui::End(); // Close the ImGui window
    }

private:
    float targetFreq = 440.f;
    float smoothingLength = 0.1f;
    smoothOsc<gam::Sine<>> osc_sine1{smoothingLength, targetFreq};
    smoothOsc<gam::Saw<>> osc_saw1{smoothingLength, targetFreq};
    smoothOsc<gam::Square<>> osc_square1{smoothingLength, targetFreq};

    std::function<float()> currentGenerateFunc; // Function pointer to current generate function
    std::function<void(float)> currentSetSmoothFreqFunc;
    std::function<void()> currentUpdateSmoothFreqFunc;
    std::function<void(float)> currentSetSmoothingLenFunc;

};

class Synth {
public: // For now organize it later lol
    Oscillator osc1{Oscillator::SINE};

    float output = 0.f;
    float generate() {
        output = 0.f;        
        output += osc1.generate() * 0.1f;
        return output;
    }

    void renderUI() {
        osc1.renderUI();
    }

};

void audioCB(gam::AudioIOData& io) {
    if (isAudioActive) {
        // my synth with proccessing code insdie
		Synth& synth = *(Synth *)io.user();
		// Generate sine wave and mix or replace input signal
		for(int i=0; i<io.framesPerBuffer(); ++i){
			// Output the mixed signal or just the sine wave
            float sample = synth.generate();
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

    print("SETTING SYNTH ATTRIBUTES!!");
    //Set Synth Attributes!

    synth.osc1.changeOscillator(Oscillator::SINE);
    synth.osc1.setSmoothingLen(0.5f);
	
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
