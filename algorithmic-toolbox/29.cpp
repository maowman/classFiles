#include <iostream>
#include <vector>
#include <string>

struct node
{
    char data;
    int position;
};

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<struct node> seq;
    bool flag = true;
    for (int i = 0; i < str.length(); i++)
    {
        char character = str[i];
        if (character == '(' || character == '{' || character == '[')
        {
            struct node tmp;
            tmp.data = character;
            tmp.position = i + 1;
            seq.push_back(tmp);
        }
        else if (character == ')' || character == '}' || character == ']')
        {
            if (seq.size() == 0)
            {
                std::cout << i + 1 << std::endl;
                flag = false;
                break;
            }
            if (character == ')')
            {
                if (seq.back().data == '(')
                {
                    seq.pop_back();
                }
                else
                {
                    std::cout << i + 1 << std::endl;
                    flag = false;
                    break;
                }
            }
            if (character == '}')
            {
                if (seq.back().data == '{')
                {
                    seq.pop_back();
                }
                else
                {
                    std::cout << i + 1 << std::endl;
                    flag = false;
                    break;
                }
            }
            if (character == ']')
            {
                if (seq.back().data == '[')
                {
                    seq.pop_back();
                }
                else
                {
                    std::cout << i + 1 << std::endl;
                    flag = false;
                    break;
                }
            }
        }
    }
    if (seq.size() == 0 && flag == true)
    {
        std::cout << "Success" << std::endl;
    }
    else
    {
        if (flag == true)
        {
            std::cout << seq.back().position << std::endl;
        }
    }
}