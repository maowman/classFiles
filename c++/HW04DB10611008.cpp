//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-14
//	FILENAME	: HW04CB10611008.cpp
//	DESCRIPTION : This is a program that simulate the game "Craps"
//=================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>

double answer1, answer2;

class Craps
{
public:
    bool win;
    int round;
    Craps()
    {
        int firstRoll = rollDice();
        round = 1;
        if (firstRoll == 7 || firstRoll == 11)
        {
            win = true;
        }
        else if (firstRoll == 2 || firstRoll == 3 || firstRoll == 12)
        {
            win = false;
        }
        else
        {
            while (true)
            {
                int nextRoll = rollDice();
                round += 1;
                if (nextRoll == firstRoll)
                {
                    win = true;
                    break;
                }
                else if (nextRoll == 7)
                {
                    win = false;
                    break;
                }
            }
        }
    }

private:
    int rollDice()
    {
        // simulate the result of rolling two dice
        return (rand() % 6 + 1) + (rand() % 6 + 1);
    }
};

int main()
{
    srand(time(NULL));
    int limit = 10000;                // how many games have to be played
    int sumOfWin = 0, sumOfRound = 0; // game raw data
    for (int i = 0; i < limit; i++)
    {
        Craps game = Craps();
        if (game.win == true)
        {
            sumOfWin += 1;
        }
        sumOfRound += game.round;
        // std::cout << "Player plays " << game.round << " round(s) in Game " << i + 1 << '\n';
    }
    double winRate = (double)sumOfWin / (double)limit;
    double averageRound = (double)sumOfRound / (double)limit; // convert raw data into statistic
    std::cout << "Win rate:" << winRate << std::endl;
    std::cout << "Average round:" << averageRound << std::endl;
    answer1 = winRate;
    answer2 = averageRound; // save the winRate and averageRound for Autolab submission check
    return 0;
}
