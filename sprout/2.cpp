#include <iostream>

int main()
{
    int n; // the height of the tower
    std::cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        // i = 1 , 2 , 3 ... n
        char display = '0' + i; // determine which charater to display at each level
        for (int k = 0; k < n - i; k++)
        {
            std::cout << ' '; // each level have the same number of character before the middle space , thus fill higher level with space
        }
        for (int k = 0; k < i; k++)
        {
            std::cout << display; // output charater of i i times
        }
        std::cout << ' '; // space between the left side and the right side of the tower
        for (int k = 0; k < i; k++)
        {
            std::cout << display; // repeat output charater of i i times
        }
        std::cout << std::endl; // next level
    }
    return 0;
}