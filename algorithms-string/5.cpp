#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string get(std::string &str, int start)
{
    std::string result;
    for (int i = 0; i < str.length(); i++)
    {
        result += str[(i + start) % str.length()];
    }
    return result;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<std::string> data;
    for (int i = 0; i < str.length(); i++)
    {
        data.push_back(get(str, i));
    }
    std::sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i].back();
    }
    std::cout << std::endl;
    return 0;
}
