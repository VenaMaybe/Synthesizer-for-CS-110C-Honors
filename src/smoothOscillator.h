#include "Gamma/Envelope.h"


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
};


//
template <typename WAVEFORM>
class SmoothOsc : public IBaseOsc, public ISmoothable {
public:
    WAVEFORM osc;
    gam::Seg<> smoothedFreq;

    // speed is in seconds, freq in hrtz
    SmoothOsc(float speed, float freq = 440.f)
    : smoothedFreq(speed, freq, freq) {
        smoothedFreq.length(speed);
    }
    
    float generate() override {
        osc.freq(smoothedFreq());
        return osc(); // Generates and returns osc output
    }

    void renderUI() override {
        // Uh render stuff here later
    }

    void setFreq(float freq) override {smoothedFreq.levels(freq, freq);};
    // This sets the frequency to approach
    void setSmoothFreq(float freq) {smoothedFreq = freq;};
    void setSmoothLen(float t) {smoothedFreq.length(t);};

};