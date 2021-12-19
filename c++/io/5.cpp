#include <iostream>
#include <fstream>
#include <string>

int answer1;

int main()
{
    std::ifstream textfile("info.txt");
    char ch;
    int count = 0;
    while (textfile >> std::noskipws >> ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {w2qqqqqa   `
            count += 1;
        }
    }
    answer1 = count;
    return 0;
}