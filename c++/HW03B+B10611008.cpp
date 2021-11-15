//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-26
//	FILENAME	: HW03B+B10611008.cpp
//	DESCRIPTION : This is a program that calculate the largets twin prime below 1000
//=================================================================

#include <iostream>
#include <cmath>

int answer1, answer2;

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
    int result;       // store the larger prime of the twin prime
    for (int i = 4; i < limit; i++)
    {
        if (isPrime(i) && isPrime(i - 2))
        {
            result = i;
            std::cout << i << " and " << i - 2 << " is a prime pair" << std::endl;
        }
    }
    answer1 = result - 2; // save the value of the smaller prime for Autolab submission check
    answer2 = result;     // save the value of the larger prime for Autolab submission check
    return 0;
}