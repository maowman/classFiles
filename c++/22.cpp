#include <iostream>
#include <vector>

int answer1;

int main()
{
    int n = 25;
    std::vector<int> data(n);
    data[0] = 0;
    data[1] = 1;
    for (int i = 2; i < (int)data.size(); i++)
    {
        data[i] = data[i - 1] + data[i - 2];
    }
    answer1 = data[19];
    std::cout << answer1 << std::endl;
    return 0;
}