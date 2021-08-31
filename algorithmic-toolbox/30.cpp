#include <iostream>
#include <vector>

struct node
{
    int parent;
    std::vector<int> child;
};

int depth(int position, std::vector<struct node> &data)
{
    int deepest = 0;
    struct node current = data[position];
    for (int i = 0; i < current.child.size(); i++)
    {
        int tmp = depth(current.child[i] , data);
        if (tmp>deepest){
            deepest = tmp;
        }
    }
    return (deepest +1);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<struct node> data(n);
    for (int i = 0; i < data.size(); i++)
    {
        std::cin >> data[i].parent;
    }
    int root;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].parent == -1)
        {
            root = i;
        }
        else
        {
            data[data[i].parent].child.push_back(i);
        }
    }
    std::cout << depth(root, data) << std::endl;
}