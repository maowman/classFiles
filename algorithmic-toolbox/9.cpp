#include <iostream>
#include <vector>
#include <numeric>

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
    unsigned long long mod = 10;
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
        data.push_back((data[ptr] + data[ptr - 1]) % mod);
        ptr += 1;
    }
    //print(data);
    unsigned long long sum = std::accumulate(data.begin(), data.end(), (unsigned long long)0);
    //std::cout << sum << std::endl;
    unsigned long long n;
    std::cin >> n;
    unsigned long long result = 0;
    result += (n / data.size()) * sum;
    for (int i = 0; i < (n % data.size())+1; i++)
    {
        result += data[i];
    }
    std::cout << result % mod << std::endl;
    return 0;
}