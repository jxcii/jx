#include <iostream>
#include <cmath>
#include <random>
#include <vector>
enum _type {
	input,
	normal,
	output
};
class Neuron {
public:
	Neuron(){}
	double value;
	std::vector<double> weights;
	int CountWeights;
	_type type;
	Neuron(int a, _type type = normal) : CountWeights(a), type(type)
	{
		for (int c = 0; c < CountWeights; c++) weights.push_back((double)int(rand() % 101) / 100);
	}
	Neuron& updateValue(std::vector<double> inputs) {
		double sum = 0;
		for (int c = 0; c < CountWeights; c++) sum += weights[c] * inputs[c];
		value = ActivationFunction(sum);
		return *this;
	}
	static double ActivationFunction(double sum) {
		return 1.0 / (1.0 + exp(-sum));
	}
	Neuron& settype(_type type) {
		this->type = type;;
		return *this;
	}

};