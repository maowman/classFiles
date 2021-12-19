//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-28
//	FILENAME	: HW05BB10611008.cpp
//	DESCRIPTION : This is a Game Of Life Simulator
//=================================================================

#include <vector>
#include <iostream>
#include <algorithm>

int answer1, answer2, answer3;

void print(std::vector<std::vector<bool>> &data) // this function is used to output current status of Game of Life
{
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            if (data[i][k] == true)
            {
                std::cout << 1;
            }
            else
            {
                std::cout << 0;
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    return;
}

int countNeighbor(int x, int y, std::vector<std::vector<bool>> &data) // this function is used to count the number of living cell neighbor given x-y coorfinate and the game map
{
    int count = 0;
    for (int i = std::max(x - 1, 0); i < std::min(x + 2, (int)data.size()); i++)
    {
        for (int k = std::max(y - 1, 0); k < std::min(y + 2, (int)data[i].size()); k++)
        {
            if (i == x && k == y)
            {
                continue; // self is not a neighbor
            }
            if (data[i][k] == true)
            {
                count += 1;
            }
        }
    }
    return count;
}

void nextIteration(std::vector<std::vector<bool>> &before) // this function is used to interate the game
{
    std::vector<std::vector<bool>> after(before.size(), std::vector<bool>(before[0].size()));
    for (int i = 0; i < (int)before.size(); i++)
    {
        for (int k = 0; k < (int)before[i].size(); k++)
        {
            int neighbor = countNeighbor(i, k, before);
            if (before[i][k] == true)
            {
                if (neighbor < 2)
                {
                    after[i][k] = false; // loneliness
                }
                else if (neighbor > 3)
                {
                    after[i][k] = false; // overcrowding
                }
                else
                {
                    after[i][k] = true; // unchanged
                }
            }
            else
            {
                if (neighbor == 3)
                {
                    after[i][k] = true; // come to life
                }
            }
        }
    }
    before = after;
    return;
}

int countAlive(std::vector<std::vector<bool>> &data)
{
    int count = 0;
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            if (data[i][k] == true)
            {
                count += 1;
            }
        }
    }
    return count;
}

int main()
{
    int round = 10;
    std::vector<std::vector<bool>> gameMap = {
        {false, false, false, false, false, false, false},
        {false, false, true, false, true, false, false},
        {false, false, false, true, false, false, false},
        {false, false, false, true, false, false, false},
        {false, false, true, false, true, false, false},
        {false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false},
    };                                               // initialize game map
    std::vector<int> result = {countAlive(gameMap)}; // store the living cell count of each generation
    for (int i = 0; i < round; i++)
    {
        std::cout << "Round " << i + 1 << ":" << std::endl;
        std::cout << "Living cell count :" << result[i] << std::endl;
        print(gameMap);                        // output the current game status
        nextIteration(gameMap);                // iterate to the next generation
        result.push_back(countAlive(gameMap)); // store the living cell count
    }
    answer1 = result[0];
    answer2 = result[1];
    answer3 = result[2]; // store the living cell cout of the first three generation for Autolab submission check
    return 0;
}