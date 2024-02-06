#ifndef COMMONPROCESSES_H
#define COMMONPROCESSES_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

class CommonProcesses
{
public:

	/// Default Constructor
	CommonProcesses(const double& scale = 1.0);

	/// Get function for RGB Data
	static Mat getRGBData();

	/// Get function for scale factor
	double getScaleFactor() const;

	/// Set function for scale factor
	void setScaleFactor(const double&);

	/// Read RGB data from a file
	static Mat readRGBFromFile(const string&);

	/// Write RGB data to a file
	void writeRGBToFile(const Mat&, const string&);

	/// Display RGB data
	void showImage() const;

	/// Convert an image to gray scale
	void convertToGrayScale(Mat&);

	/// Filter noise in an image 
	void filterNoise(Mat& detection);

	/// Resize an image
	void rescale(Mat&);

	/// Destructor
	~CommonProcesses();

private:
	/// Static member to hold RGB data
	static const Mat rgbData;

	/// Variable for scale factor
	double scaleFactor;
};

#endif