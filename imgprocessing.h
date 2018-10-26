// Bradley Orzolek
// CS340 Final AI Project
// imgprocessing.h
// Modified 10/24/18


// this code is copied from the example file given

/*
* These functions all of the image preprocessing. It will convert
* the source image to grayscale, copy it, apply a threshold to the copy,
* dilation, and apply erotion to the image. Returns the new image.
*/

#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

Mat preprocessImage(Mat& sourceImage);

#endif