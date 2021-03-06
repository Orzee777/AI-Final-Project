// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// sigmoid.cpp
// modified: 11/15/18


#include "sigmoid.h"

Sigmoid::Sigmoid()
{
}

Sigmoid::Sigmoid(unsigned int input_size)
{
  InputSize = input_size;
}

void Sigmoid::Forward()
{
  //make sure the batch fits the input size
  if (Input.size() % InputSize != 0)
    cout << "Error! Input size mismatch: given " << Input.size() << " instead of multiple of "
              << InputSize << endl;
  else
  {
    Output.resize(Input.size());
    for (unsigned int i = 0; i < Input.size(); i++)
      Output[i] = 1.0f / (1 + exp(-Input[i]));
  }
}

void Sigmoid::CalcDeltas(vector<float> nextLayerDeltas)
{
  NextLayerDeltas = nextLayerDeltas;
  LayerDeltas.clear();
  LayerDeltas.resize(nextLayerDeltas.size());
  for (unsigned int i = 0; i < nextLayerDeltas.size(); i++)
    LayerDeltas[i] = nextLayerDeltas[i] * Output[i] * (1.0f - Output[i]);
}

void Sigmoid::UpdateParams(float learning_rate)
{
}
