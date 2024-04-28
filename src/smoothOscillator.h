#ifndef SMOOTH_OSCILLATOR_H
#define SMOOTH_OSCILLATOR_H

#include "Gamma/Envelope.h"
#include "imgui.h"

#include "iBaseOscillators.h"


//
template <typename WAVEFORM>
class SmoothOsc : public IBaseOsc, public ISmoothable {
public:
    WAVEFORM osc;
    gam::Seg<> smoothedFreq;
    float targetFreq;
    float targetLen;

    // speed is in seconds, freq in hrtz
    SmoothOsc(float speed, float freq = 440.f)
    : targetFreq(freq), targetLen(speed), smoothedFreq(speed, freq, freq) {
        smoothedFreq.length(speed);
    }
    
    float generate() override {
        osc.freq(smoothedFreq());
        return osc(); // Generates and returns osc output
    }

    void setFreq(float freq) override {smoothedFreq.levels(freq, freq);};

    // Getters
    float getSmoothFreq() const override {return targetFreq;}
    float getSmoothLen() const override {return targetLen;}

    // This sets the frequency to approach
    void setSmoothFreq(float freq) {smoothedFreq = freq;}
    void setSmoothLen(float t) {smoothedFreq.length(t);}
    

    bool soundEnabled = true;
    void renderUI() override {

        // Render a slider to control the frequency
        if (ImGui::SliderFloat("Frequency", &targetFreq, 20.0f, 1000.0f, "%.1f Hz")) {
            setSmoothFreq(targetFreq);
        }

        // Optionally, render additional controls as needed
        if (ImGui::SliderFloat("Smoothing Freq", &targetLen, 0.f, 1.0f, "%.2f")) {
            setSmoothLen(targetLen);
        }
    }
};

#endif // SMOOTH_OSCILLATOR_H