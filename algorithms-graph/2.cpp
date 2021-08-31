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

int join(std::vector<int> &data, int a, int b)
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
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int vertex, edge;
    int u, v;
    std::cin >> vertex >> edge;
    std::vector<int> data(vertex + 1); // 1-based input
    int count = vertex;
    for (int i = 0; i < data.size(); i++)
    {
        data[i] = i;
    }
    for (int i = 0; i < edge; i++)
    {
        std::cin >> u >> v;
        count += join(data, u, v);
    }
    std::cout << count << std::endl;
    return 0;
}