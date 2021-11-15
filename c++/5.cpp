#include <iostream>
#include <string>

int main()
{
    int n;
    std::cout << "Please input a five-digit number: ";
    std::cin >> n;
    std::string str = std::to_string(n);
    std::cout << "The five digits are as follows: " << std::endl;
    for (int i = 0; i < (int)str.length(); i++)
    {
        std::cout << str[i] << "   ";
    }
    std::cout << std::endl;
    return 0;
}