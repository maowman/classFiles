#include <algorithm>
#include <vector>
#include <iostream>

struct work
{
    int worker;
    unsigned long long finish;
    bool operator<(struct work &other) const
    {
        if (finish == other.finish)
        {
            return worker < other.worker;
        }
        else
        {
            return finish < other.finish;
        }
    }
};
template <typename T>
void down(std::vector<T> &heap, int current)
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
        std::swap(heap[minIndex], heap[current]);
        return down(heap, minIndex);
    }
    else
    {
        return;
    }
}
template <typename T>
void up(std::vector<T> &heap, int current)
{
    if (current == 0)
    {
        return;
    }
    int parent = (current - 1) / 2;
    if (heap[current] < heap[parent])
    {
        std::swap(heap[parent], heap[current]);
        return up(heap, parent);
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> workers(n);
    std::vector<unsigned long long> pending(m);
    std::vector<struct work> working;
    for (int i = 0; i < workers.size(); i++)
    {
        workers[i] = i;
    }
    for (int i = 0; i < pending.size(); i++)
    {
        std::cin >> pending[i];
    }
    unsigned long long time = 0;
    int ptr = 0;
    while (ptr < pending.size())
    {
        if (workers.size() != 0)
        {
            struct work tmp;
            tmp.worker = workers[0];
            tmp.finish = time + pending[ptr];
            std::cout << tmp.worker << ' ' << time << std::endl;
            ptr += 1;
            std::swap(workers[0], workers[workers.size() - 1]);
            workers.pop_back();
            down(workers, 0);
            working.push_back(tmp);
            up(working, working.size() - 1);
        }
        else
        {
            time = working[0].finish;
            int freeWorker = working[0].worker;
            std::swap(working[0], working[working.size() - 1]);
            working.pop_back();
            down(working, 0);
            workers.push_back(freeWorker);
            up(workers, workers.size() - 1);
        }
    }
}