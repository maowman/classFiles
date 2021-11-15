//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-13
//	FILENAME	: HW02CB10611008.cpp
//	DESCRIPTION : This is a program that calculate the value of black jack
//=================================================================

#include <iostream>

int answer1, answer2;

int main()
{
    int condition = -1;      // store the condition
    int score = 0;           // store the score
    int a, b, c;             //store the score of each ball
    std::cin >> a >> b >> c; // user input
    if (a > 10 || b > 10 || c > 10 || a < 0 || b < 0 || c < 0)
    {
        condition = 0; //check for error event
    }
    else if (a == 10) // strike
    {
        if (b == 10)
        {
            score = a + b + c;
            condition = 1;
        }
        else
        {
            if (b + c > 10)
            {
                condition = 0; // error case
            }
            else
            {
                score = a + b + c;
                condition = 1;
            }
        }
    }
    else
    {
        if (a + b > 10)
        {
            condition = 0; // error case
        }
        else if (a + b == 10) // spare
        {
            score = a + b + c;
            condition = 1;
        }
        else if (a + b < 10) // blow
        {
            score = a + b;
            condition = 1;
        }
    }
    if (condition == 1)
    {
        std::cout << "The score is " << score << std::endl;
    }
    else
    {
        std::cout << "Erroneous input!" << std::endl;
    }
    answer1 = score;
    answer2 = condition;
    return 0;
}
