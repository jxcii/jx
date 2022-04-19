#include "layers.h"
#include <vector>
class NeuralWork {
public:
	layer** layers;
	std::vector<int> system;
	NeuralWork(std::initializer_list<int> system) {
		for (auto t : system) this->system.push_back(t);
		layers = new layer*[system.size()];
		for (int c = 0; c < system.size(); c++) {
			if (c==0) *(layers + c) = new layer(this->system[c], input);
			else if (c==system.size()-1) *(layers + c) = new layer(this->system[c], output);
			else *(layers + c) = new layer(this->system[c]);
		}
	}
};
