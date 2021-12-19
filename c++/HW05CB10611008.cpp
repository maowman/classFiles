//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-28
//	FILENAME	: HW05CB10611008.cpp
//	DESCRIPTION : This is path finder
//=================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int dfsCounter = 0;
int answer1, answer2;

struct coord
{
    int x, y;
    coord(int inputX, int inputY)
    {
        x = inputX;
        y = inputY;
    }
    bool operator==(struct coord other)
    {
        return (other.x == x) && (other.y == y);
    }
};

void print(std::vector<std::vector<int>> &data) // this function is used to show the current status of the maze
{
    std::cout << "Iteration : " << dfsCounter << std::endl;
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            std::cout << std::setw(3) << data[i][k] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool dfs(std::vector<std::vector<int>> &data, struct coord current, struct coord from, struct coord exit)
{
    if (current.x >= (int)data.size() || current.y >= (int)data[current.x].size() || data[current.x][current.y] == -1)
    {
        return false; // hit a wall , or the boundary of the maze
    }
    dfsCounter += 1; // incriment the counter by one
    if (current == from)
    {
        data[current.x][current.y] = 0;
    }
    else
    {
        data[current.x][current.y] = data[from.x][from.y] + 1; // represent the distance from start
    }

    print(data); // output
    if (current == exit)
    {
        return true;
    }
    struct coord nxtD(current.x + 1, current.y), nxtR(current.x, current.y + 1), nxtU(current.x - 1, current.y), nxtL(current.x, current.y - 1);
    if ((nxtD == from) == false && dfs(data, nxtD, current, exit) == true) // go down
    {
        return true;
    }
    if ((nxtR == from) == false && dfs(data, nxtR, current, exit) == true) // go right
    {
        return true;
    }
    if ((nxtU == from) == false && dfs(data, nxtU, current, exit) == true) // go up
    {
        return true;
    }
    if ((nxtL == from) == false && dfs(data, nxtL, current, exit) == true) // go left
    {
        return true;
    }
    dfsCounter += 1;
    return false; // dead end , return to last position
}

int main()
{
    std::vector<std::vector<int>> maze = {
        {0, 0, 0, 0, 0, 1, -1},
        {-1, 0, -1, -1, 0, 0, -1},
        {-1, 0, -1, -1, 0, 0, 0},
        {0, -1, 0, 0, 0, -1, 0},
        {-1, -1, -1, 0, -1, -1, -1},
        {0, -1, 0, 0, 0, 0, -1},
        {-1, -1, -1, -1, -1, 0, 0}}; // we use -1 to represent wall in the maze
    struct coord end(6, 6), start(0, 0);
    bool result = dfs(maze, start, start, end); // check if the end is reachable
    std::cout << "Path finding completed" << std::endl;
    if (result == true)
    {
        std::cout << "Exit is reacheable!" << std::endl;
    }
    else
    {
        std::cout << "Exit is not reachable!" << std::endl;
    }
    answer1 = maze[end.x][end.y];
    std::cout << dfsCounter << std::endl;
    answer2 = dfsCounter;
    return 0;
}