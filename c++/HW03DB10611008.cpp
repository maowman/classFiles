//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-10-30
//	FILENAME	: HW03DB10611008.cpp
//	DESCRIPTION : This is a program that plays the Rock-Paper-Scissors game
//=================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int answer1;

char computer()
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
    {
        return 'R';
    }
    else if (random == 1)
    {
        return 'P';
    }
    else if (random == 2)
    {
        return 'S';
    }
    else
    {
        return 'E';
    }
}

void output(std::string name, char input)
{
    std::string figure;
    if (input == 'R')
    {
        figure = "Rock";
    }
    else if (input == 'S')
    {
        figure = "Scissors";
    }
    else if (input == 'P')
    {
        figure = "Paper";
    }
    std::cout << name << " -> " << figure << std::endl;
}

int main()
{
    int win = 0, lost = 0;
    int stepOfStaircase = 3;
    int round = 0;
    while (true)
    {
        if (win == stepOfStaircase || lost == stepOfStaircase)
        {
            break; // If current game status satisfy the condition, break the while loop
        }
        round += 1;
        std::cout << "Round " << round << std::endl;
        std::cout << "player point: " << win << '/' << stepOfStaircase << std::endl;
        std::cout << "Computer point: " << lost << '/' << stepOfStaircase << std::endl; // let the player know current game state
        std::cout << "Please enter your figure(Rock:R , Paper:P , Scissors:S):" << std::endl;
        char userInput;
        while (std::cin >> userInput)
        {
            if (userInput == 'R' || userInput == 'S' || userInput == 'P')
            {
                break;
            }
            else
            {
                std::cout << "Invalid input , please enter again" << std::endl; // inform the user for invalid input
            }
        }
        char computerInput = computer(); // randomly generate computer's figure
        output("Player", userInput);
        output("Computer", computerInput); // output both the player's and the computer's figure
        if (userInput == computerInput)
        {
            std::cout << "This is a draw" << std::endl; // two same figure = draw
        }
        else
        {
            if ((userInput == 'R' && computerInput == 'S') || (userInput == 'P' && computerInput == 'R') || (userInput == 'S' && computerInput == 'P'))
            {
                win += 1;
                std::cout << "You win this round!" << std::endl; // show the player win or lost
            }
            else
            {
                lost += 1;
                std::cout << "Computer win this round!" << std::endl;
            }
        }
    }
    std::cout << "It takes " << round << " rounds to finish the game" << std::endl; // inform the player about how many round has been played
    answer1 = round;                                                                // save the value of round for Autolab submission check
    return 0;
}