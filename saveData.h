// Bradley Orzolek
// CS340 Final AI Project
// saveData.h
// Modified 10/2/18

#ifndef SAVEDATA_H
#define SAVEDATA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

////
//// Function declarations
////

void saveNetworkData ();

void readNetworkData ();

////
//// Function definitions
////

void saveNetworkData () {
    ifstream outputFile;
    outputFile.open("data.txt");
    
    // write network to file
    
    outputFile.close();
    
}

void readNetworkData () {
    ifstream inputFile;
    inputFile.open("data.txt");
    
    if (inputFile.fail()) {
        cerr << "ERROR: Cannot access Network Data File" << endl;
    }
    else {
        // read input file
        
        
    }
    inputFile.close();
}

#endif /* SAVEDATA_H */

