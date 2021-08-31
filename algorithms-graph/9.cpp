#include <iostream>
#include <vector>
#include <climits>
#define BIGNUM 10000000000
void print(std::vector<std::vector<long long>> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        for (int k = 0; k < data[i].size(); k++)
        {
            long long value = data[i][k];
            if (value == BIGNUM)
            {
                std::cout << "INF ";
            }
            else
            {
                std::cout << value << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int vertex, edge;
    std::cin >> vertex >> edge;
    std::vector<std::vector<long long>> data(vertex + 1, std::vector<long long>(vertex + 1, BIGNUM));
    for (int i = 0; i < data.size(); i++)
    {
        data[i][i] = 0;
    }
    int from, to, weight;
    for (int i = 0; i < edge; i++)
    {
        std::cin >> from >> to >> weight;
        data[from][to] = weight;
    }
    for (int i = 1; i < data.size(); i++)
    {
        for (int l = 1; l < data.size(); l++)
        {
            for (int r = 1; r < data.size(); r++)
            {
                if (data[l][r] > data[l][i] + data[i][r])
                {
                    data[l][r] = data[l][i] + data[i][r];
                }
            }
        }
    }
    //print(data);
    for (int i = 1; i < data.size(); i++)
    {
        if (data[i][i] != 0)
        {
            std::cout << 1 << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}