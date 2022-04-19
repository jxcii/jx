#include <cmath>
#include <random>
enum _type {
	input,
	normal,
	output
};
class Nueron {
public:
	double value, * weights;
	int CountWeights;
	_type type;
	Nueron(int a) : CountWeights(a)
	{
		weights = new double[CountWeights];
		for (int c = 0; c < CountWeights; c++) *(weights + c) = (double)int(rand() % 101) / 100;
	}
	Nueron& updateValue(double* inputs) {
		double sum = 0;
		for (int c = 0; c < CountWeights; c++) sum += (*(weights + 1)) * (*(inputs + 1));
		value = ActivationFunction(sum);
	}
	static double ActivationFunction(double sum) {
		return 1.0 / (1.0 + exp(-sum));
	}
};