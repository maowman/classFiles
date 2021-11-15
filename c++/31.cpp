#include <iostream>
#include <string>

char answer1;

int main()
{
    std::string str, encrypted;
    std::cin >> str;
    for (int i = 0; i < (int)str.length(); i++)
    {
        encrypted.push_back(str[i] + 1);
    }
    std::cout << encrypted << std::endl;
    answer1 = encrypted[0];
    return 0;
}
