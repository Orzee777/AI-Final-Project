// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// chai.h
// modified: 11/15/18


#ifndef CHAI_H
#define CHAI_H

#include <fcl.h>
#include <sigmoid.h>
#include <softmax.h>
#include <relu.h>

using namespace std;

class ChaiModel
{
public:
  ChaiModel();
  ~ChaiModel();
  vector<float> Evaluate(vector<float> input);
  float Train(vector<float> input, vector<float> output, float learning_rate);
  void AddFCL(unsigned int input_size, unsigned int output_size);
  void AddSigmoid(unsigned int input_size);
  void AddSoftmax(unsigned int input_size);
  void AddReLU(unsigned int input_size);
  vector<Layer*> Layers;
};

#endif
