#include <iostream>
#include <algorithm>

int main()
{
    unsigned long long a, b;
    std::cin >> a >> b;
    std::cout << std::__gcd(a, b) << std::endl;
}