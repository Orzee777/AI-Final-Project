// Bradley Orzolek
// CS340 Final AI Project
// neuralNetwork.h
// Modified 10/2/18

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <fstream>
#include <cmath>

#include "../Matrix/Matrix.h"

using namespace std;

class NeuralNetwork {
public:
    
    neuralNetwork(vector<int> neurons, double learningRate);
    neuralNetwork(const char *filePath);

    Matrix<double> computeOutput(vector<double> input);
    void learn(vector<double> expectedOutput);

    void saveNetworkParameters(const char *filePath);
    void loadNetworkParameters(const char *filePath);

    vector<Matrix<double> > W;
    vector<Matrix<double> > B;

private:
    
    vector<Matrix<double> > H;
    vector<Matrix<double> > dEdW;
    vector<Matrix<double> > dEdB;

    Matrix<double> Y;

    int hiddenLayersCount;
    double learningRate;

    static double random(double x);
    static double sigmoid(double x);
    static double sigmoidPrime(double x);

    void printToFile(Matrix<double> &m, ofstream &file);
    
};

#endif /* NEURALNETWORK_H */