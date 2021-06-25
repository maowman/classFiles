#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;
    unsigned long long result = 0;
    result += n / 10;
    result += (n % 10) / 5;
    result += (n % 5);
    std::cout << result << std::endl;
    return 0;
}