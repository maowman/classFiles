#include <iostream>
#include <numeric>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int answer1;

int main()
{
    int a, b;
    std::cin >> a >> b;
    int result = gcd(a, b);
    std::cout << result << std::endl;
    answer1 = result;
    return 0;
}