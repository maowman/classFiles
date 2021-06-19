#include <iostream>
#include <vector>

void print(std::vector<unsigned long long> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
    return;
}

int main()
{
    unsigned long long a, b;
    std::cin >> a >> b;
    std::vector<unsigned long long> data(3);
    data[0] = 0;
    data[1] = 1;
    data[2] = 1;
    unsigned long long ptr = 2;
    while (true)
    {
        if (data[ptr] == 1 && data[ptr - 1] == 0)
        {
            data.pop_back();
            data.pop_back();
            break;
        }
        else
        {
            data.push_back((data[ptr] + data[ptr - 1]) % b);
            ptr += 1;
        }
    }
    //print(data);
    std::cout << data[a % data.size()] << std::endl;
    return 0;
}