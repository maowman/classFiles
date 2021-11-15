#include <iostream>
#include <algorithm>
#include <vector>

int answer1, answer2;

int main()
{
    std::vector<int> data(3);
    for (int i = 0; i < (int)data.size(); i++)
    {
        std::cin >> data[i];
    }
    std::sort(data.begin(), data.end());
    for (int i = 0; i < (int)data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
    answer1 = data[2];
    answer2 = data[0];
    return 0;
}