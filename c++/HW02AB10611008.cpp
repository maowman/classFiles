//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-13
//	FILENAME	: HW02AB10611008.cpp
//	DESCRIPTION : This is a program that tell the user which quadrant or axis the coordinate point lies
//=================================================================

#include <iostream>
#include <string>

int answer1;

int main()
{
    double x, y;
    int result = -1; // define variables
    std::string message = "error";
    std::cout << "Please enter the coordinate: ";
    std::cin >> x >> y;
    if (x == 0 && y == 0)
    {
        result = 7;
        message = "the orgin";
    }
    else if (x == 0 || y == 0)
    {
        if (x == 0)
        {
            result = 6;
            message = "on the y-axis";
        }
        else if (y == 0)
        {
            result = 5;
            message = "on the x-axis";
        }
    }
    else
    {
        if (x > 0)
        {
            if (y > 0)
            {
                result = 1;
                message = "in quadrant I";
            }
            else if (y < 0)
            {
                result = 4;
                message = "in quadrant IV";
            }
        }
        else if (x < 0)
        {
            if (y > 0)
            {
                result = 2;
                message = "in quadrant II";
            }
            else if (y < 0)
            {
                result = 3;
                message = "in quadrant III";
            }
        }
    }                                                                                      // logic and message
    std::cout << "The point ( " << x << " , " << y << " ) is " << message << "." << std::endl; // output the result;
    answer1 = result;                                                                      // save the value of result for Autolab submission check
    return 0;                                                                              // program end
}