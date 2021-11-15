//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-26
//	FILENAME	: HW03BB10611008.cpp
//	DESCRIPTION : This is a program that calculate the largets prime number below 1000
//=================================================================

#include <iostream>
#include <cmath>

int answer1;

bool isPrime(int n) // check if n is a prime number
{
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int limit = 1000; // the largest prime number possible
    int result;       // store the largest prime number below limit
    for (int i = 2; i < limit; i++)
    {
        if (isPrime(i))
        {
            result = i;
            std::cout << i << " is a prime number" << std::endl;
        }
    }
    answer1 = result; // save the value of result for Autolab submission check
    return 0;
}