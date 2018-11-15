// Bradley Orzolek
// CS 340 Final Project
// Handwriting OCR
// loadmnist.cpp
// modified: 11/15/18


#include "loadmnist.h"

vector<vector<float> > LoadMNIST()
{
  //open the MNIST dataset
  ifstream data0;
  data0.open("MNIST_Dataset/data0.txt", ios::binary);
  ifstream data1;
  data1.open("MNIST_Dataset/data1.txt", ios::binary);
  ifstream data2;
  data2.open("MNIST_dataset/data2.txt", ios::binary);
  ifstream data3;
  data3.open("MNIST_Dataset/data3.txt", ios::binary);
  ifstream data4;
  data4.open("MNIST_Dataset/data4.txt", ios::binary);
  ifstream data5;
  data5.open("MNIST_Dataset/data5.txt", ios::binary);
  ifstream data6;
  data6.open("MNIST_Dataset/data6.txt", ios::binary);
  ifstream data7;
  data7.open("MNIST_Dataset/data7.txt", ios::binary);
  ifstream data8;
  data8.open("MNIST_Dataset/data8.txt", ios::binary);
  ifstream data9;
  data9.open("MNIST_Dataset/data9.txt", ios::binary);

  vector<float> input0;
  vector<float> input1;
  vector<float> input2;
  vector<float> input3;
  vector<float> input4;
  vector<float> input5;
  vector<float> input6;
  vector<float> input7;
  vector<float> input8;
  vector<float> input9;

  //create the input vectors
  while (data0.good())
  {
    int data_byte = data0.get();
    input0.push_back(data_byte / 255.0f);
  }
  while (data1.good())
  {
    int data_byte = data1.get();
    input1.push_back(data_byte / 255.0f);
  }
  while (data2.good())
  {
    int data_byte = data2.get();
    input2.push_back(data_byte / 255.0f);
  }
  while (data3.good())
  {
    int data_byte = data3.get();
    input3.push_back(data_byte / 255.0f);
  }
  while (data4.good())
  {
    int data_byte = data4.get();
    input4.push_back(data_byte / 255.0f);
  }
  while (data5.good())
  {
    int data_byte = data5.get();
    input5.push_back(data_byte / 255.0f);
  }
  while (data6.good())
  {
    int data_byte = data6.get();
    input6.push_back(data_byte / 255.0f);
  }
  while (data7.good())
  {
    int data_byte = data7.get();
    input7.push_back(data_byte / 255.0f);
  }
  while (data8.good())
  {
    int data_byte = data8.get();
    input8.push_back(data_byte / 255.0f);
  }
  while (data9.good())
  {
    int data_byte = data9.get();
    input9.push_back(data_byte / 255.0f);
  }

  data0.close();
  data1.close();
  data2.close();
  data3.close();
  data4.close();
  data5.close();
  data6.close();
  data7.close();
  data8.close();
  data9.close();

  vector<vector<float> > training_data;
  training_data.push_back(input0);
  training_data.push_back(input1);
  training_data.push_back(input2);
  training_data.push_back(input3);
  training_data.push_back(input4);
  training_data.push_back(input5);
  training_data.push_back(input6);
  training_data.push_back(input7);
  training_data.push_back(input8);
  training_data.push_back(input9);

  return training_data;
}
