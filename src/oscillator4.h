// Oscillator4.h
#ifndef OSCILLATOR4_H
#define OSCILLATOR4_H

#include <memory>
#include "iBaseOscillators.h"
#include "module.h" // Only if Module needs to be known in this declaration

/*
Has an output!!
*/

class Oscillator4 : public Module {
public:
    enum WAVEFORM { SINE, SAW, SQUARE };

    Oscillator4(WAVEFORM oscType);

    void changeOscillator(WAVEFORM oscType);
    float generate() override;
    void setSmoothFreq(float freqToSet);
    void setSmoothingLen(float desiredLen);
    void renderUI(const std::string windowTitle) override;

private:
    Connection output1;

    bool soundEnabled;
    float targetFreq;
    float smoothingLen;
    WAVEFORM oscType;
    
    std::unique_ptr<IBaseOsc> currentOsc;
};

#endif // OSCILLATOR4_H
