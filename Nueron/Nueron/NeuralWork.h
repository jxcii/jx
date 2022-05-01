#include "layers.h"
class NueralWork {
	vector<layer> layers;
public:
	NueralWork(vector<int> topology)
	{
		layers.push_back(layer(topology[0], input));
		for (int c = 0; c < topology[0]; c++) layers[0].neurons[c] = new Neuron(1, input);
		for (int c = 1; c < topology.size() - 1; c++) {
			layers.push_back(layer(topology[c]));
			for (int j = 0; j < layers[c].neurons.size(); j++) 
				layers[c].neurons[j] = new Neuron(layers[c - 1].neurons.size());
		}
		layers.push_back(layer(topology[topology.size()-1], output));
		for (int c = 0; c < topology[topology.size() - 1]; c++) layers[topology.size() - 1].neurons[c] = new Neuron(topology[topology.size() - 2], output);

	}
	vector<double> FeedForward(vector<double> localinputs) {
		for (int c = 0; c < layers[0].neurons.size(); c++) layers[0].neurons[c]->FeedForward({ localinputs[c] });

		for (int c = 1; c < layers.size(); c++) {
			localinputs = layers[c - 1].FeedForward();
		}
	}
};