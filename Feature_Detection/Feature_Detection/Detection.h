#ifndef DETECTION_H
#define DETECTION_H

#include "CommonProcesses.h"

/// Overloaded stream insertion operator for Point class
ostream& operator<<(ostream&, const Point&);

/// Overloaded stream insertion operator for vector of Vec4f
ostream& operator<<(ostream&, const vector<Vec4f>&);

class Detection : public CommonProcesses
{
public:
	/// Default Constructor with optional scale, type, and address parameters
	Detection(const double& scale = 1.0, const string& type = "", const string& address = "d:/sedat/Desktop/");

	/// Get function for type of detection
	string getTypeOfDetection() const;

	/// Get function for directory
	string getDirectory() const;

	/// Create a file path with the given file name and extension
	string createFilePath(const string&, const string&) const;

	/// Visualize the given image
	void visualize(const Mat&) const;

	/// Write features from the vector of Vec4f to a file
	void writingFeatures(const vector<Vec4f>& image) const;

	/// Write features from the vector of Point to a file
	void writingFeatures(const vector<Point>&) const;

	/// Destructor
	~Detection();

private:
	/// Type of detection
	const string typeOfDetection;
	/// Directory path for saving files
	const string directory;
};

#endif