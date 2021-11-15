#include <iostream>

double answer1;

int main()
{
    int n;
    std::cin >> n;
    int sum = 0, input;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        sum += input;
    }
    double result = (double)sum / (double)n;
    std::cout << result << std::endl;
    answer1 = result;
    return 0;
}