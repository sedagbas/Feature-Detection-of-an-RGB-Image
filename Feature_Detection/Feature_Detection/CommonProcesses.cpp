#pragma once
#include "CommonProcesses.h"
#include "CornerDetection.h"

/// Initialize the static member variable with RGB data from the specified file
const Mat CommonProcesses::rgbData = readRGBFromFile("d:/sedat/Desktop/Image.png");

/// Read RGB data from a file and return it as a Mat
Mat CommonProcesses::readRGBFromFile(const string& path)
{
	return imread(path);
}

/// Constructor with an optional scale parameter
CommonProcesses::CommonProcesses(const double& scale)
	: scaleFactor(scale)
{
	/// Check if the RGB data is empty after reading from the file
	if (rgbData.empty())
		throw runtime_error("Failed to read image from file!");

	/// Check if the scale factor is greater than 0.0
	if (getScaleFactor() <= 0.0)
		throw invalid_argument("ScaleFactor must be greater than 0.0 !");
}

/// Write the given image to the specified output path
void CommonProcesses::writeRGBToFile(const Mat& image, const string& outputPath)
{
	/// Check the imwrite operation is successfull
	if (imwrite(outputPath, image))
	{
		/// Print a success message
		cout << "The writing RGB data to file process has been successfully completed. Address: " + outputPath << endl;
	}
	else
		throw runtime_error("Failed to write image to file: " + outputPath);
}

/// Get RGB data (static) 
Mat CommonProcesses::getRGBData()
{
	return rgbData;
}

/// Get the scale factor
double CommonProcesses::getScaleFactor() const
{
	return scaleFactor;
}

/// Set scale factor to the specified value
void CommonProcesses::setScaleFactor(const double& scale)
{
	scaleFactor = scale;
}

/// Display the original image using OpenCV's imshow function
void CommonProcesses::showImage() const
{
	/// Check if the RGB data is empty
	if (!getRGBData().empty())
	{
		imshow("Original Image", CommonProcesses::getRGBData());
	}
	else
		throw runtime_error("Cannot display an empty image!");
}

/// Convert the given image to grayscale using OpenCV's cvtColor function
void CommonProcesses::convertToGrayScale(Mat& image)
{
	/// Check if the image is empty
	if (!image.empty())
		cvtColor(image, image, COLOR_BGR2GRAY);
	else
		throw runtime_error("Cannot convert an empty image to grayscale!");
}

/// Apply Gaussian blur to the given image for noise reduction
void CommonProcesses::filterNoise(Mat& image)
{
	/// Check if the image is empty
	if (!image.empty())
		GaussianBlur(image, image, Size(1, 1), 0);
	else
		throw runtime_error("Cannot filter the noise in an empty image!");
}

/// Resize the given image using OpenCV's resize function
void CommonProcesses::rescale(Mat& image)
{
	/// Check if the image is empty
	if (!image.empty()) {
		resize(image, image, Size(), getScaleFactor(), getScaleFactor());
	}
	else
		throw runtime_error("RGB Data not available!");
}

/// Destructor
CommonProcesses::~CommonProcesses()
{
}