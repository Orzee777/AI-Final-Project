// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// layer.h
// modified: 11/15/18


#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Layer
{
public:
  Layer();
  virtual ~Layer();
  vector<float> Input;
  vector<float> Output;
  vector<float> LayerDeltas;
  vector<float> NextLayerDeltas;
  virtual void Forward() = 0;
  virtual void CalcDeltas(vector<float> nextLayerDeltas) = 0;
  virtual void UpdateParams(float learning_rate) = 0;
};

#endif
