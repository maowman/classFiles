#include <iostream>
#include <cmath>
#define PI 3.1416
double answer1 = 0.0;

int main()
{
    double radius, area;
    std::cout << "Please enter the radius:";
    std::cin >> radius;
    if (radius < 0)
    {
        std::cout << "Invalid radius" << std::endl;
    }
    else
    {
        area = PI * std::pow(radius, 2);
        std::cout << "The area of this circle is " << area << std::endl;
        answer1 = area;
    }
    return 0;
}