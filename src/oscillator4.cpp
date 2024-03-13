// Oscillator4.cpp
#include <Gamma/Oscillator.h>
#include "imgui.h" // For renderUI

#include "SmoothOscillator.h"
#include "Oscillator4.h"

Oscillator4::Oscillator4(WAVEFORM oscType)
: oscType(oscType), targetFreq(440.f), smoothingLen(0.1f), Module("Osc4") {
    changeOscillator(oscType);
    // Initialize the output1.signal with a new Signal object
    output1.signal = std::make_shared<Signal>();
    // Optionally add output1 to the outputs vector if you want to use it for modular connections
    outputs.push_back(output1);
}

void Oscillator4::changeOscillator(WAVEFORM oscType) {
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
};

float Oscillator4::generate() {
    float output = currentOsc->generate();
    
    

    // Assuming Oscillator4 has a single output for simplicity
    if (!outputs.empty() && outputs[0].signal) {
        output1.signal->setValue(output);
    }

    return output;
//    return outputValue;

//    return currentOsc->generate();
};

void Oscillator4::setSmoothFreq(float freqToSet) {
    ISmoothable* smoothable = dynamic_cast<ISmoothable*>(currentOsc.get());
    if (smoothable) {
        smoothable->setSmoothFreq(freqToSet);
    }
};

void Oscillator4::setSmoothingLen(float desiredLen) {
    ISmoothable* smoothable = dynamic_cast<ISmoothable*>(currentOsc.get());
    if (smoothable) {
        smoothable->setSmoothLen(desiredLen);
    }
};

void Oscillator4::renderUI(const std::string windowTitle) {
    // Each element is rendered from it's base?
    // Maybe some kinda render tree?

    ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize);

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

