#include <vector>
#include <string>
#include <iostream>

void print(std::vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

std::vector<int> sortByChar(std::string &str)
{
    std::vector<int> converted(str.size());
    std::vector<int> count(5);
    std::vector<int> order(str.size(), -1);
    for (int i = 0; i < converted.size(); i++)
    {
        int tmp = -1;
        switch (str[i])
        {
        case '$':
            tmp = 0;
            break;
        case 'A':
            tmp = 1;
            break;
        case 'C':
            tmp = 2;
            break;
        case 'G':
            tmp = 3;
            break;
        case 'T':
            tmp = 4;
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
        }
        converted[i] = tmp;
        count[tmp] += 1;
    }

    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    //std::cout << "Counting completed" << std::endl;
    for (int i = converted.size() - 1; i >= 0; i--)
    {
        int chr = converted[i];
        count[chr] -= 1;
        order[count[chr]] = i;
    }
    return order;
}

std::vector<int> computeNode(std::string &str, std::vector<int> &order)
{
    std::vector<int> node(str.size());
    node[order[0]] = 0;
    for (int i = 1; i < order.size(); i++)
    {
        if (str[order[i]] == str[order[i - 1]])
        {
            node[order[i]] = node[order[i - 1]];
        }
        else
        {
            node[order[i]] = node[order[i - 1]] + 1;
        }
    }
    return node;
}

void doubleSort(std::string &str, int len, std::vector<int> &order, std::vector<int> &node)
{
    std::vector<int> count(str.size());
    std::vector<int> newOrder(str.size());
    for (int i = 0; i < node.size(); i++)
    {
        count[node[i]] += 1;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = newOrder.size() - 1; i >= 0; i--)
    {
        int startPos = (order[i] - len + str.size()) % str.size();
        int classValue = node[startPos];
        count[classValue] -= 1;
        newOrder[count[classValue]] = startPos;
    }
    order = newOrder;
    return;
}

void updateNode(std::vector<int> &order, std::vector<int> &node, int len)
{
    std::vector<int> newNode(node.size());
    newNode[order[0]] = 0;
    for (int i = 1; i < order.size(); i++)
    {
        int current = order[i];
        int prev = order[i - 1];
        int currentRight = (current + len) % node.size();
        int prevRight = (prev + len) % node.size();
        if (node[current] != node[prev] || node[currentRight] != node[prevRight])
        {
            newNode[current] = newNode[prev] + 1;
        }
        else
        {
            newNode[current] = newNode[prev];
        }
    }
    node = newNode;
    return;
}

int main()
{
    std::string input;
    std::cin >> input;
    std::vector<int> order = sortByChar(input);
    //print(order);
    std::vector<int> node = computeNode(input, order);
    //print(node);
    int len = 1;
    while (len < input.size())
    {
        doubleSort(input, len, order, node);
        updateNode(order, node, len);
        len *= 2;
    }
    print(order);
}