// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// main.cpp
// modified: 12/13/18

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include "matrix.h"
#include "loadmnist.h"

using namespace std;

unsigned int MaxElement(vector<float> input);
vector<vector<float> > LoadMNIST();

unsigned int MaxElement(vector<float> input)
{
  if (input.size() == 0)
    return -1;

  float max = input[0];
  int index = 0;
  for (unsigned int i = 1; i < input.size(); i++)
    if (input[i] > max)
    {
      max = input[i];
      index = i;
    }

  return index;
}

int main()
{
    
    cout << "Training model..." << endl;
    srand(time(NULL));
    vector<vector<float> > training_data = LoadMNIST();

    //create the labels
    vector<vector<float> > labels;
    for (int i = 0; i < 10; i++)
    {
        vector<float> label;
        label.resize(10);
        label[i] = 1.0f;
        labels.push_back(label);
    }

    Matrix MNISTModel;
    MNISTModel.AddFCL(784, 10);
    MNISTModel.AddSoftmax(10);
    const unsigned int INPUT_SIZE = 784;
    const unsigned int NUM_CLASSES = 10;
    const unsigned int OUTPUT_SIZE = 10;
    const unsigned int NUM_EPOCHS = 10;
    const float LEARNING_RATE = 0.1f;
    const unsigned int NUM_EXAMPLES = training_data[0].size() / INPUT_SIZE;

    for (unsigned int epoch = 0; epoch < NUM_EPOCHS; epoch++)
      for (unsigned int i = 0; i < NUM_EXAMPLES; i++)
        for (unsigned int j = 0; j < NUM_CLASSES; j++)
        {
          vector<float> input;
          input.reserve(INPUT_SIZE);
          for (int k = i * INPUT_SIZE; k < i * INPUT_SIZE + INPUT_SIZE; k++)
            input.push_back(training_data[j][k]);

          float loss = MNISTModel.Train(input, labels[j], LEARNING_RATE / pow(10, epoch / 10.0f));

          //train the model
          if (i % 100 == 0)
              ;
            //cout << "Epoch " << epoch + 1 << ", loss: " << loss << endl;
        }

  cout << "Testing trained model..." << endl;

  unsigned int num_tests = 0;
  unsigned int num_correct = 0;
  for (unsigned int i = 0; i < NUM_EXAMPLES; i++)
  {
    for (unsigned int j = 0; j < NUM_CLASSES; j++)
    {
      vector<float> input;
      input.reserve(INPUT_SIZE);
      for (int k = i * INPUT_SIZE; k < i * INPUT_SIZE + INPUT_SIZE; k++) {
        input.push_back(training_data[j][k]);
      }

      num_tests++;
      
      unsigned int computedAnswer = MaxElement(MNISTModel.Evaluate(input));
      
      // show all guesses      
      //cout << " ... " << j << " and I guessed " << computedAnswer << endl;

      if (computedAnswer == j) {
        num_correct++;
      }
      else {
          
          // show incorrect guesses
          //cout << " ... " << j << " and I guessed " << computedAnswer << endl;
      }
    }
  }
  
  cout << "I got " << num_correct << " out of " << num_tests << " correct!" << endl;

  cout << "Accuracy: " << (float)num_correct / num_tests * 100.0f << "%" << endl;

cout << "Press enter to exit..." << endl;
string name;
getline(cin, name);

	return 0;
}
