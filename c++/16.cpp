#include <iostream>

int getMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int answer1;

int main()
{
    int a, b;
    std::cin >> a >> b;
    int result = getMax(a, b);
    std::cout << result << std::endl;
    answer1 = result;
    return 0;
}
