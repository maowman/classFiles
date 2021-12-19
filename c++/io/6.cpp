#include <iostream>
#include <string>
#include <vector>

int answer1;

int main()
{
    std::string str;
    std::vector<std::string> data;
    while (std::cin >> str)
    {
        data.push_back(str);
    }
    std::string target = data[data.size() - 2];
    std::string replacement = data[data.size() - 1];
    int count = 0;
    data.pop_back();
    data.pop_back();
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (data[i] == target)
        {
            count += 1;
        }
    }
    answer1 = count;
    return 0;
}