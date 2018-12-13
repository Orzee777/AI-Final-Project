// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// softmax.h
// modified: 11/15/18

#ifndef SOFTMAX_H
#define SOFTMAX_H

#include "layer.h"

using namespace std;

class Softmax : public Layer
{
public:
  Softmax();
  Softmax(unsigned int input_size);
  unsigned int InputSize;
  unsigned int OutputSize;
  void Forward();
  void CalcDeltas(vector<float> nextLayerDeltas);
  void UpdateParams(float learning_rate);
};

#endif
