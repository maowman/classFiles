#include <iostream>

int answer1;

int main()
{
    int n = 1, counter = 0, target = 30000;
    while (true)
    {
        if (n > target)
        {
            break;
        }
        else
        {
            counter += 1;
            n *= 3;
        }
    }
    std::cout << counter << std::endl;
    answer1 = counter;
    return 0;
}