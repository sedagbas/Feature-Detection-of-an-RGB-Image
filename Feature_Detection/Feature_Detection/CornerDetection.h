#ifndef CORNERDETECTION_H
#define CORNERDETECTION_H

#include "Detection.h"

class CornerDetection : public Detection
{
public:
	/// Constructor with optional scale, type, and address parameters
	CornerDetection(const double& scale = 1.0, const string& type = "Corner_Detection", const string& address = "d:/sedat/Desktop/");

	/// Get the normalized output matrix
	static Mat getNormalized();

	/// Get the detected corners matrix
	static Mat getDetectCorners();

	/// Get the corners vector
	static vector <Point> getCornersVector();

	/// Draw the detected corners on the image
	void drawCorners();

	/// Create circles around the detected corners
	void creatingCircles();

	/// Show the detected corners from a file
	void showCornersFromFile() const;

	/// Destructor
	~CornerDetection();

private:
	/// Matrix to store the detected corners
	static Mat detectCorners;

	/// Vector to store the corners in the detected image
	static vector <Point> cornersVector;

	/// Normalized matrix for visualization
	static Mat normalized;

	/// Set the detected corners matrix
	static Mat setDetectCorners();

	/// Initialize the corner detection process
	void initialize();
};

#endif