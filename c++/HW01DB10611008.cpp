//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-09-26
//	FILENAME	: HW01DB10611008.cpp
//	DESCRIPTION : This is a program that calculates the maximum load that 
//                can be placed at the end of a symmetrical wooden beam . 
//=================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

double answer1;

int main()
{
    double distance, base, height, stress;
    std::cin >> distance >> base >> height >> stress;
    double momentOfInertia = (base * std::pow(height, 3.0)) / 12;
    answer1 = (stress * momentOfInertia) / (distance * (0.5 * height));
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The maximum load is " << answer1 << " lbs." << std::endl;
    return 0;
}