//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-09-26
//	FILENAME	: HW01CB10611008.cpp
//	DESCRIPTION : This is a program that calculates the return frequency from
//                the emitted frequency and speed using the doppler effect.
//=================================================================

#include <iostream>
#include <iomanip>
double answer1;

int main()
{
    double speed, fe, fr, constant; // define variables
    fe = 2e10;
    speed = 55;
    constant = 6.685e8;
    fr = (fe * (constant + speed)) / (constant - speed); // calculate the speed ;
    answer1 = fr;                                        // save the value of speed for Autolab submission check
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The return frequency at "<<speed<<" mph is "<<fr<<" Hz."<< std::endl; // output the return frequency;
    return 0;
}