#include "LineDetection.h"

/// Initialization for lines vector
vector<Vec4f> LineDetection::linesVector = vector<Vec4f>();

/// Initialization for detectLines
Mat LineDetection::detectLines = Mat();

/// Constructor for LineDetection class
LineDetection::LineDetection(const double& scale, const string& type, const string& address)
    : Detection(scale, type, address)
{
    /// Call the setLines function during construction
    detectLinesFromImage();
}

/// Get detectLines matrix
Mat LineDetection::getDetectLines()
{
    return detectLines;
}

/// Get linesVector vector
vector<Vec4f> LineDetection::getLinesVector()
{
    return linesVector;
}

/// Perform Canny detection and Hough Line Transform to detect lines in the image
void LineDetection::detectLinesFromImage()
{
    /// Apply Canny edge detection on the RGB image data using parameters: (input, output, threshold, threshold2)
    Canny(CommonProcesses::getRGBData(), detectLines, 221, 296);

    /// Apply Hough Line Transform on the edge - detected image to detect to detect lines
    /// Parameters: (input, output vector of lines, resolution of accumulator in pixels,
    /// angle resolution of accumulator in radians, threshold, minimum line length, maximum line gap
    HoughLinesP(detectLines, linesVector, 1, CV_PI / 180.0, 50, 50, 10);
}

/// Perform post-processing on the detected lines and visualize the results
void LineDetection::drawLines()
{
    /// Perform noise filtering on the detected image
    CommonProcesses::filterNoise(detectLines);

    /// Rescale the image based on the scale factor
    CommonProcesses::rescale(detectLines);

    /// Visualize the detected image with the detected lines
    Detection::visualize(getDetectLines());

    /// Write the processed image (after noise filtering and rescaling) to a file
    CommonProcesses::writeRGBToFile(detectLines, Detection::createFilePath(getTypeOfDetection(), ".png"));

    /// Write detected lines a file
    Detection::writingFeatures(getLinesVector());
}

/// Display lines from a file on the original image
void LineDetection::showLinesFromFile()
{
    /// Construct the filename based on the type of detection and directory
    string filename = getDirectory() + getTypeOfDetection() + ".txt";

    /// Open the file for reading
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "File could not be opened! " << filename << endl;
        return;
    }

    /// Vector to store line coordinates
    vector<Point> coordinates;

    char leftBracket1, comma1, rightBracket1, leftBracket2, comma2, rightBracket2;

    /// Variables to store coordinates
    int x1, y1, x2, y2;

    char type[8];

    /// Read line from the file
    while (file >> type >> leftBracket1 >> x1 >> comma1 >> y1 >> rightBracket1 >> leftBracket2 >> x2 >> comma2 >> y2 >> rightBracket2) {

        /// Check the format of the coordinates
        if (leftBracket1 == '(' && comma1 == ',' && rightBracket1 == ')' && leftBracket2 == '(' && comma2 == ',' && rightBracket2 == ')') {
            coordinates.emplace_back(x1, y1);
            coordinates.emplace_back(x2, y2);
        }
        else
            throw runtime_error("Invalid coordinate format. Expected (x1,y1)(x2,y2) type!");
    }

    /// Close the file after reading
    file.close();

    /// Check if there are enough points for lines
    if (coordinates.size() < 2 || coordinates.size() % 2 == 1) {
        cerr << "Not enough points for lines." << endl;
        return;
    }

    // Load the original image
    Mat copy_originalImage = CommonProcesses::getRGBData().clone();
    if (copy_originalImage.empty()) {
        cerr << "Couldn't load the original image." << endl;
        return;
    }

    // Draw lines on the original image
    for (int i = 0; i < coordinates.size(); i += 2) {
        line(copy_originalImage, coordinates[i], coordinates[i + 1], cv::Scalar(0, 0, 255), 1);
    }

    CommonProcesses::rescale(detectLines);

    // Display the image with drawn lines
    Detection::visualize(copy_originalImage);
}

/// Destructor
LineDetection::~LineDetection()
{
}