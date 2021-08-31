#include <iostream>
#include <vector>

struct node
{
    bool been;
    std::vector<int> edges;
};

void reset(std::vector<struct node> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i].been = false;
    }
}

bool dfs(std::vector<struct node> &data, int ptr, int start)
{
    if (data[ptr].been == true && ptr == start)
    {
        return false;
    }
    else
    {
        if (data[ptr].been == true)
        {
            // prevent stack overflow
            return true;
        }
        data[ptr].been = true;
        for (int i = 0; i < data[ptr].edges.size(); i++)
        {
            if (dfs(data, data[ptr].edges[i], start) == false)
            {
                return false;
            }
        }
        return true;
    }
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
    }
    for (int i = 1; i < data.size(); i++)
    {
        reset(data);
        if (dfs(data, i, i) == false)
        {
            std::cout << 1 << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}