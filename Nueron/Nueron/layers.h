#include "Neuron.h"
class layer {
public:
	layer(){}
	int count;
	Neuron** nuerons;
	_type type;
	layer(int count, _type type = normal) : count(count), type(type)
	{
		nuerons = new Neuron*[count];
		
	}
	layer& setBeforeNueron(int size) {
		for (int c = 0; c < count; c++) *(nuerons + c) = new Neuron(size);
		return *this;
	}

};
