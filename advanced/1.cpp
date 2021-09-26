#include <iostream>
#include <vector>
#include <queue>
#define upperLimit 200000000

void build(std::vector<std::vector<long long>> &capacity, std::vector<std::vector<long long>> &flow, std::vector<std::vector<long long>> &residual)
{
    int n = capacity[0].size();
    residual = std::vector<std::vector<long long>>(n, std::vector<long long>(n));
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k < n; k++)
        {
            residual[i][k] += capacity[i][k] - flow[i][k];
            residual[k][i] += flow[i][k];
        }
    }
}

long long karp(std::vector<std::vector<long long>> &capacity, std::vector<std::vector<long long>> &flow, std::vector<std::vector<long long>> &residual, int start)
{
    std::queue<int> visit;
    visit.push(start);
    std::vector<bool> visited(capacity[0].size(), false);
    std::vector<int> from(capacity[0].size(), -1);
    std::vector<int> closest(capacity[0].size(), 1000);
    build(capacity, flow, residual);
    long long result = 0;
    while (visit.empty() == false)
    {
        int ptr = visit.front();
        visit.pop();
        visited[ptr] = true;
        //std::cout << "visiting node " << ptr << std::endl;
        bool flag = true;
        if (ptr == capacity[0].size() - 1)
        {
            //std::cout << "This node is sink" << std::endl;
            long long smallest = upperLimit;
            int nxt = ptr;
            int prv = from[ptr];
            //std::cout << "This node is from node " << prv << std::endl;
            std::vector<int> path;
            while (true)
            {
                //std::cout << "Path added " << nxt << std::endl;
                path.push_back(nxt);
                if (nxt == start)
                {
                    break;
                }
                else
                {
                    if (smallest > residual[prv][nxt])
                    {
                        smallest = residual[prv][nxt];
                    }
                    nxt = prv;
                    prv = from[prv];
                }
            }
            for (int i = 0; i < path.size() - 1; i++)
            {
                //std::cout << "Path contains " << path[i] << std::endl;
                flow[path[i + 1]][path[i]] += smallest;
            }
            result += smallest;
            //std::cout << "Smallest residual is " << smallest << std::endl;
            if (smallest == 0)
            {
                break;
            }
            else
            {
                visit = std::queue<int>();
                visit.push(start);
                build(capacity, flow, residual);
                from = std::vector<int>(capacity[0].size(), -1);
                visited = std::vector<bool>(capacity[0].size(), false);
                closest = std::vector<int>(capacity[0].size(), 1000);
            }
        }
        else
        {

            if (ptr == start)
            {
                closest[ptr] = 0;
            }
            for (int i = 1; i < capacity[0].size(); i++)
            {
                if (residual[ptr][i] > 0 && visited[i] == false && closest[i] > closest[ptr] + 1)
                {
                    from[i] = ptr;
                    closest[i] = closest[ptr] + 1;
                    visit.push(i);
                    //std::cout << "Will visit node " << i << std::endl;
                }
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    if (m == 0 || n == 1)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<std::vector<long long>> capacity(n + 1, std::vector<long long>(n + 1));
    std::vector<std::vector<long long>> flow(n + 1, std::vector<long long>(n + 1));
    std::vector<std::vector<long long>> residual(n + 1, std::vector<long long>(n + 1));
    long long from, to, c;
    for (int i = 0; i < m; i++)
    {
        std::cin >> from >> to >> c;
        if (from != to)
        {
            capacity[from][to] += c;
        }
    }
    long long result = karp(capacity, flow, residual, 1);
    std::cout << result << std::endl;
    return 0;
}