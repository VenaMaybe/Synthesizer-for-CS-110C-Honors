struct AudioSignal {
    float value; // For simplicity, could be expanded for more complex signal representation
};

class IAudioModule {
public:
    virtual void process(AudioSignal& input, AudioSignal& output) = 0;
    // Other necessary virtual methods for audio processing
};
