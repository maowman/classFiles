#include <iostream>
#include <vector>
#include <algorithm>

void show(std::vector<std::vector<int>> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        for (int k = 0; k < data[i].size(); k++)
        {
            std::cout << data[i][k] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return;
}

void show(std::vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

bool three(std::vector<int> souvenirs)
{
    int sum = 0;
    for (int i=0;i<souvenirs.size();i++){
        sum += souvenirs[i];
    }
    if (sum % 3 != 0)
    {
        return false;
    }
    int target = sum / 3;
    for (int i = 0; i < 3; i++)
    {
        std::vector<std::vector<int>> data(souvenirs.size());
        for (int k = 0; k < data.size(); k++)
        {
            std::vector<int> tmp(target + 1);
            data[k] = tmp;
        }
        for (int k = 1; k < data.size(); k++)
        {
            for (int r = 1; r < data[k].size(); r++)
            {
                if (souvenirs[k] > r)
                {
                    data[k][r] = data[k - 1][r];
                }
                else
                {
                    data[k][r] = std::max(data[k - 1][r], data[k - 1][r - souvenirs[k]] + souvenirs[k]);
                }
            }
        }
        //print(data);
        if (data[data.size() - 1][data[0].size() - 1] != target)
        {
            return false;
        }
        int x = data.size() - 1;
        int y = data[x].size() - 1;
        int cache = 0;
        std::vector<int> newSouvenirs(1);
        std::vector<int> taken(0);
        while (true)
        {
            if (x == 0)
            {
                break;
            }
            if (data[x][y] == data[x - 1][y])
            {
                newSouvenirs.push_back(souvenirs[x]);
                cache += souvenirs[x];
                x -= 1;
            }
            else
            {
                taken.push_back(souvenirs[x]);
                y -= souvenirs[x];
                x -= 1;
            }
        }
        //show(taken);
        //show(newSouvenirs);
        if (cache != sum - target * (i + 1))
        {
            return false;
        }
        if (i == 1)
        {
            return true;
        }
        souvenirs.clear();
        for (int k = 0; k < newSouvenirs.size(); k++)
        {
            souvenirs.push_back(newSouvenirs[k]);
        }
    }
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> souvenirs(n + 1);
    for (int i = 1; i < souvenirs.size(); i++)
    {
        std::cin >> souvenirs[i];
    }
    int limit = 100;
    for (int i=0;i<limit;i++){
        std::random_shuffle(souvenirs.begin() , souvenirs.end());
        if (three(souvenirs)){
            std::cout<<1<<std::endl;
            return 0;
        }
    }
    std::cout<<0<<std::endl;
    return 0;

}