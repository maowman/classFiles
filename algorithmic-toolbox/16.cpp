#include <iostream>
#include <vector>

int main()
{
    long long n;
    std::cin >> n;
    long long target = 1;
    std::vector<long long> result;
    while (true)
    {
        if (n - target > target)
        {
            result.push_back(target);
            n -= target;
            target += 1;
        }
        else
        {
            result.push_back(n);
            break;
        }
    }
    std::cout << result.size() << std::endl;
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    return 0;
}