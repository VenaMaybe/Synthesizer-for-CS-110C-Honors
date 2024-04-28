#ifndef FILTER_H
#define FILTER_H

#include <memory>

#include <iostream>

#include "Gamma/Filter.h"
#include "module.h"

class FilterHPLP : public Module {
public:
	gam::FilterType filterType;

	FilterHPLP();

	// Only high or low pass!
	bool validType(gam::FilterType ft);
	// Swaps between high and low pass
	bool swapType(gam::FilterType ft);
	// Sets the filter type!
	bool setType(gam::FilterType ft);
	// In callback, send signal to input
	bool setInput1(float input);


	// Called every callback to update the filter type!
	void updateFilter(float& audio, float cutoff, float resonance);

	// temp just ignore for now
	float generate();
	// temp just ignore for now
	void renderUI(const std::string windowTitle);

private:
	Connection input1;
	Connection output1;
	gam::Biquad<> filter;
	
	// input selection stuff
	int selectedInput = 0;
	std::vector<const char*> outputNames;
	std::vector<Connection> outputConnections;

	// input variables
	float targetCutoff = 1000.f;
	float targetResonance = 0.707f;

};

#endif // FILTER_H