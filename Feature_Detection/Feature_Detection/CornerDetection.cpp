#include "CornerDetection.h"

/// Initialization for detected corners
Mat CornerDetection::detectCorners = setDetectCorners();

/// Set the detected corners matrix
Mat CornerDetection::setDetectCorners()
{
	return CommonProcesses::getRGBData();
}

/// Initialization for corners vector
vector <Point> CornerDetection::cornersVector = vector<Point>();

/// Initialization for normalized matrix
Mat CornerDetection::normalized = Mat();

/// Get the normalized matrix
Mat CornerDetection::getNormalized()
{
	return normalized;
}

/// Constructor with optional scale, type, and address parameters
CornerDetection::CornerDetection(const double& scale, const string& type, const string& address)
	: Detection(scale, type, address)
{
	initialize();
}

/// Get the detected coners matrix
Mat CornerDetection::getDetectCorners()
{
	return detectCorners;
}

/// Get the corners vector
vector <Point> CornerDetection::getCornersVector()
{
	return cornersVector;
}

/// Initialize the corner detected process
void CornerDetection::initialize()
{
	/// Initialize the 'normalized' matrix for corner detection with zeros, matching the size of the RGB data
	CornerDetection::normalized = Mat::zeros(CommonProcesses::getRGBData().size(), CV_32FC1);

	/// Convert the 'detectCorners' matrix to grayscale 
	CommonProcesses::convertToGrayScale(detectCorners);

	/// Apply the Harris corner detection algorithm
	cornerHarris(getDetectCorners(), CornerDetection::normalized, 3, 3, 0.0001);

	/// Normalize the obtained results
	normalize(getNormalized(), normalized, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
}

/// Draw the detected corners on the image
void CornerDetection::drawCorners()
{
	/// Apply noise filtering
	CommonProcesses::filterNoise(detectCorners);

	/// Draw circles based on the detected corner points
	creatingCircles();

	/// Write the detected corner information to a file
	Detection::writingFeatures(cornersVector);

	/// Rescale the corner detection result
	CommonProcesses::rescale(detectCorners);

	/// Visualize the detected corners
	Detection::visualize(getDetectCorners());

	/// Save the corner detection results
	CommonProcesses::writeRGBToFile(detectCorners, Detection::createFilePath(getTypeOfDetection(), ".png"));
}

/// Create circles around the detected corners
void CornerDetection::creatingCircles()
{
	for (int j = 0; j < getNormalized().rows; j++)
	{
		for (int i = 0; i < getNormalized().cols; i++)
		{
			if ((int)getNormalized().at<float>(j, i) > 150)
			{
				circle(getDetectCorners(), Point(i, j), 4, Scalar(0, 0, 255), 1, LINE_AA, 0);
				cornersVector.emplace_back(static_cast<float>(i), static_cast<float>(j));
			}
		}
	}
}

/// Show the detected corners from a text file
void CornerDetection::showCornersFromFile() const
{
	string filename = Detection::getDirectory() + Detection::getTypeOfDetection() + ".txt";

	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "File could not be opened!" << filename << endl;
		return;
	}

	std::vector<cv::Vec2f> coordinates;
	char leftBracket, comma;
	float x, y;
	char rightBracket;
	char corner[8];

	while (file >> corner >> leftBracket >> x >> comma >> y >> rightBracket) {
		if (leftBracket == '(' && comma == ',' && rightBracket == ')') {
			coordinates.emplace_back(x, y);
		}
	}
	file.close();

	if (coordinates.empty()) {
		cerr << "No point has been found." << endl;
		return;
	}

	// Load the original image
	Mat copy_originalImage = CommonProcesses::getRGBData().clone();
	if (copy_originalImage.empty()) {
		cerr << "Couldn't load the original image." << endl;
		return;
	}

	// Draw circles' borders on the original image
	for (const auto& coord : coordinates) {
		circle(copy_originalImage, Point(cvRound(coord[0]), cvRound(coord[1])), 4, Scalar(0, 0, 255), 1);
	}

	// Display the image with points
	Detection::visualize(copy_originalImage);
}

/// Destructor
CornerDetection::~CornerDetection()
{
}