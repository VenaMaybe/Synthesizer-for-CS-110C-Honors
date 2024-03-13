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
    WAVEFORM oscType;

    // Holds pointer to any child of BaseOsc
    std::unique_ptr<IBaseOsc> currentOsc;

    // Constructor!
    Oscillator4(WAVEFORM oscType) 
    : oscType(oscType) {
        changeOscillator(oscType);
    }

    void changeOscillator(WAVEFORM oscType) {
        // Before changing the oscillator, update targetFreq and smoothingLen
        if (auto* smoothable = dynamic_cast<ISmoothable*>(currentOsc.get())) {
            targetFreq = smoothable->getSmoothFreq();
            smoothingLen = smoothable->getSmoothLen();
        }

        this->oscType = oscType;
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
        // Each element is rendered from it's base?
        // Maybe some kinda render tree?

        ImGui::Begin("Oscillator Controls", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

        // Render a dropdown to change the oscillator type
        const char* oscTypes[] = { "Sine", "Saw", "Square" };
        int currentItem = static_cast<int>(oscType);
        if (ImGui::Combo("Wave", &currentItem, oscTypes, IM_ARRAYSIZE(oscTypes))) {
            changeOscillator(static_cast<WAVEFORM>(currentItem));
            //setSmoothingLen(smoothingLength); WILL MB MESS UP LATER!!!
        }

        // Renders freq and smoothing freq sliders!
        currentOsc->renderUI();
        ImGui::End(); // Close the ImGui window
    }
};