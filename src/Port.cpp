#include "Port.h"

void port::renderPort() {
    ImGui::SameLine(); // Keeps the next widget on the same line

    // Checkbox on the right
    ImGui::Checkbox("Enable", &checkboxValue);
}