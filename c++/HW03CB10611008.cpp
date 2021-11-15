//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-30
//	FILENAME	: HW03CB10611008.cpp
//	DESCRIPTION : This is a program that compute the number of Lychrel numbers below 100000
//=================================================================

#include <iostream>
#include <string>
#include <algorithm>

int answer1;

long long reverseNumber(long long n)
{
    std::string str = std::to_string(n);
    std::reverse(str.begin(), str.end());
    return std::atol(str.c_str());
}

bool isLychrel(long long n, int limit)
{
    long long current = n;
    for (int i = 0; i < limit; i++)
    {
        current += reverseNumber(current); // the next iteration of the current number = current number + reverse(current number)
        if (reverseNumber(current) == current)
        {
            return false;  // if the next iteration is a palindrome number , return false
        }
    }
    return true;
}

int main()
{
    int count = 0;
    int limit = 10000;
    int iterationDepthLimit = 50; // define variables
    for (int i = 1; i <= limit; i++)
    {
        if (isLychrel(i, iterationDepthLimit))
        {
            std::cout << i << " is a Lychrel number" << std::endl;
            count += 1;
        }
    }
    std::cout << "There are " << count << " Lychrel numbers below " << limit << std::endl; // output the total number of lychrel numbers
    answer1 = count;                                                                       // save the value of count for Autolab submission check
    return 0;
}
