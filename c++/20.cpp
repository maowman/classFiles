#include <iostream>
#include <cmath>

double answer1, answer2;

int main()
{
    double c;
    std::cin >> c;
    double r = c / (M_PI * 2);
    double a = pow(r, 2.0) * M_PI;
    std::cout << r << ' ' << a << std::endl;
    answer1 = r;
    answer2 = a;
    return 0;
}