#include <iostream>
#include <vector>
#include <algorithm>
struct node
{
    bool visited = false;
    int label;
    std::vector<int> edges;
    int pre = -1;
    int post = -1;
};

void build(std::vector<struct node> &data, int ptr, int &timer)
{
    if (data[ptr].visited == true)
    {
        return;
    }
    else
    {
        data[ptr].visited = true;
        timer += 1;
        data[ptr].pre = timer;
        for (int i = 0; i < data[ptr].edges.size(); i++)
        {
            build(data, data[ptr].edges[i], timer);
        }
        timer += 1;
        data[ptr].post = timer;
        return;
    }
}

void search(std::vector<struct node> &data, int ptr)
{
    //std::cout << "Approaching Node " << ptr << std::endl;
    if (data[ptr].visited == true)
    {
        return;
    }
    else
    {
        data[ptr].visited = true;
        for (int i = 0; i < data[ptr].edges.size(); i++)
        {
            search(data, data[ptr].edges[i]);
        }
        return;
    }
}

bool cmp(struct node l, struct node r)
{
    return l.post > r.post;
}

void print(std::vector<struct node> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << "Node " << data[i].label << " , pre = " << data[i].pre << " , post = " << data[i].post << std::endl;
    }
    return;
}

int main()
{
    int vertex, edge;
    std::cin >> vertex >> edge;
    std::vector<struct node> data(vertex + 1), dataR(vertex + 1);
    for (int i = 0; i < data.size(); i++)
    {
        data[i].label = i;
        dataR[i].label = i;
    }
    int from, to;
    for (int i = 0; i < edge; i++)
    {
        std::cin >> from >> to;
        data[from].edges.push_back(to);
        dataR[to].edges.push_back(from);
    }
    int timer = 0;
    for (int i = 1; i < dataR.size(); i++)
    {
        build(dataR, i, timer);
    }
    //std::cout << "Building complpeted" << std::endl;
    //print(dataR);
    std::sort(dataR.begin(), dataR.end(), cmp);
    ///print(dataR);
    int result = 0;
    for (int i = 0; i < data.size() - 1; i++)
    {
        if (data[dataR[i].label].visited == false)
        {
            //std::cout << "Node " << dataR[i].label << " has the biggest post value , start searching" << std::endl;
            search(data, dataR[i].label);
            result += 1;
        }
    }
    //std::cout << "Searching completed" << std::endl;
    std::cout << result << std::endl;
}
