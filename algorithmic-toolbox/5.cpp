#include <iostream>
#include <vector>

int main()
{
    int limit = 10000000;
    std::vector<unsigned long long> data(limit);
    data[0] = 0;
    data[1] = 1;
    for (int i = 2; i < limit; i++)
    {
        data[i] = (data[i - 1] + data[i - 2]) % 10;
    }
    int n;
    std::cin >> n;
    std::cout << data[n] << std::endl;
    return 0;
}