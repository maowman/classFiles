#include <iostream>
#include <string>

char answer1;

int main()
{
    std::string a, b;
    std::cin >> a >> b;
    std::string result = a + b;
    std::cout << result << std::endl;
    answer1 = result[0];
    return 0;
}