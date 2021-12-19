#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

char answer1;

int main()
{
    std::ifstream openFile("test.dat");
    std::string content, cache;
    while (openFile >> cache)
    {
        content += cache;
    }
    answer1 = content[0];
    return 0;
}