#include <iostream>
#include <vector>
#include <algorithm>

struct node
{
    long long start;
    long long end;
    bool already;
};

bool cmp(struct node l, struct node r)
{
    return l.start < r.start;
}

void print(std::vector<struct node> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i].start << ' ' << data[i].end << std::endl;
    }
    return;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<struct node> data(n);
    for (int i = 0; i < data.size(); i++)
    {
        std::cin >> data[i].start >> data[i].end;
        data[i].already = false;
    }
    std::sort(data.begin(), data.end(), cmp);
    std::vector<int> result;
    //print(data);
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].already == false)
        {
            data[i].already = true;
            long long point = data[i].start;
            long long upperlimit = data[i].end;
            for (int k = i + 1; k < data.size(); k++)
            {
                if (data[k].start <= upperlimit)
                {
                    point = data[k].start;
                    upperlimit = std::min( upperlimit,data[k].end );
                    data[k].already = true;
                }
                else
                {
                    break;
                }
            }
            result.push_back(point);
        }
    }
    std::cout << result.size() << std::endl;
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    return 0;
}