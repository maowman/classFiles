#include <iostream>
#include <vector>

struct node
{
    int value;
    int rightChild;
    int leftChild;
};

bool dfs(std::vector<struct node> &data, int ptr, int upper, int lower)
{
    if (ptr == -1)
    {
        return true;
    }
    else
    {
        if (data[ptr].value > upper || data[ptr].value < lower)
        {
            return false;
        }
        else
        {
            bool left = dfs(data, data[ptr].leftChild, data[ptr].value, lower);
            bool right = dfs(data, data[ptr].rightChild, upper, data[ptr].value);
            if (left == true && right == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

void output(bool flag)
{
    if (flag == true)
    {
        std::cout << "CORRECT" << std::endl;
    }
    else
    {
        std::cout << "INCORRECT" << std::endl;
    }
    return;
}

int main()
{
    int n;
    std::cin >> n;
    if (n == 0)
    {
        output(true);
        return 0;
    }
    else
    {
        std::vector<struct node> data(n);
        int biggest, smallest;
        int v, l, r;
        for (int i = 0; i < data.size(); i++)
        {
            std::cin >> v >> l >> r;
            data[i].value = v;
            data[i].leftChild = l;
            data[i].rightChild = r;
            if (i == 0)
            {
                biggest = v;
                smallest = v;
            }
            else
            {
                if (v > biggest)
                {
                    biggest = v;
                }
                if (v < smallest)
                {
                    smallest = v;
                }
            }
        }

        output(dfs(data, 0, biggest + 1, smallest - 1));
        return 0;
    }
}