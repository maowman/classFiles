//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-26
//	FILENAME	: HW03AB10611008.cpp
//	DESCRIPTION : This is a program that calculate the minimal n value required of a arithmetic series
//=================================================================

#include <iostream>
#include <vector>
#include <cmath>

double answer1;

int main()
{
    double n = 0;
    double error = 2.0;      // define variable
    std::vector<int> fib(2); // store fibonacci numbers
    fib[0] = 1;
    fib[1] = 1; // set up the first two value of fibonacci numbers
    while (true)
    {
        if (error < 0.001)
        {
            break; // if satisfy the condition , end the while loop
        }
        else
        {
            if (n == (int)fib.size())
            {
                fib.push_back(fib[n - 1] + fib[n - 2]); // compute new fibonacci number
            }
            error -= fib[n] * pow(0.5, n + 1); // compute the new error value
            std::cout << "When n = " << n << " , Error is " << error << std::endl;
            n += 1;
        }
    }
    std::cout << n << std::endl;
    answer1 = n; // save the value of n for Autolab submission check
    return 0;    // program end
}