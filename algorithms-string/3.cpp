#include <iostream>
#include <string>
#include <vector>

struct node
{
    char chr = '$';
    std::vector<int> child;
    bool end = false;
};

void build(std::vector<struct node> &data, std::string &str, int ptr, int seq)
{
    if (seq >= str.length())
    {
        if (seq == str.length())
        {
            data[ptr].end = true;
        }
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

bool match(std::vector<struct node> &data, std::string &str, int charAt, int ptr)
{
    if (data[ptr].child.size() == 0)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < data[ptr].child.size(); i++)
        {
            if (data[data[ptr].child[i]].chr == str[charAt])
            {
                if (data[data[ptr].child[i]].end == true)
                {
                    return true;
                }
                return match(data, str, charAt + 1, data[ptr].child[i]);
            }
        }
        return false;
    }
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
    std::string text;
    std::cin >> text;
    std::vector<struct node> data(1);
    int n;
    std::cin >> n;
    std::string str;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str;
        build(data, str, 0, 0);
    }
    //show(data, 0);
    for (int i = 0; i < text.length(); i++)
    {
        if (match(data, text, i, 0) == true)
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}