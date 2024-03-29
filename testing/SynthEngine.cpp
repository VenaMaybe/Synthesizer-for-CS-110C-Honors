#include <iostream>

#include "Gamma/Gamma.h"
#include "Gamma/AudioIO.h"

#include "Gamma/Oscillator.h"


// A user defined class that can be accessed from the audio callback
struct Synth{
	float ampL, ampR;
	gam::Sine<> osc_sine1;
};


// create a callback for generating a block of samples
//
//		This is called by the audio system everytime it needs a new block of
// audio samples to send to the soundcard. The interval is regular and
// determined by the buffere size and sample rate.
//
void audioCB(gam::AudioIOData& io){
    Synth& user = *(Synth *)io.user();
    float ampL = user.ampL;
    float ampR = user.ampR;

    // Generate sine wave and mix or replace input signal
    for(int i=0; i<io.framesPerBuffer(); ++i){
        float sine = user.osc_sine1(); // Generate sine wave sample
        //float input = io.in(0,i); // Original input signal
        float mixedSignal = (sine * 0.2f); // + (input * 0.f); // Example: mix sine with input signal

        // Output the mixed signal or just the sine wave
        io.out(0,i) = mixedSignal * ampL; // Left channel
        io.out(1,i) = mixedSignal * ampR; // Right channel
    }
}



int main(){
	/*
	// check if we have any audio devices
	if(gam::AudioDevice::numDevices() == 0){
		printf("Error: No audio devices detected. Exiting...\n");
		exit(EXIT_FAILURE);
	}

	// list all detected audio devices
	printf("Audio devices found:\n");
	gam::AudioDevice::printAll();
	printf("\n");
	*/

	// set parameters of audio stream Meow
	int blockSize = (256*8);		// how many samples per block?
	float sampleRate = 44100;		// sampling rate (samples/second)
	int outputChannels = 2;			// how many output channels to open
	int inputChannels = 1;			// how many input channels to open
	Synth user = {-0.5, 0.5};	// external data to be passed into callback
	
	//Get default output/input
	gam::AudioDevice adevi = gam::AudioDevice::defaultInput();
	gam::AudioDevice adevo = gam::AudioDevice::defaultOutput();
	
	// create an audio i/o object using default input and output devices
	gam::AudioIO io(blockSize, sampleRate, audioCB, &user, outputChannels, inputChannels);

	//Set it explicitly
	io.deviceIn(adevi);
	io.deviceOut(adevo);

	// we can also set the input and output devices explicitly
	// use device 0 for input and output
	//io.deviceIn (AudioDevice(0));
	//io.deviceOut(AudioDevice(0));

	// use devices matching keyword in name
	//io.deviceIn (AudioDevice("Microphone", AudioDevice::INPUT));
	//io.deviceOut(AudioDevice("Built-in", AudioDevice::OUTPUT));

	if(io.channelsOut() < 2){
		printf("This example needs at least 2 output channels to start streaming. Exiting...\n");
		return 0;
	}
	if(io.channelsIn() < 1){
		printf("This example needs at least 1 input channel to start streaming. Exiting...\n");
		return 0;
	}
	
	// set the global sample rate "subject"
	gam::sampleRate(io.framesPerSecond());
	
	// sets the frequency
	user.osc_sine1.freq(440);

	// start the audio stream
	io.start();
	
	// print some information about the i/o streams
	printf("Audio stream info:\n");
	io.print();
	
	printf("\nPress 'enter' to quit...\n"); getchar();
	return 0;
}
