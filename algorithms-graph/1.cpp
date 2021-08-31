#include <iostream>
#include <vector>

//use disjoint set faster;

int find(std::vector<int> &data, int ptr)
{
    if (data[ptr] == ptr)
    {
        return ptr;
    }
    else
    {
        int result = find(data, data[ptr]);
        data[ptr] = result;
        return result;
    }
}

void join(std::vector<int> &data, int a, int b)
{
    if (b > a)
    {
        return join(data, b, a);
    }
    else
    {
        int pa = find(data, a);
        int pb = find(data, b);
        if (pa != pb)
        {
            data[pb] = pa;
        }
    }
    return;
}

int main()
{
    int vertex, edge;
    int u, v, tc, tv;
    std::cin >> vertex >> edge;
    std::vector<int> data(vertex + 1); // 1-based input
    for (int i = 0; i < data.size(); i++)
    {
        data[i] = i;
    }
    for (int i = 0; i < edge; i++)
    {
        std::cin >> tc >> tv;
        join(data, tc, tv);
    }
    std::cin >> u >> v;
    if (find(data, u) == find(data, v))
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    return 0;
}