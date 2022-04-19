#include "Neuron.h"
class layer {
public:
	layer(){}
	int count;
	std::vector<Neuron> nuerons;
	_type type;
	layer(int count, _type type = normal) : count(count), type(type)
	{
		for (int c = 0; c < count; c++) nuerons.push_back(Neuron(count, type));
	}

};
