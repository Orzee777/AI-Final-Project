// Bradley Orzolek
// CS340 Final AI Project
// segment.h
// Modified 10/4/18

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

/* functions to create and draw segments */
int* horizontalSegments(Mat& src);
int* verticalSegments(Mat& src);
Mat drawHorizontalSegments(int* seg, int rows, int cols);
Mat drawVerticalSegments(int* seg, int rows, int cols);

/* functions to manipulate segments */
vector<pair<int, int> > createSegmentPairs(int* seg, int segSize);
vector<Rectangle> getRectangles(vector<pair<int, int> > vPairs, vector<pair<int, int> > hPairs);
vector<Rectangle> shrinkRectangles(Mat& im, vector<Rectangle> r);
vector<Rectangle> takeRectangles(vector<Rectangle> r, int number);
void drawRectangles(Mat& im, vector<Rectangle> r);

void classify(Mat &image, Mat& trainingData, Mat& trainingClasses, vector<Rectangle> r);
vector<Rectangle> segmentation(Mat& img, int numSquares);


#endif /* SEGMENT_H */