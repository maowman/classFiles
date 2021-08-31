#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

struct coord
{
    int x = -1, y = -1;
};

struct node
{
    int value = 0;
    struct coord from;
};

std::vector<int> lcs(std::vector<int> &a, std::vector<int> &b)
{
    std::vector<std::vector<struct node>> data(a.size() + 1);
    for (int i = 0; i < data.size(); i++)
    {
        std::vector<struct node> cache(b.size() + 1);
        data[i] = cache;
    }
    for (int i = 1; i < data.size(); i++)
    {
        for (int k = 1; k < data[i].size(); k++)
        {
            if (a[i - 1] == b[k - 1])
            {
                data[i][k].value = data[i - 1][k - 1].value + 1;
                struct coord tmp;
                tmp.x = i - 1;
                tmp.y = k - 1;
                data[i][k].from = tmp;
            }
            else
            {
                if (data[i - 1][k].value < data[i][k - 1].value)
                {
                    data[i][k].value = data[i][k - 1].value;
                    struct coord tmp;
                    tmp.x = i;
                    tmp.y = k - 1;
                    data[i][k].from = tmp;
                }
                else
                {
                    data[i][k].value = data[i - 1][k].value;
                    struct coord tmp;
                    tmp.x = i - 1;
                    tmp.y = k;
                    data[i][k].from = tmp;
                }
            }
        }
    }
    /**
    
    for (int i = 0; i < data.size(); i++)
    {
        for (int k=0;k<data[i].size();k++){
            std::cout<<'('<<data[i][k].from.x<<','<<data[i][k].from.y<<','<<data[i][k].value<<')';
        }
        std::cout<<std::endl;
    }
    **/

    std::vector<int> result;
    struct coord ptr;
    ptr.x = data.size() - 1;
    ptr.y = data[ptr.x].size() - 1;
    while (true)
    {
        //std::cout<<'('<<ptr.x<<','<<ptr.y<<')'<<std::endl;
        if (ptr.x == -1 || ptr.y == -1)
        {
            break;
        }
        if (a[ptr.x - 1] == b[ptr.y - 1])
        {
            result.push_back(a[ptr.x - 1]);
        }
        ptr = data[ptr.x][ptr.y].from;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int a;
    std::cin >> a;
    std::vector<int> seqA(a);
    for (int i = 0; i < seqA.size(); i++)
    {
        std::cin >> seqA[i];
    }
    int b;
    std::cin >> b;
    std::vector<int> seqB(b);
    for (int i = 0; i < seqB.size(); i++)
    {
        std::cin >> seqB[i];
    }
    int c;
    std::cin >> c;
    std::vector<int> seqC(c);
    for (int i = 0; i < seqC.size(); i++)
    {
        std::cin >> seqC[i];
    }
    std::vector<int> cache = lcs(seqA , seqB);
    print(cache);
    std::vector<int> seq = lcs(seqC , cache);
    print(seq);
    std::cout<<seq.size()<<std::endl;
    return 0;
}