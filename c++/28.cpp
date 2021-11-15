#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
int answer1;

int main()
{
    int n = 20;
    srand(time(0));
    std::vector<int> data(n);
    for (int i = 0; i < (int)data.size(); i++)
    {
        data[i] = rand()%100;
    }
    std::sort(data.begin(), data.end());
    std::cout << data.back() << std::endl;
    answer1 = data.back();
    return 0;
}