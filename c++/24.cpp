#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int answer1, answer2;

int reverse(int n)
{
    std::string str = std::to_string(n);
    std::reverse(str.begin(), str.end());
    return atoi(str.c_str());
}

int main()
{
    int count = 0, cache;
    for (int i = 0; i < 10000; i++)
    {
        if (i == reverse(i))
        {
            count += 1;
            cache = i;
        }
    }
    std::cout << cache << ' ' << count << std::endl;
    answer1 = cache;
    answer2 = count;
    return 0;
}