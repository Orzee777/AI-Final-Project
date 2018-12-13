// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// relu.h
// modified: 11/15/18

#ifndef RELU_H
#define RELU_H

#include "layer.h"

using namespace std;

class ReLU : public Layer
{
public:
  ReLU();
  ReLU(unsigned int input_size);
  unsigned int InputSize;
  unsigned int OutputSize;
  void Forward();
  void CalcDeltas(vector<float> nextLayerDeltas);
  void UpdateParams(float learning_rate);
};

#endif
