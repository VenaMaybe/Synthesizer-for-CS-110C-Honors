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
        auto osc2 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc2);

        auto osc3 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc3);

        auto osc4 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc4);

        auto osc5 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc5);

        auto osc6 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc6);

        auto osc7 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc7);

        auto osc8 = std::make_shared<Oscillator4>(Oscillator4::SINE);
        addModule(osc8);
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
        output = 0.f; // Reset output to 0
        processAudio(); // Ensure all modules have processed their current state

        for (auto& module : modules) {
            // For simplicity, assume each module's generate method updates its internal state
            // and returns a float representing its contribution to the final output
            if (!module->outputs.empty()) {
                output += module->outputs[0].signal->getValue();
            }
        }

        output /= modules.size();

        // Here, output contains the summed signal from all modules
        return output;
    }

    void renderUI() {
        renderModulesUI();
    }

};

#endif // SYNTH_H