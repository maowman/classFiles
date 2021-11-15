#include <iostream>
#include <cmath>

int answer1;

int main()
{
    double a, b, c;
    int root = 0;
    std::cin >> a >> b >> c;
    if (a == 0.0 && b == 0.0)
    {
        //std::cout << "No root" << std::endl;
        root = 0;
    }
    else if (a == 0.0)
    {
        //std::cout << "One root" << std::endl;
        root = 1;
    }
    else
    {
        double discriminant = b*b - 4 * a * c;
        if (discriminant > 0.0)
        {
            root = 2;
        }
        else if (discriminant < 0.0)
        {
            root = 2;
        }
        else
        {
            root = 1;
        }
    }
    answer1 = root;
    std::cout << root << std::endl;
    return 0;
}