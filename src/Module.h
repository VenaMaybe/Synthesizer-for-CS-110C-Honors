#ifndef MODULE_H
#define MODULE_H

// Holds a value between -5 and 5
#include <vector>
#include <memory>

struct Signal {
    double value;
};

struct Connection {
    std::shared_ptr<Signal> signal;
};

class Module {
public:
    std::vector<Connection> inputs;
    std::vector<Connection> outputs;

    void addInput(Connection connection) {
        inputs.push_back(connection);
    }

    void addOutput(Connection connection) {
        outputs.push_back(connection);
    }

    virtual float generate() = 0; // Proccesses Audio
    virtual void renderUI() = 0; // Rendering ui for module
};


/*
Module:
    List of inputs
    List of outputs

*/

#endif // MODULE_H