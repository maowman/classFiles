#include <iostream>
#include <vector>
#include <queue>

struct node
{
    int depth = -1;
    int status = 0;
    std::vector<int> edges;
};

void print(std::queue<int> data)
{
    while (data.empty() == false)
    {
        int tmp = data.front();
        data.pop();
        std::cout << tmp << ' ';
    }
    std::cout << std::endl;
}

void bfs(std::vector<struct node> &data, std::queue<int> &work)
{
    while (work.empty() != true)
    {
        int ptr = work.front();
        if (data[ptr].status == 2)
        {
            std::cout << "Error!" << std::endl;
            return;
        }
        //std::cout << "Processing Node " << ptr << std::endl;
        //std::cout << "Queue : ";
        //print(work);
        work.pop();
        for (int i = 0; i < data[ptr].edges.size(); i++)
        {
            //std::cout << "Detected Node " << data[ptr].edges[i] << std::endl;
            if (data[data[ptr].edges[i]].status == 0)
            {
                //std::cout << "This Node hav't been discovered , pushing Node " << data[ptr].edges[i] << std::endl;
                data[data[ptr].edges[i]].status = 1;
                data[data[ptr].edges[i]].depth = data[ptr].depth + 1;
                work.push(data[ptr].edges[i]);
            }
        }
        //std::cout << "Queue : ";
        //print(work);
        data[ptr].status = 2;
        //std::cout << std::endl;
    }
    return;
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
    int start, end;
    std::cin >> start >> end;
    std::queue<int> work;
    work.push(start);
    data[start].status = 1;
    data[start].depth = 0;
    bfs(data, work);
    std::cout << data[end].depth << std::endl;
    return 0;
}