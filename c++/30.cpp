#include <ctime>
#include <cstdlib>
#include <iostream>

int answer1;

int roll()
{
    return (rand() % 6) + 1;
}

int main()
{
    srand(time(NULL));
    int count = 0;
    int n = 36000;
    for (int i = 0; i < n; i++)
    {
        int a = roll(), b = roll();
        if (a == 6 && b == 6)
        {
            count += 1;
        }
    }
    std::cout << count << std::endl;
    answer1 = count;
}