#include <iostream>
#include <vector>

double answer1;
int answer2;

int main()
{
    int n = 5;
    std::vector<int> data(n);
    for (int i = 0; i < (int)data.size(); i++)
    {
        std::cin >> data[i];
    }
    int max = data[0];
    double total = 0;
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
        total += data[i];
    }
    std::cout << total / n << ' ' << max << std::endl;
    answer1 = total / n;
    answer2 = max;
    return 0;
}