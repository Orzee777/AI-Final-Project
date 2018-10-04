// Bradley Orzolek
// CS340 Final AI Project
// segment.h
// Modified 10/2/18

#ifndef SEGMENT_H
#define SEGMENT_H

#include <vector>


using namespace std;

///
/// Rectangle structure is used for segmenting images to analyze them
///

struct Rectangle {
    int stringPosition;
    int x;
    int y;
    int width;
    int height;
};

void initArray(int* tbd, int length);


#endif /* SEGMENT_H */