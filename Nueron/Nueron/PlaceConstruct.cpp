#include <iostream>
#include "NeuralWork.h"
using namespace std;
int main() {
	NueralWork tr({ 2, 2, 1 });
	vector<double> results = tr.FeedForward({ 1, 0 });

}