//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-13
//	FILENAME	: HW02DB10611008.cpp
//	DESCRIPTION : This is a program that calculate the value of black jack
//=================================================================

#include <iostream>
#include <vector>

int answer1, answer2;

int main()
{
    int card = 3;                // the number of card
    int value = 0, sum = 0;      // define values
    std::vector<int> hand(card); // store the values of each card
    for (int i = 0; i < (int)hand.size(); i++)
    {
        std::cin >> hand[i]; //  input the card value
        sum += hand[i];
        if (hand[i] > 10)
        {
            hand[i] = 10; // knight , queen and king
        }
        value += hand[i]; // add up the value of each card
    }

    for (int i = 0; i < (int)hand.size(); i++)
    {
        if (hand[i] == 1)
        {
            if (value + 10 <= 21)
            {
                value += 10;
            }
        }
    }

    answer1 = value;
    answer2 = sum; // save the value of each digit for Autolab submission check
    std::cout << "The total value of hand is " << value << ((value > 21) ? " (bust)." : " .") << std::endl;
    return 0;
}