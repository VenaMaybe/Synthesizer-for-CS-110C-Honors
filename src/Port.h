#ifndef PORT_H
#define PORT_H

#include "imgui.h" // For renderUI

class port {

    bool checkboxValue = false;
    
    // Renders a port on the next line.
    void renderPort();
};

#endif // PORT_H