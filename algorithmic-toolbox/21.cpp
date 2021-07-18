#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    if (n < 5)
    {
        if (n == 1 || n == 3 || n == 4)
        {
            std::cout << 1 << std::endl;
        }
        else
        {
            std::cout << 2 << std::endl;
        }
        return 0;
    }
    std::vector<int> data(n + 1);
    data[1] = 1;
    data[2] = 2;
    data[3] = 1;
    data[4] = 1;
    for (int i = 5; i < data.size(); i++)
    {
        data[i] = std::min(std::min(data[i - 3] + 1, data[i - 4] + 1), data[i - 1] + 1);
    }
    std::cout << data.back() << std::endl;
    return 0;
}