//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-09-26
//	FILENAME	: HW01BB10611008.cpp
//	DESCRIPTION : This is a program that wait the user to enter three floating-point number
//                And then output the sum and average of those three floating-point number
//=================================================================
#include <iostream>
#include <iomanip>
double answer1, answer2;
int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    answer1 = a + b + c;
    answer2 = answer1 / 3;
    std::cout<<std::fixed<<std::setprecision(1);
    std::cout<<"The sum of the three numbers is "<<answer1<<"."<<std::endl;
    std::cout<<"The average of the three numbers is "<<answer2<<"."<<std::endl;
    return 0;
}