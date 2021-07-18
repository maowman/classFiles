#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data(n);
    for (int i = 0; i < data.size(); i++)
    {
        std::cin >> data[i];
    }
    int current = data[0];
    int remain = 1;
    for (int i = 0; i < data.size(); i++)
    {
        {
            if (data[i] == current)
            {
                remain += 1;
            }
            else
            {
                remain -= 1;
                if (remain == 0)
                {
                    remain = 1;
                    current = data[i];
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == current)
        {
            count += 1;
        }
    }
    if (count > data.size() / 2)
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
}