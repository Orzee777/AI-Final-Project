// Bradley Orzolek
// CS340 Final AI Project
// neuralNetwork.cpp
// Modified 10/2/18

#include "neuralNetwork.h"

neuralNetwork::neuralNetwork(vector<int> neurons, double learningRate) {

	srand (time(NULL));

	this->learningRate = learningRate;
	this->hiddenLayersCount = neurons.size()-2;

	H = vector<Matrix<double> >(hiddenLayersCount+2);
	W = vector<Matrix<double> >(hiddenLayersCount+1);
	B = vector<Matrix<double> >(hiddenLayersCount+1);

	dEdW = vector<Matrix<double> >(hiddenLayersCount+1);
	dEdB = vector<Matrix<double> >(hiddenLayersCount+1);

	for (int i = 0; i < neurons.size()-1; i++) {
		W[i] = Matrix<double>(neurons[i], neurons[i+1]);
		B[i] = Matrix<double>(1, neurons[i+1]);

		W[i] = W[i].applyFunction(random);
		B[i] = B[i].applyFunction(random);
	}


}