#include <iostream>

double answer1;

double convert(double n)
{
    return (n - 32.0) * 5.0 / 9.0;
}

int main()
{
    int n = 4;
    double input;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        double result = convert(input);
        std::cout << result << std::endl;
    }
    answer1 = convert(input);
    return 0;
}