#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct node
{
    unsigned long long value;
    unsigned long long weight;
    double ratio;
};

bool cmp(struct node l, struct node r)
{
    return l.ratio < r.ratio;
}

void print(std::vector<struct node> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i].value << ' ' << data[i].weight << ' ' << data[i].ratio << std::endl;
    }
    return;
}

int main()
{
    unsigned long long n, capacity;
    double result = 0;
    std::cin >> n >> capacity;
    std::vector<struct node> data(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> data[i].value >> data[i].weight;
        data[i].ratio = (double)data[i].value / data[i].weight;
    }
    std::sort(data.begin(), data.end(), cmp);
    while (true)
    {
        if (data.size() == 0)
        {
            break;
        }
        if (capacity > data.back().weight)
        {
            result += data.back().value;
            capacity -= data.back().weight;
            data.pop_back();
        }
        else
        {
            result += (double) (data.back().value * capacity) / data.back().weight;
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(4) << result << std::endl;
    return 0;
}