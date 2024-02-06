#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "LineDetection.h"
#include "CornerDetection.h"

using namespace cv;

int main()
{
    try
    {
        LineDetection a(1.5);

        a.drawLines();

        //a.showLinesFromFile();
    }
    catch (const exception& e)
    {
        cerr << "An exception occured: " << e.what() << endl << endl;
    }

    try
    {
        CornerDetection b(1.5);

        b.drawCorners();

        b.showCornersFromFile();
    }
    catch (const exception& e)
    {
        cerr << "An exception occured: " << e.what() << endl << endl;
    }

    return 0;
}