// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// matrix.cpp
// modified: 12/10/18

#include "matrix.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
  for (unsigned int i = 0; i < Layers.size(); i++)
    delete Layers[i];
}

void Matrix::AddFCL(unsigned int input_size, unsigned int output_size)
{
  FCL* fcl = new FCL(input_size, output_size);
  Layer* layer = fcl;
  Layers.push_back(layer);
}

void Matrix::AddSigmoid(unsigned int input_size)
{
  Sigmoid* sigmoid = new Sigmoid(input_size);
  Layer* layer = sigmoid;
  Layers.push_back(layer);
}

void Matrix::AddSoftmax(unsigned int input_size)
{
  Softmax* softmax = new Softmax(input_size);
  Layer* layer = softmax;
  Layers.push_back(layer);
}

void Matrix::AddReLU(unsigned int input_size)
{
  ReLU* relu = new ReLU(input_size);
  Layer* layer = relu;
  Layers.push_back(layer);
}

vector<float> Matrix::Evaluate(vector<float> input)
{
  if (Layers.size() == 0)
    cout << "Error! Empty model!" << endl;
  else
  {
    Layers[0]->Input = input;
    for (unsigned int i = 0; i < Layers.size(); i++)
    {
      Layers[i]->Forward();
      if (i < Layers.size () - 1)
        Layers[i + 1]->Input = Layers[i]->Output;
    }
    return Layers[Layers.size() - 1]->Output;
  }
  vector<float> v;
  v.push_back(-1);
  return v;
}

float Matrix::Train(vector<float> input, vector<float> output, float learning_rate)
{
  //Evaluate model
  vector<float> model_output = Evaluate(input);

  //check output size
  if (Layers[Layers.size() - 1]->Output.size() != output.size())
  {
    cout << "Error size mismatch: expected output vector of size " << Layers[Layers.size() - 1]->Output.size()
              << ", got size " << output.size() << endl;
    return -1;
  }
  //optimization
  unsigned int _oSize = output.size();

  //calculate last layer deltas
  vector<float> lastLayerDeltas;
  lastLayerDeltas.resize(model_output.size());
  float cost = 0.0f;
  for (unsigned int i = 0; i < lastLayerDeltas.size(); i++)
  {
    lastLayerDeltas[i] = model_output[i] - output[i % _oSize];
    cost += lastLayerDeltas[i] * lastLayerDeltas[i] / 2;
  }

  //calculate layer deltas
  Layers[Layers.size() - 1]->CalcDeltas(lastLayerDeltas);
  for (int i = Layers.size() - 2; i >= 0; i--)
    Layers[i]->CalcDeltas(Layers[i + 1]->LayerDeltas);

  //update model parameters
  for (unsigned int i = 0; i < Layers.size(); i++)
    Layers[i]->UpdateParams(learning_rate);
  return cost;
}
