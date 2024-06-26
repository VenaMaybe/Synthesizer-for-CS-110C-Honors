// Oscillator4.cpp
#include <Gamma/Oscillator.h>
#include "imgui.h" // For renderUI

#include "smoothOscillator.h"
#include "oscillator4.h"

// Osc Constructor
Oscillator4::Oscillator4(WAVEFORM oscType)
: oscType(oscType), targetFreq(440.f), smoothingLen(0.1f), Module("Osc4"),
        output1("Osc Output1"), soundEnabled(false) {
    
    
    output1.connectionName = baseName + " " + std::to_string(typeCounts.at(baseName)) + " Output 1"; // kinda scuffed add to module later
    addOutput(output1);
        
    changeOscillator(oscType);
    // Initialize the output1.signal with a new Signal object
    //output1.signal = std::make_shared<Signal>();
    // Optionally add output1 to the outputs vector if you want to use it for modular connections
    //outputs.push_back(output1);
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
    float output = currentOsc->generate() * soundEnabled;
    // Assuming Oscillator4 has a single output for simplicity
    if (!outputs.empty() && outputs[0].signal) {
        output1.signal->setValue(output);
        output1.signal->finalDest = true;
    }
    return output;
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


    // Checkbox on the right
    if (ImGui::Checkbox("On", &soundEnabled)) {
    };
    // This renders the elements related to a general oscilator
    ImGui::SameLine(); // Keeps the next widget on the same line

    // Renders freq and smoothing freq sliders!
    currentOsc->renderUI();
    ImGui::End(); // Close the ImGui window
}

