//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-13
//	FILENAME	: HW02BB10611008.cpp
//	DESCRIPTION : This is a program that encrypt a number;
//=================================================================

#include <iostream>
#include <string>

int answer1, answer2, answer3, answer4, answer5;

int main()
{
    int input;        // input variable
    std::cout << "Please enter the number: ";
    std::cin >> input;
    if (input < 1000 || input > 9999)
    {
        answer5 = 0;// save the value of each digit for Autolab submission check
    }
    else
    {
        std::string str = std::to_string(input);                                    // transfer int to string
        int a = str[0] - '0', b = str[1] - '0', c = str[2] - '0', d = str[3] - '0'; // transfer char to int
        a = (a + 7) % 10;
        b = (b + 7) % 10;
        c = (c + 7) % 10;
        d = (d + 7) % 10; // do the calculation
        std::swap(a, b);
        std::swap(c, d); // do the swaping
        std::cout << a << b << c << d << " is the encrypted number of " << input << std::endl;
        answer5 = 1;
        answer1 = a;
        answer2 = b;
        answer3 = c;
        answer4 = d;// save the value of each digit for Autolab submission check
    }

    return 0;
}