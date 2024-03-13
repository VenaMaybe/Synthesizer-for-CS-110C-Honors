#include <memory> // unique_ptr

#include <Gamma/Oscillator.h>

#include "module.h"
#include "smoothOscillator.h"

// This is an oscillator with 4 wave selecitons

class Oscillator4 : public Module {
public:
    enum WAVEFORM { SINE, SAW, SQUARE};

    float targetFreq = 440.f;
    float smoothingLen = 0.1f;

    // Holds pointer to any child of BaseOsc
    std::unique_ptr<IBaseOsc> currentOsc;

    // Constructor!
    Oscillator4(WAVEFORM oscType) {
        changeOscillator(oscType);
    }

    void changeOscillator(WAVEFORM oscType) {
        switch (oscType) {
        case SINE:
            currentOsc = std::make_unique<SmoothOsc<gam::Sine<>>>(smoothingLen, targetFreq);
            break;
        case SAW:
            currentOsc = std::make_unique<SmoothOsc<gam::Saw<>>>(smoothingLen, targetFreq);
            break;
        case SQUARE:
            currentOsc = std::make_unique<SmoothOsc<gam::Square<>>>(smoothingLen, targetFreq);
            break;
        }
    }

    //SmoothOsc<gam::Sine<>> osc{1.f, 440.f};

    float generate() override {
        return currentOsc->generate();
    }

    void setSmoothFreq(float freqToSet) {
        ISmoothable* smoothable = dynamic_cast<ISmoothable*>(currentOsc.get());
        if (smoothable) {
            smoothable->setSmoothFreq(freqToSet);
        }
    }

    void setSmoothingLen(float desiredLen) {
        ISmoothable* smoothable = dynamic_cast<ISmoothable*>(currentOsc.get());
        if (smoothable) {
            smoothable->setSmoothLen(desiredLen);
        }
    }

    void renderUI() override {
    }
};