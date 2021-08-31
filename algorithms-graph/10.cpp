#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

struct city
{
    int x, y;
    bool selected = false;
};

struct road
{
    int from, to;
    double dist;
    road(int u, int v, std::vector<struct city> &data)
    {
        from = u;
        to = v;
        dist = std::sqrt(std::pow(data[u].x - data[v].x, 2) + std::pow(data[u].y - data[v].y, 2));
    }
};

struct cmp
{
    bool operator()(struct road a, struct road b)
    {
        return a.dist > b.dist;
    }
};

double prim(std::vector<struct city> &data)
{
    std::priority_queue<struct road, std::vector<struct road>, cmp> heap;
    data[0].selected = true;
    for (int i = 1; i < data.size(); i++)
    {
        struct road tmp(0, i, data);
        heap.push(tmp);
    }
    int counter = 0;
    double result = 0;
    while (counter < data.size() - 1)
    {
        if (heap.empty() == true)
        {
            std::cout << "Error:heap empty" << std::endl;
            break;
        }
        struct road r = heap.top();
        heap.pop();
        if (data[r.to].selected == true)
        {
            continue;
        }
        else
        {
            data[r.to].selected = true;
            result += r.dist;
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i].selected == false)
                {
                    struct road nr(r.to, i, data);
                    heap.push(nr);
                }
            }
            counter += 1;
        }
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<struct city> data(n);

    for (int i = 0; i < data.size(); i++)
    {
        std::cin >> data[i].x >> data[i].y;
    }
    double result = prim(data);
    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    return 0;
}