// Bradley Orzolek
// CS340 Final AI Project
// NeuralNetwork.cpp
// Modified 10/4/18

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(vector<int> neurons, double learningRate) {

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

NeuralNetwork::NeuralNetwork(const char *filePath) {
	loadNetworkParameters(filePath);
}

Matrix<double> NeuralNetwork::computeOutput(vector<double> input) {

	// row matrix
	H[0] = Matrix<double>({input});

	for (int i = 0; i < hiddenLayersCount + 2; i++) {
		H[i] = H[i-1].dot(W[i-1]).add(B[i-1]).applyFunction(sigmoid);
	}

	return H[hiddenLayersCount+1];
}

void NeuralNetwork::learn(vector<double> expectedOutput) {

	// row matrix
	Y = Matrix<double>({expectedOutput});

	// compute gradients
	dEdB[hiddenLayersCount] = H[hiddenLayersCount+1].subtract(Y).multiply(H[hiddenLayersCount].dot(W[hiddenLayersCount]).applyFunction(sigmoidPrime));

	for (int i = hiddenLayersCount - 1; i >= 0; i--) {
        dEdB[i] = dEdB[i+1].dot(W[i+1].transpose()).multiply(H[i].dot(W[i]).add(B[i]).applyFunction(sigmoidPrime));
    }

    for (int i = 0; i < hiddenLayersCount + 1; i++) {
        dEdW[i] = H[i].transpose().dot(dEdB[i]);
    }

    // update weights
    for (int i=0 ; i<hiddenLayersCount+1 ; i++) {

        W[i] = W[i].subtract(dEdW[i].multiply(learningRate));
        B[i] = B[i].subtract(dEdB[i].multiply(learningRate));

    }	
}

void NeuralNetwork::printToFile(Matrix<double> &m, ofstream &file) {

	int height = m.getHeight();
	int width = m.getWidth();

	file << height << endl;
	file << width << endl;

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {

			file << m.get(i, j) << (j != (width - 1) ? " ":"");

		}
		file << endl;
	}
}

void NeuralNetwork::saveNetworkParameters(const char *filePath) {
	ofstream out(filePath);

	out << hiddenLayersCount << endl;
	out << learningRate << endl;

	for (int i = 0; i < W.size(); i++) {
		printToFile(W[i], out);
	}

	for (int i = 0; i < B.size(); i++) {
		printToFile(B[i], out);
	}

	out.close();
}

void NeuralNetwork::loadNetworkParameters(const char *filePath) {
	ifstream in(filePath);
	vector<Matrix<double> > parameters;

	double value;
	int h, w;

	if (in) {

		in >> hiddenLayersCount;
		in >> learningRate;

		H = vector<Matrix<double> >(hiddenLayersCount+2);
		W = vector<Matrix<double> >(hiddenLayersCount+1);
		B = vector<Matrix<double> >(hiddenLayersCount+1);
		
		dEdW = vector<Matrix<double> >(hiddenLayersCount+1);
		dEdB = vector<Matrix<double> >(hiddenLayersCount+1);

		for (int i = 0; i < 2*hiddenLayersCount + 2; i++) {
			in >> h;
			in >> w;
			Matrix<double> m(h, w);
			
			for (int hh=0; hh < h; hh++) {

				for (int ww = 0; ww < w; ww++) {

					in >> value;
					m.put(hh, ww, value);
				}
			}
			parameters.push_back(m);
		}
	}
	in.close();


	// assign values

	for (int i = 0; i < hiddenLayersCount + 1; i++) {

		W[i] = parameters[i];
	}

	for (int i = hiddenLayersCount + 1; i < parameters.size(); i++) {

		B[i - hiddenLayersCount - 1] = parameters[i];
	}
}

double NeuralNetwork::random(double x) {
	return (double)(rand() % 10000 + 1)/10000 - 0.5;
}

double NeuralNetwork::sigmoid(double x) {
	return 1 / (1 + exp(-x));
}

double NeuralNetwork::sigmoidPrime(double x) {
	return exp(-x) / (pow(1 + exp(-x), 2));
}