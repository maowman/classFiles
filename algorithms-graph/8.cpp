#include <iostream>
#include <vector>
#include <queue>

struct heapNode
{
    int distance;
    int lable;
    heapNode(int d, int l)
    {
        distance = d;
        lable = l;
    }
};

struct node
{
    int distance = -1;
    bool processed = false;
    int label;
    std::vector<struct edge> edges;
    node(int l)
    {
        label = l;
    }
    struct heapNode getHeapNode()
    {
        struct heapNode tmp(distance, label);
        return tmp;
    }
};

struct edge
{
    int to;
    int weight;
    edge(int t, int w)
    {
        to = t;
        weight = w;
    }
};

class Cmp
{
public:
    bool operator()(struct heapNode a, struct heapNode b)
    {
        return a.distance > b.distance;
    }
};

void dijkstra(std::vector<struct node> &data, int start)
{
    std::priority_queue<struct heapNode, std::vector<struct heapNode>, Cmp> heap;
    data[start].distance = 0;
    heap.push(data[start].getHeapNode());
    int remainNode = data.size() - 1;
    while (heap.empty() != true)
    {
        struct heapNode tmp = heap.top();
        heap.pop();
        //std::cout << "Now processing Node " << tmp.lable << " the distance of this Node is " << tmp.distance << std::endl;
        if (data[tmp.lable].processed == true)
        {
            continue;
        }
        for (int i = 0; i < data[tmp.lable].edges.size(); i++)
        {
            if (data[data[tmp.lable].edges[i].to].processed == false)
            {
                int newDistance = data[tmp.lable].edges[i].weight + data[tmp.lable].distance;
                if (data[data[tmp.lable].edges[i].to].distance == -1 || newDistance < data[data[tmp.lable].edges[i].to].distance)
                {
                    data[data[tmp.lable].edges[i].to].distance = newDistance;
                    heap.push(data[data[tmp.lable].edges[i].to].getHeapNode());
                    //std::cout << "Setting Node" << data[tmp.lable].edges[i].to << " distance to " << newDistance << std::endl;
                }
            }
        }
        data[tmp.lable].processed = true;
        remainNode -= 1;
    }
    return;
}

int main()
{
    int vertexN, edgeN;
    std::cin >> vertexN >> edgeN;
    std::vector<struct node> data;
    for (int i = 0; i < vertexN + 1; i++)
    {
        struct node tmp(i);
        data.push_back(tmp);
    }
    int from, to, weight;
    for (int i = 0; i < edgeN; i++)
    {
        std::cin >> from >> to >> weight;
        struct edge tmp(to, weight);
        data[from].edges.push_back(tmp);
    }
    int start, end;
    std::cin >> start >> end;
    dijkstra(data, start);
    std::cout << data[end].distance << std::endl;
}