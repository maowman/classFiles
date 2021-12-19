#include <iostream>
#include <cmath>

double answer1, answer2;

int main()
{
    double x, y;
    x = 10.0;
    y = 10.0;
    double r = sqrt(x * x + y * y);
    double a = atan(y / x) * 180.0 / (M_PI);
    std::cout << r << ' ' << a << std::endl;
    answer1 = r;
    answer2 = a;
    return 0;
}