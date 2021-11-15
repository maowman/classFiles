#include <iostream>

double answer1;

int main()
{
    double cel, fahr;
    std::cout << "Please input the Fahrenheit degrees: ";
    std::cin >> fahr;
    cel = (5.0 / 9.0) * (fahr - 32.0);
    std::cout << "For a Fahrenheit temperature of " << fahr << " degrees" << std::endl;
    std::cout << "  the equivalent Celsius temperature is " << cel << " degrees" << std::endl;
    answer1 = cel;
    return 0;
}