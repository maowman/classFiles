#include <iostream>
#include <algorithm>

int main()
{
    unsigned long long a, b;
    std::cin >> a >> b;
    unsigned long long gcd = std::__gcd(a, b);
    std::cout << (a * b) / gcd << std::endl;
}