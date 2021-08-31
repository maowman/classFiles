#include <iostream>
#include <vector>
#include <queue>

struct node
{
    int status = 0;
    int color = 0;
    std::vector<int> edges;
};

bool bi(std::vector<struct node> &data, std::queue<int> work)
{
    while (work.empty() != true)
    {
        int ptr = work.front();
        work.pop();
        if (data[ptr].status == 2)
        {
            std::cout << "Error" << std::endl;
            return false;
        }
        for (int i = 0; i < data[ptr].edges.size(); i++)
        {
            if (data[ptr].color == data[data[ptr].edges[i]].color)
            {
                return false;
            }
            if (data[data[ptr].edges[i]].status == 0)
            {
                data[data[ptr].edges[i]].status = 1;
                data[data[ptr].edges[i]].color = -1 * data[ptr].color;
                work.push(data[ptr].edges[i]);
            }
        }
        data[ptr].status = 2;
    }
    return true;
}

int main()
{
    int vertex, edge;
    std::cin >> vertex >> edge;
    std::vector<struct node> data(vertex + 1);
    int from, to;
    for (int i = 0; i < edge; i++)
    {
        std::cin >> from >> to;
        data[from].edges.push_back(to);
        data[to].edges.push_back(from);
        // undirected graph
    }
    for (int i = 1; i < data.size(); i++)
    {
        if (data[i].status == 0)
        {
            std::queue<int> work;
            work.push(i);
            data[i].color = 1;
            data[i].status = 1;
            bool flag = bi(data, work);
            if (flag == false)
            {
                std::cout << 0 << std::endl;
                return 0;
            }
        }
    }
    std::cout << 1 << std::endl;
    return 0;
}