#include <iostream>
#include <vector>

struct node
{
    int value;
    int rightChild;
    int leftChild;
};

void in(std::vector<struct node> &data, int ptr)
{
    if (ptr == -1)
    {
        return;
    }
    else
    {
        in(data, data[ptr].leftChild);
        std::cout << data[ptr].value << ' ';
        in(data, data[ptr].rightChild);
        return;
    }
}

void pre(std::vector<struct node> &data, int ptr)
{
    if (ptr == -1)
    {
        return;
    }
    else
    {
        std::cout << data[ptr].value << ' ';
        pre(data, data[ptr].leftChild);
        pre(data, data[ptr].rightChild);
        return;
    }
}

void post(std::vector<struct node> &data, int ptr)
{
    if (ptr == -1)
    {
        return;
    }
    else
    {
        post(data, data[ptr].leftChild);
        post(data, data[ptr].rightChild);
        std::cout << data[ptr].value << ' ';
        return;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<struct node> data(n);
    for (int i = 0; i < data.size(); i++)
    {
        std::cin >> data[i].value >> data[i].leftChild >> data[i].rightChild;
    }
    in(data, 0);
    std::cout << std::endl;
    pre(data, 0);
    std::cout << std::endl;
    post(data, 0);
    std::cout << std::endl;
}