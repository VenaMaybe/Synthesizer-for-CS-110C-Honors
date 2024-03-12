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

    void addOutput(Connection conneciton) {
        outputs.push_back(conneciton);
    }

    virtual void generate() = 0;
};


/*
Module:
    List of inputs
    List of outputs

*/