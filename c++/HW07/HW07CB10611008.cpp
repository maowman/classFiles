//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-12-26
//	FILENAME	: HW07BB10611008.cpp
//	DESCRIPTION : This is a program that find clusters in data
//=================================================================

#include <vector>
#include <iostream>
#include <fstream>
#include <tuple>
#include <cmath>
#include <ctime>
#include <cstdlib>

int answer1, answer2, answer3;

class Coord
{
private:
    double x, y;

public:
    Coord()
    {
        x = -1;
        y = -1;
    }
    Coord(double inputX, double inputY)
    {
        x = inputX;
        y = inputY;
    }
    friend std::ostream &operator<<(std::ostream &os, const Coord cd)
    {
        os << '(' << cd.x << ',' << cd.y << ')';
        return os;
    }
    auto getData()
    {
        return std::make_tuple(x, y);
    }

    double getDistance(const Coord c)
    {
        return sqrt((c.x - x) * (c.x - x) + (c.y - y) * (c.y - y));
    }
    bool operator==(const Coord c)
    {
        return (x == c.x && y == c.y);
    }
};

class Node
{
private:
    Coord coord;
    char cluster;
    std::string name;

public:
    Node(double x, double y, std::string inputName)
    {
        coord = Coord(x, y);
        cluster = '#';
        name = inputName;
    }
    friend std::ostream &operator<<(std::ostream &os, const Node n)
    {
        os << n.cluster << ' ' << n.name << ' ' << n.coord;
        return os;
    }
    void setCluster(char inputCluster)
    {
        cluster = inputCluster;
    }

    char getCluster()
    {
        return cluster;
    }

    Coord getCoord()
    {
        return coord;
    }
};

class Cluster
{
private:
    Coord center;
    std::vector<Coord> coords;
    char clusterName;
    void updateCenter()
    {
        double totalX = 0, totalY = 0;
        for (auto el : coords)
        {
            auto data = el.getData();
            totalX += std::get<0>(data);
            totalX += std::get<1>(data);
        }
        double nodeCount = (double)coords.size();
        center = Coord(totalX / nodeCount, totalY / nodeCount);
        std::cout << "Center updated , coords count = " << coords.size() << std::endl;
    }

public:
    Cluster(char inputClusterName)
    {
        clusterName = inputClusterName;
        center = Coord(-1, -1);
    }
    void addNode(Node &node)
    {
        std::cout << "Added node " << node << " to cluster " << clusterName << std::endl;
        node.setCluster(clusterName);
        coords.push_back(node.getCoord());
        updateCenter();
    }

    char getClusterName()
    {
        return clusterName;
    }

    Coord getCenter()
    {
        return center;
    }

    double getDistance(Node n)
    {
        return center.getDistance(n.getCoord());
    }

    int getCoordsCount()
    {
        return (int)coords.size();
    }
};

bool assignNode(std::vector<Node> &nodes, Cluster &cluster)
{
    int targetNode = -1;
    for (int i = 0; i < (int)nodes.size(); i++)
    {
        if (cluster.getCenter() == Coord(-1, -1))
        {
            targetNode = rand() % (int)nodes.size();
            break;
        }
        if (nodes[i].getCluster() == '#' && (targetNode == -1 || cluster.getDistance(nodes[i]) < cluster.getDistance(nodes[targetNode])))
        {
            targetNode = i;
        }
    }
    if (targetNode != -1)
    {
        cluster.addNode(nodes[targetNode]);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(NULL));
    std::ifstream inputFile("iris.data");
    std::string name;
    double x, y;
    std::vector<Node> nodes;
    while (inputFile >> name >> x >> y)
    {
        nodes.push_back(Node(x, y, name));
    }
    Cluster clusterA('A'), clusterB('B'), clusterC('C');
    bool flag = true;
    for (auto el : nodes)
    {
        std::cout << el << std::endl;
    }
    while (flag == true)
    {
        flag = assignNode(nodes, clusterA);
        flag = assignNode(nodes, clusterB);
        flag = assignNode(nodes, clusterC);
    }
    std::ofstream outputFile("Iris.out");
    std::cout << "Result:" << std::endl;
    for (auto el : nodes)
    {
        std::cout << el << std::endl;
        outputFile << el << std::endl;
    }

    answer1 = clusterA.getCoordsCount();
    answer2 = clusterB.getCoordsCount();
    answer3 = clusterC.getCoordsCount();
    return 0;
}