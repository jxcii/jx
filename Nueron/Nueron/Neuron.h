#include <cmath>
#include <random>
enum _type {
	input,
	normal,
	output
};
class Neuron {
public:
	Neuron(){}
	double value, * weights;
	int CountWeights;
	_type type;
	Neuron(int a, _type type = normal) : CountWeights(a), type(type)
	{
		weights = new double[CountWeights];
		for (int c = 0; c < CountWeights; c++) *(weights + c) = (double)int(rand() % 101) / 100;
	}
	Neuron& updateValue(double* inputs) {
		double sum = 0;
		for (int c = 0; c < CountWeights; c++) sum += (*(weights + 1)) * (*(inputs + 1));
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