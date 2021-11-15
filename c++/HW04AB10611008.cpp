//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-14
//	FILENAME	: HW04AB10611008.cpp
//	DESCRIPTION : This is a program that calculate the largest perfect number below 10000
//=================================================================

#include <iostream>

int answer1;

bool isPerfect(int n)
{
    int sumOfFactor = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sumOfFactor += i; // which means i is a factor of n , add i to sumOfFactor
        }
    }
    if (n == sumOfFactor)
    {
        return true; // means n equals to the sum of all its factors , i.e. it is a perfect number
    }
    else
    {
        return false;
    }
}

int main()
{
    int limit = 10000; // the limit of the perfect number-finding program
    int largestPerfectNumber;
    for (int i = 1; i < limit; i++)
    {
        // check if i is a perfect number
        if (isPerfect(i))
        {
            std::cout << i << " is a perfect number" << std::endl;
            largestPerfectNumber = i;
        }
    }
    answer1 = largestPerfectNumber; // save the largestPerfectNumber for Autolab submission check
    return 0;
}