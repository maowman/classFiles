#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

struct memory
{
    int count;
    std::vector<int> pos;
};

std::string gen(std::string &first, std::string &last, char tar, int seq)
{
    int visited = 0;
    int ptr = -1;
    for (int i = 0; i < last.size(); i++)
    {
        if (last[i] == tar)
        {
            visited += 1;
            if (visited == seq)
            {
                ptr = i;
                break;
            }
        }
    }
    //std::cout << "ptr = " << ptr << std::endl;
    if (ptr == -1)
    {
        return "#";
    }
    if (first[ptr] == '$')
    {
        return std::string(1, tar);
    }
    else
    {
        int before = 0;
        for (int i = 0; i < ptr; i++)
        {
            if (first[i] == first[ptr])
            {
                before += 1;
            }
        }
        return tar + gen(first, last, first[ptr], before + 1);
    }
}

std::string countingSort(std::string &str)
{
    int a = 0, t = 0, c = 0, g = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char tmp = str[i];
        if (tmp == 'A')
        {
            a += 1;
        }
        else if (tmp == 'C')
        {
            c += 1;
        }
        else if (tmp == 'G')
        {
            g += 1;
        }
        else if (tmp == 'T')
        {
            t += 1;
        }
    }
    std::string result = "$";
    result += std::string(a, 'A');
    result += std::string(c, 'C');
    result += std::string(g, 'G');
    result += std::string(t, 'T');
    return result;
}

int main()
{
    std::string last;
    std::cin >> last;
    std::string first = countingSort(last);
    //std::cout << first << ' ' << last << std::endl;
    std::string result = gen(first, last, '$', 1);
    int start = 1;
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[(start + i) % result.size()];
    }
    std::cout << std::endl;
    return 0;
}

// duoewhfdowhqoihdiqhwoidhuoqhwocfqioshdihnqwiohdoinwqoidhoiasnidohiqwohduohqwuodboqwbdonwqoidnlyuwqvdikbkjqwbd$
// diwwkdoboiihvhiihbf$hohcsioowoidwodqqoooonoddowqdhkibnsdhiowuuiwduhqwqqddubidoifwwhwjonihoawddhyqqqeoqhqhnnuql