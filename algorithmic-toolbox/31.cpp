#include <iostream>
#include <vector>
#include <algorithm>

struct node
{
    int a;
    int b;
};

void down(std::vector<int> &heap, int current, std::vector<struct node> &record)
{
    int leftIndex = 2 * current + 1;
    int rightIndex = 2 * current + 2;
    int minIndex = current;
    if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex])
    {
        minIndex = leftIndex;
    }
    if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex])
    {
        minIndex = rightIndex;
    }
    if (minIndex != current)
    {
        struct node tmp;
        tmp.a = minIndex;
        tmp.b = current;
        record.push_back(tmp);
        std::swap(heap[minIndex], heap[current]);
        return down(heap, minIndex, record);
    }
    else
    {
        return;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> heap(n);
    std::vector<struct node> record;
    for (int i = 0; i < heap.size(); i++)
    {
        std::cin >> heap[i];
    }
    int startIndex = (n / 2) - 1;
    for (int i = startIndex; i >= 0; i--)
    {
        down(heap, i, record);
    }
    std::cout << record.size() << std::endl;
    for (int i = 0; i < record.size(); i++)
    {
        std::cout << record[i].a << ' ' << record[i].b << std::endl;
    }
    return 0;
}