// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// matrix.h
// modified: 11/15/18


#ifndef MATRIX_H
#define MATRIX_H

#include "fcl.h"
#include "sigmoid.h"
#include "softmax.h"
#include "relu.h"

using namespace std;

class Matrix
{
public:
  Matrix();
  ~Matrix();
  vector<float> Evaluate(vector<float> input);
  float Train(vector<float> input, vector<float> output, float learning_rate);
  void AddFCL(unsigned int input_size, unsigned int output_size);
  void AddSigmoid(unsigned int input_size);
  void AddSoftmax(unsigned int input_size);
  void AddReLU(unsigned int input_size);
  vector<Layer*> Layers;
};

#endif
