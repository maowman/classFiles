#include <iostream>

int answer1;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    int result = gcd(a, b);
    std::cout << result << std::endl;
    answer1 = result;
    return 0;
}