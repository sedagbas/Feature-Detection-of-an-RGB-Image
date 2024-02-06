#ifndef LINEDETECTION_H
#define LINEDETECTION_H

#include "Detection.h"
#include <cmath>

class LineDetection : public Detection
{
public:
	/// Constructor with optional scale, type, and address parameters
	LineDetection(const double& scale = 1.0, const string& type = "Line_Detection", const string& address = "d:/sedat/Desktop/");

	/// Get detectLines matrix
	static Mat getDetectLines();

	/// Get lines vector
	static vector<Vec4f> getLinesVector();

	/// Perform line detection on the image
	static void detectLinesFromImage();

	/// Draw the detected lines on the image
	void drawLines();

	/// Show the detected lines from a file
	void showLinesFromFile();

	/// Destructor
	~LineDetection();

private:
	/// Matrix to store detected lines
	static Mat detectLines;

	/// Vector to store the lines in the detected image
	static vector<Vec4f> linesVector;
};

#endif