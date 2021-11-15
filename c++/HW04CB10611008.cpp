//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-14
//	FILENAME	: HW04CB10611008.cpp
//	DESCRIPTION : This is a program that calculate distance between different points
//=================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <limits>

double answer1;

class Point
{
public:
    double x, y;
    Point(double inputX, double inputY)
    {
        // constructor
        x = inputX;
        y = inputY;
    }
    double distanceTo(Point pt)
    {
        // calculate the distance between two points
        return sqrt(pow(x - pt.x, 2.0) + pow(y - pt.y, 2.0));
    }
};

std::ostream &operator<<(std::ostream &os, Point &pt)
{
    return os << '(' << pt.x << ',' << pt.y << ')';
}

int main()
{
    std::vector<Point> data;
    data.push_back(Point(9.1, 49.0));
    data.push_back(Point(24.2, 54.3));
    data.push_back(Point(50.9, 28.5));
    data.push_back(Point(80.7, 54.2));
    data.push_back(Point(81.3, 24.1));
    data.push_back(Point(86.0, 32.1)); // store different points
    for (int i = 0; i < (int)data.size(); i++)
    {
        std::cout << "Point " << i + 1 << " :" << data[i] << std::endl;
    }
    std::cout << "The distance matrix:" << std::endl;
    int columnSize = 5;                                             // set the width of each column
    double shortestPathLength = std::numeric_limits<double>::max(); // initialize the shortest path by the value of biggest value of double possible
    int shortestFrom, shortestTo;                                   // store the path of shortest distance
    for (int i = -1; i < (int)data.size(); i++)
    {
        for (int k = -1; k < (int)data.size(); k++)
        {
            std::cout << std::setw(columnSize);
            if (i == -1) // which means it is the top row
            {
                if (k == -1)
                {
                    std::cout << "Point";
                }
                else
                {
                    std::cout << k + 1;
                }
            }
            else
            {
                if (k == -1)
                {
                    std::cout << i + 1;
                }
                else
                {
                    double distace = data[i].distanceTo(data[k]);
                    if (distace > 0 && distace < shortestPathLength)
                    {
                        shortestPathLength = distace;
                        shortestFrom = i;
                        shortestTo = k;
                    }
                    std::cout << std::setprecision(1) << std::fixed << distace;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "The shortest distance is " << std::setprecision(1) << std::fixed << shortestPathLength << " between Point " << shortestFrom + 1 << " and Point " << shortestTo + 1 << std::endl;
    answer1 = shortestPathLength; // save the shortestPathLength for Autolab submission check
    return 0;
}