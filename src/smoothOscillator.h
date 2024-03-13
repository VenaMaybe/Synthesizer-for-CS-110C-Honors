#include "Gamma/Envelope.h"
#include "imgui.h"

class IBaseOsc {
public:
    virtual ~IBaseOsc() {}
    virtual float generate() = 0;
    virtual void renderUI() = 0;
    virtual void setFreq(float freq) = 0;
};

class ISmoothable {
public:
    virtual ~ISmoothable() {}
    virtual void setSmoothFreq(float freq) = 0;
    virtual void setSmoothLen(float length) = 0;
    virtual float getSmoothFreq() const = 0;
    virtual float getSmoothLen() const = 0;
};


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
    

    void renderUI() override {
        // This renders the elements related to a general oscilator

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