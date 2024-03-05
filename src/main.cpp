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
    float targetFreq;
	float frequency;
    float modIndex;

    // Envelop segment to linearly smooth
    gam::Seg<> smoothInputFreq; // This is the garget value!

    smoothOsc(float speed, float freq = 440.f) : targetFreq(freq), frequency(freq) {
        smoothInputFreq.length(speed);
        smoothInputFreq = targetFreq;
    }

    void updateSmoothFreq() {
        smoothInputFreq = targetFreq;
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

class Oscilator {
public:
    enum oscilator {SINE, SAW, SQUARE};
    oscilator osc;

    Oscilator(oscilator osc) : {
        this->osc = osc;
        switch (osc)
        {
        case SINE:
            /* code */
            break;
        case SAW:
            /* code */
            break;
        case SQUARE:
            /* code */
            break;
        default:
            break;
        }
    }

private:
    float smoothingLength = 0.01f;
    float output = 0.f;

    smoothOsc<gam::Sine<>> osc_sine1{smoothingLength};
    //smoothOsc<gam::Tri<>> osc_tri1{smoothingLength};
    smoothOsc<gam::Saw<>> osc_saw1{smoothingLength};
    smoothOsc<gam::Square<>> osc_square1{smoothingLength};
};

struct Synth {

    float targetFreq;
    
    smoothOsc<gam::Sine<>> osc_sine1{0.5f};
    smoothOsc<gam::Sine<>> mod_sine1{0.5f};

    // Envelop segment to linearly smooth
    //gam::Seg<> smoothInputFreq; // This is the garget value!
    //Synth() : targetFreq(frequency) { // Initial frequency set to frequency Hz
    //    smoothInputFreq.length(0.05f);   // Set envelope segment length to 0.5 seconds
    //    smoothInputFreq = targetFreq;  // Set initial target value of the envelope to 440 Hz
    //}
    // Function to update the target frequency and start smoothing
    //void setFrequency(float newFreq) {
    //    targetFreq = newFreq;
    //    smoothInputFreq = newFreq; // Assign new target frequency to envelope
    //}
    // Generate and return the current audio sample
    // Anything in here happens at audio rate per Callback!

    float output = 0.f;
    float generate() {
        output = 0.f;
        // Use the current value of the frequency envelope to set the oscillator's frequency
        
        //osc_sine1.smoothInputFreq = targetFreq;
        //frequency = osc_sine1.smoothInputFreq();

        //mod_sine1.freq(frequency*2);
        //osc_sine1.freq(frequency + mod_sine1());

        //osc_sine1.setFM(mod_sine1.generate());
        output += osc_sine1.generate() * 0.1; // Return oscillator output (scaled down)
        //output += mod_sine1.generate() * 0.1;
        
        return output;
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
		if(ImGui::SliderFloat("Frequency", &synth.osc_sine1.targetFreq, 20.0f, 1000.0f, "%.1f Hz")) {
            synth.osc_sine1.updateSmoothFreq();
        };

        if(ImGui::SliderFloat("Frequency Mod", &synth.mod_sine1.targetFreq, 20.0f, 1000.0f, "%.1f Hz")) {
            synth.mod_sine1.updateSmoothFreq();
        };

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
