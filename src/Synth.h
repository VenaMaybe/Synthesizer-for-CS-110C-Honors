#ifndef SYNTH_H
#define SYNTH_H

#include "Oscillator4.h"
#include <vector>
#include <memory>

class Synth {
public: // For now organize it later lol

    std::vector<std::shared_ptr<Module>> modules;

    Synth() {
        // Add an Oscillator4 module set to SINE waveform
        auto osc1 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc1);

        // Add another Oscillator4 module set to SAW waveform
        auto osc2 = std::make_shared<Oscillator4>(Oscillator4::SAW);
        addModule(osc2);
    }

    void addModule(std::shared_ptr<Module> module) {
        modules.push_back(module);
    }

    void processAudio() {
        for (auto& module : modules) {
            // Assume generate() updates outputs based on inputs
            module->generate();
        }
        // Additional logic to handle signal routing between modules
    }

    void renderModulesUI() {
        for (auto& module : modules) {
            module->renderUI(module->getUniqueName());
            // Additional ImGui logic for drawing connections
        }
    }

    //Oscillator4 osc1{Oscillator4::SINE};
    //Oscillator4 osc2{Oscillator4::SINE};

    float output = 0.f;
    float generate() {
        output = 0.f;        
        //output += osc1.generate();
        //output += osc2.generate();
        processAudio();
        return output;
    }

    void renderUI() {
        renderModulesUI();
    }

};

#endif // SYNTH_H