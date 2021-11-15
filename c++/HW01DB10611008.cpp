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
    double distance = 8.0 * 12.0;                                // foot to inch
    double base = 2.0, height = 4.0, stress = 3000.0, maxWeight; // define variables
    /*
    std::cout << "The input sequence is distance (d), base, height, and stress (S), respectively.";// tell user about the imput sequence
    std::cin >> distance >> base >> height >> stress; //input
    */
    double momentOfInertia = (base * height * height * height) / 12.0;    // compute the moment of inertia
    maxWeight = (stress * momentOfInertia) / (distance * (0.5 * height)); // comput the maximum weight
    answer1 = maxWeight;                                                  // save the value of maxWeight for Autolab submission check
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The maximum load is " << answer1 << " lbs." << std::endl; // output the answer
    return 0;
}