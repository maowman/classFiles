#include <iostream>
#include <vector>

struct node
{
    bool visited = false;
    std::vector<int> edges;
};

void dfs(std::vector<struct node> &data, int ptr, std::vector<int> &result)
{
    if (data[ptr].visited == true)
    {
        return;
    }
    else
    {
        data[ptr].visited = true;
        for (int i = 0; i < data[ptr].edges.size(); i++)
        {
            dfs(data, data[ptr].edges[i], result);
        }
        result.push_back(ptr);
        return;
    }
}

int main()
{
    int vertex, edge;
    std::cin >> vertex >> edge;
    std::vector<struct node> data(vertex + 1);
    std::vector<int> result;
    int from, to;
    for (int i = 0; i < edge; i++)
    {
        std::cin >> from >> to;
        data[from].edges.push_back(to);
    }
    for (int i = 0; i < data.size(); i++)
    {

        dfs(data, i, result);
    }
    for (int i = 0; i < result.size() - 1; i++)
    {
        std::cout << result[data.size() - (1 + i)] << ' ';
    }
    std::cout << std::endl;
}