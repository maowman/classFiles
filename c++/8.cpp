#include <iostream>

int answer1;
double answer2;

int main()
{
    int option;
    double first, second, result;
    std::cin >> first >> second >> option;
    switch (option)
    {
    case 1:
        result = first + second;
        break;
    case 2:
        result = first * second;
        break;
    case 3:
        result = first / second;
        break;
    }
    std::cout << result << std::endl;
    answer1 = option;
    answer2 = result;
    return 0;
}