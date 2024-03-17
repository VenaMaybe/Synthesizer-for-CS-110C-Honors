#ifndef MODULE_H
#define MODULE_H

// Holds a value between -5 and 5
#include <vector>
#include <memory>
#include <string>
#include <map>

struct Signal {
    double value = 0.0; // Default value

    void setValue(double newValue) {
        value = newValue;
    }

    double getValue() const {
        return value;
    }
};

struct Connection {
    std::shared_ptr<Signal> signal;
};

class Module {
protected:
    static std::map<std::string, int> typeCounts; // Static map to hold counts of each module type
    std::string name; // The unique name for the module instance

    void generateName(const std::string& baseName) {
        int count = ++typeCounts[baseName]; // Increment the count for this module type
        name = baseName + " " + std::to_string(count); // Combine the base name and count to form a unique name
    }

public:
    // Constructor    
    Module(const std::string& baseName) {
        generateName(baseName); // Generate a unique name upon module creation

// TEST MAYBE THIS IS CAUSING LAG WHEN CONSTRUCTING A MODULE????
// you gotta figure out a way to make a profiler!!

    }
    virtual ~Module() {}


    std::vector<Connection> inputs;
    std::vector<Connection> outputs;
    
    std::string getUniqueName() const {return name; }

    void addInput(Connection connection) {
        inputs.push_back(connection);
    }

    void addOutput(Connection connection) {
        outputs.push_back(connection);
    }

    virtual float generate() = 0; // Proccesses Audio
    virtual void renderUI(const std::string windowTitle) = 0; // Rendering ui for module
};

/*
Module:
    List of inputs
    List of outputs

*/

#endif // MODULE_H