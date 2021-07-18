#include <iostream>
#include <vector>
#include <algorithm>

struct node
{
    int step = 0;
    int from = 0;
};

struct option
{
    int value = 0;
    int ptr = 0;
};
main()
{
    int n;
    std::cin >> n;
    std::vector<node> data(n + 1);
    data[1].from = -1;
    data[1].step = 0;
    for (int i = 2; i < data.size(); i++)
    {
        std::vector<struct option> options(1);
        options[0].ptr = i - 1;
        options[0].value = data[i - 1].step + 1;
        if (i % 2 == 0)
        {
            struct option tmp;
            tmp.ptr = i / 2;
            tmp.value = data[i / 2].step + 1;
            options.push_back(tmp);
        }
        if (i % 3 == 0)
        {
            struct option tmp;
            tmp.ptr = i / 3;
            tmp.value = data[i / 3].step + 1;
            options.push_back(tmp);
        }
        struct option best = options[0];
        for (int k = 1; k < options.size(); k++)
        {
            if (options[k].value < best.value)
            {
                best = options[k];
            }
        }
        data[i].step = best.value;
        data[i].from = best.ptr;
    }
    //std::cout << "dp completed" << std::endl;
    std::vector<int> result;
    std::cout << data.back().step << std::endl;
    result.push_back(n);
    int header = data.back().from;
    while (true)
    {
        if (header == -1)
        {
            break;
        }
        else
        {
            result.push_back(header);
            header = data[header].from;
        }
    }
    //std::cout<<"result completed"<<std::endl;
    std::reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
}