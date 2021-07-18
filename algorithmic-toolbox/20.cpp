#include <iostream>
#include <vector>

void print(std::vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
    return;
}

void qsort(std::vector<int> &data)
{
    if (data.size()==1|| data.size() == 0){
        return ;
    }
    //print(data);
    int pivot = data[data.size() / 2];
    std::vector<int> l, r, m;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == pivot)
        {
            m.push_back(data[i]);
        }
        else if (data[i] > pivot)
        {
            r.push_back(data[i]);
        }
        else if (data[i] < pivot)
        {
            l.push_back(data[i]);
        }
    }
    qsort(l);
    qsort(r);
    int ptr = 0;
    for (int i = 0; i < l.size(); i++)
    {
        data[ptr] = l[i];
        ptr++;
    }
    for (int i = 0; i < m.size(); i++)
    {
        data[ptr] = m[i];
        ptr++;
    }
    for (int i = 0; i < r.size(); i++)
    {
        data[ptr] = r[i];
        ptr++;
    }
    return;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data(n);
    for (int i = 0; i < data.size(); i++)
    {
        std::cin >> data[i];
    }
    qsort(data);
    print(data);
    std::cout << std::endl;
}


