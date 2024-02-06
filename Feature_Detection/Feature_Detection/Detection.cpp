#include "Detection.h"
#include <iomanip>
#include <fstream>

/// Overloaded ostream operator for 'Point' type
ostream& operator<<(ostream& output, const Point& point) {

	output << "(" << point.x << ", " << point.y << ")";

	return output;
}

/// Overloaded ostream operator for vector of Vec4f
ostream& operator<<(ostream& output, const vector<Vec4f>& v)
{
	for (const Vec4f& line : v) {
		Point p1(line[0], line[1]);
		Point p2(line[2], line[3]);

		output << "Line: " << p1 << p2 << endl;
	}

	return output;
}

/// Empty Constructor
Detection::Detection(const double& scale, const string& type, const string& address)
	: CommonProcesses(scale),
	typeOfDetection(type),
	directory(address)
{
	/// Empty body
}

/// Get type of detection
string Detection::getTypeOfDetection() const
{
	return typeOfDetection;
}

/// Get directory
string Detection::getDirectory() const
{
	return directory;
}

/// Create file path
string Detection::createFilePath(const string& fileName, const string& extension) const
{
	return getDirectory() + fileName + extension;
}

/// Visualize the detection
void Detection::visualize(const Mat& image) const
{
	/// Check if the image is empty 
	if (!image.empty())
	{
		CommonProcesses::showImage();

		imshow(getTypeOfDetection(), image);
		waitKey(0);
	}
	else
		throw runtime_error("The detection matrix is empty.");
}

/// Writing features to file for lines
void Detection::writingFeatures(const vector<Vec4f>& data) const
{
	string filePath = createFilePath(getTypeOfDetection(), ".txt");

	// Open the file for writing
	ofstream outputFile(filePath);

	/// Check if the file is open
	if (!outputFile.is_open()) {
		cerr << "Error opening file: " << filePath << endl;
		return;
	}

	if (outputFile)
		outputFile << data << endl;

	else
		cerr << "Error writing features to file !" << endl;

	// Close the file
	outputFile.close();

	cout << "Features written to file: " << filePath << endl;
}

/// Writing features to file for corners
void Detection::writingFeatures(const vector <Point>& data) const
{
	string filePath = createFilePath(getTypeOfDetection(), ".txt");

	ofstream outputFile(filePath);

	/// Check if the file is open
	if (!outputFile.is_open()) {
		throw runtime_error("Error: Unable to open the output file.");
	}

	else
	{
		for_each(data.begin(), data.end(), [&outputFile](const Point& p)
			{
				outputFile << "Corner: " << p << endl;
			});

		cout << "Features written to file: " << filePath << endl;
	}
}

/// Destructor
Detection::~Detection()
{
}