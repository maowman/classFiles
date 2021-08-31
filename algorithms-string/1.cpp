#include <iostream>
#include <vector>
#include <string>

struct node
{
    char chr = '$';
    std::vector<int> child;
};

void build(std::vector<struct node> &data, std::string &str, int ptr, int seq)
{
    if (seq >= str.length())
    {
        return;
    }
    char tmp = str[seq];
    for (int i = 0; i < data[ptr].child.size(); i++)
    {
        if (data[data[ptr].child[i]].chr == tmp)
        {
            return build(data, str, data[ptr].child[i], seq + 1);
        }
    }
    // generate new node
    struct node n;
    n.chr = tmp;
    data.push_back(n);
    data[ptr].child.push_back(data.size() - 1);
    return build(data, str, data.size() - 1, seq + 1);
}

void show(std::vector<struct node> &data, int ptr)
{
    if (data[ptr].child.size() == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < data[ptr].child.size(); i++)
        {
            std::cout << ptr << "->" << data[ptr].child[i] << ":" << data[data[ptr].child[i]].chr << std::endl;
            show(data, data[ptr].child[i]);
        }
    }
    return;
}

int main()
{
    std::vector<struct node> data(1);
    int n;
    std::cin >> n;
    std::string str;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str;
        build(data, str, 0, 0);
    }
    show(data, 0);
    return 0;
}