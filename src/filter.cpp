#include "imgui.h" // For renderUI

#include "filter.h"

FilterHPLP::FilterHPLP()
: Module("FiltHPLP"), input1("Filt Input 1 "), output1("Filt Output 1 ") {
	input1.connectionName = baseName + " " + std::to_string(typeCounts.at(baseName)) + " Input 1"; // sets to current amt of current module type
	output1.connectionName = baseName + " " + std::to_string(typeCounts.at(baseName)) + " Output 1"; // kinda scuffed add to module later

    addInput(input1);
	addOutput(output1);
	
	selectedInput = -1;
	std::cout << modules->size() << "\n\n\n\n";

	//input1.signal = std::make_shared<Signal>();
    //output1.signal = std::make_shared<Signal>();
    //inputs.push_back(input1);
    //outputs.push_back(output1);
}

// Only high or low pass!
bool FilterHPLP::validType(gam::FilterType ft) {
	return true;
}
// Swaps between high and low pass
bool FilterHPLP::swapType(gam::FilterType ft){
	return true;
}
// Sets the filter type!
bool FilterHPLP::setType(gam::FilterType ft) {
	return true;
}

bool FilterHPLP::setInput1(float input) {
	input1.signal->setValue(input);
	return true;
}

float FilterHPLP::generate() {
	float signalValue;
	signalValue = input1.signal->getValue();
	input1.signal->finalDest = false;

	//std::cout << "ThingPre " << signalValue;

	updateFilter(signalValue, targetCutoff, targetResonance);

	//std::cout << " Thing " << signalValue << std::endl;

	output1.signal->setValue(signalValue);
	output1.signal->finalDest = true;
	return signalValue;
}

// Function to pad the string to a specific length 'n'
void setStringLenTo(int n, std::string& s) {
	if(s.length() > n ) { return; }
	int addedSpaces = n - s.length();
	s.append(addedSpaces, ' ');
}

void FilterHPLP::renderUI(const std::string windowTitle) {
	ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize);

	ImGui::Text("Meowdy my friends");
	
	std::string outputString;

	outputNames.clear();
	outputConnections.clear();
	
	if (modules == nullptr) {
		std::cout << "\nError: modules pointer is null\n";
	} else {
		
		outputString = std::to_string(modules->size()) + '\n';

		for (auto& module : *modules) {
			// Make sure module exists (janky)
			// Refactor arcitecture later.

			if (module == nullptr) {
				std::cout << "\n\nError: Module pointer is null\n";
				continue;
			}

			outputString += module->getUniqueName();
			outputString += "\t\t";
			for (const Connection& connection : module->outputs) {
			//if (connection == nullptr) { break ;}
				outputString += connection.connectionName;
				outputString += "\t";
			
				outputNames.push_back(connection.connectionName.c_str());
				outputConnections.push_back(connection);
			}


			for (const auto& connection : module->inputs) {
				outputString += connection.connectionName;
			}
			outputString += "\n";
			

		}

		if (ImGui::Combo("Input from", &selectedInput, outputNames.data(), outputNames.size())) {
			std::cout << "Selcted Input: " << outputNames[selectedInput] << std::endl;
		
			input1.signal = outputConnections[selectedInput].signal;
			// outputConnections[selectedInput].signal->finalDest = !outputConnections[selectedInput].signal->finalDest;
		}

		const char* filterTypes[] {"Low Pass", "High Pass"};
		if (ImGui::Combo("Filter Type", &selectedType, filterTypes, 2)) {
			switch (selectedType) {
			case 0:
				filter.type(gam::LOW_PASS);
				break;
			case 1:
				filter.type(gam::HIGH_PASS);
				break;
			}
		}

		if (ImGui::SliderFloat("Cutoff", &targetCutoff, 20.0f, 20000.0f, "%0.1f Hz")) {
			filter.freq(targetCutoff);
		}

		if (ImGui::SliderFloat("Resonance", &targetResonance, 0.001f, 5.000f, "%0.3f Hz")) {
			filter.res(targetResonance);
		}

	}
	
	ImGui::TextUnformatted(outputString.c_str());
	

	ImGui::End();
}

// Called every callback to update the filter type!
void FilterHPLP::updateFilter(float& audio, float cutoff, float resonance){
	filter.freq(cutoff);
	if (resonance == 0) {
		resonance = 0.001f;
	}
	filter.res(resonance);
	audio = filter(audio);
}


