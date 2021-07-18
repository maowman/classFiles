#include <iostream>
#include <vector>

int main()
{
    int d, m, n;
    std::cin >> d >> m >> n;
    std::vector<int> data(n + 2);
    data.front() = 0;
    data.back() = d;
    for (int i = 1; i < data.size() - 1; i++)
    {
        std::cin >> data[i];
    }
    int stops = 0;
    int current = 0;
    while (true)
    {
        int far = current;
        for (int i = current; i < data.size(); i++)
        {
            if (data[i] - data[current] <= m)
            {
                far = i;
            }
            else
            {
                break;
            }
        }
        if (far == data.size() - 1)
        {
            break;
        }
        else if (far == current)
        {
            stops = -1;
            break;
        }
        else
        {
            stops += 1;
            current = far;
        }
    }
    std::cout << stops << std::endl;
}