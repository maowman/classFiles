#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int a;
    std::cin >> a;
    std::vector<int> seqA(a+1);
    for (int i = 1; i < seqA.size(); i++)
    {
        std::cin >> seqA[i];
    }
    int b;
    std::cin >> b;
    std::vector<int> seqB(b+1);
    for (int i = 1; i < seqB.size(); i++)
    {
        std::cin >> seqB[i];
    }

    std::vector<std::vector<int>> data(seqB.size());
    for (int i = 0; i < data.size(); i++)
    {
        std::vector<int> tmp(seqA.size());
        data[i] = tmp;
    }
    for (int i = 1; i < data.size(); i++)
    {
        for (int k = 1; k < data[i].size(); k++)
        {
            if (seqA[k] == seqB[i]){
                data[i][k] = data[i-1][k-1]+1;
            }
            else{
                data[i][k] = std::max(data[i-1][k] , data[i][k-1]);
            }
        }
    }
    std::cout<<data[b][a]<<std::endl;
}