#ifndef I_BASE_OSCILLATORS_H
#define I_BASE_OSCILLATORS_H

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

#endif // I_BASE_OSCILLATORS_H