#include <iostream>
#include <algorithm>

double answer1, answer2;

int main()
{
    double a, b;
    std::cin >> a >> b;
    std::swap(a, b);
    std::cout << a << ' ' << b;
    answer1 = a;
    answer2 = b;
    return 0;
}