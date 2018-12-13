// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// fcl.h
// modified: 12/10/18


#ifndef FCL_H
#define FCL_H

#include "layer.h"
#include <cstdlib>

using namespace std;

class FCL : public Layer
{
public:
  FCL();
  FCL(unsigned int input_size, unsigned int output_size);
  unsigned int InputSize;
  unsigned int OutputSize;
  vector<float> W;
  vector<float> b;
  void Forward();
  void CalcDeltas(vector<float> nextLayerDeltas);
  void UpdateParams(float learning_rate);
};

#endif
