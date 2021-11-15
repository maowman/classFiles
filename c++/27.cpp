#include <iostream>
#include <cstdlib>
#include <ctime>

int roll()
{
    return 1 + (rand() % 6);
}

struct dice
{
    int a, b;
    dice()
    {
        // std::cout<<"Dice constructed"<<std::endl;
        a = roll();
        b = roll();
    }
};

int answer1;

int main()
{
    srand(time(0));
    int n = 36000;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        struct dice tmp;
        //std::cout << tmp.a << ' ' << tmp.b << std::endl;
        if (tmp.a == 6 && tmp.b == 6)
        {
            counter += 1;
        }
    }
    std::cout << counter << std::endl;
    answer1 = counter;
    return 0;
}