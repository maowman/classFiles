#include <iostream>

double answer1;

int main()
{
    int limit = 10;
    for (int i = 1; i <= limit; i++)
    {
        std::cout << i << ' ' << i * i << ' ' << i * i * i << std::endl;
    }
    answer1 = limit + 1;
    return 0;
}