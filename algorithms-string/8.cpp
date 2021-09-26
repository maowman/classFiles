#include <vector>
#include <string>
#include <iostream>
template <typename T>
void print(T &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::string text, pattern;
    std::cin >> pattern >> text;
    std::string str = pattern + "$" + text;
    std::vector<int> prefix(str.size());
    int border = 0;
    for (int i = 1; i < prefix.size(); i++)
    {
        while (border > 0 && str[i] != str[border])
        {
            border = prefix[border - 1];
        }
        if (str[i] == str[border])
        {
            border = border + 1;
        }
        else
        {
            border = 0;
        }
        prefix[i] = border;
        if (prefix[i] == pattern.size())
        {
            std::cout << i - pattern.size() * 2 << ' ';
        }
    }
    std::cout << std::endl;
    //print(str);
    //print(prefix);
}