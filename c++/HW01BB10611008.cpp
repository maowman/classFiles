//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-09-26
//	FILENAME	: HW01BB10611008.cpp
//	DESCRIPTION : This is a program that calculate the sum and average of those three floating-point number
//=================================================================
#include <iostream>
#include <iomanip>
double answer1, answer2;
int main()
{
    double a, b, c, sum, average;                                   //define variables
    std::cout << "Please enter the numbers you want to calculate:"; // inform the user
    std::cin >> a >> b >> c;                                        // input the numbers
    sum = a + b + c;                                                //calculate sum
    average = sum / 3.0;                                            //calculate average
    answer1 = sum;                                                  // save the value of total for Autolab submission check
    answer2 = average;                                              // save the value of average for Autolab submission check
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The sum of the three numbers is " << sum << "." << std::endl;         //output sum
    std::cout << "The average of the three numbers is " << average << "." << std::endl; // output average
    return 0;
}