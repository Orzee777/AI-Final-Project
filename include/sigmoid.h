// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// sigmoid.h
// modified: 11/15/18

#ifndef SIGMOID_H
#define SIGMOID_H

#include <layer.h>

using namespace std;

class Sigmoid : public Layer
{
public:
  Sigmoid();
  Sigmoid(unsigned int input_size);
  unsigned int InputSize;
  unsigned int OutputSize;
  void Forward();
  void CalcDeltas(vector<float> nextLayerDeltas);
  void UpdateParams(float learning_rate);
};

#endif
