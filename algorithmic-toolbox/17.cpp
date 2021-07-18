#include <iostream>
#include <vector>

int search(std::vector<int> &data, int start, int end, int &tar)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (data[mid] > tar)
    {
        return search(data, start, mid - 1, tar);
    }
    else if (data[mid] < tar)
    {
        return search(data, mid + 1, end, tar);
    }
    else
    {
        return mid;
    }
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
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int req;
        std::cin >> req;
        std::cout<<search(data , 0 , data.size()-1 , req)<<' ';
    }
    std::cout<<std::endl;
}