#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

std::vector<int> al, cl, gl, tl;
std::vector<char> result;
int st;

struct node
{
    char chr;
    int seq;
};

inline std::vector<struct node> transform(std::string str, int &a, int &c, int &g, int &t)
{
    std::vector<struct node> result(str.length());
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        result[i].chr = chr;
        if (chr == 'A')
        {
            a += 1;
            result[i].seq = a;
            al.push_back(i);
        }
        else if (chr == 'C')
        {
            c += 1;
            result[i].seq = c;
            cl.push_back(i);
        }
        else if (chr == 'G')
        {
            g += 1;
            result[i].seq = g;
            gl.push_back(i);
        }
        else if (chr == 'T')
        {
            t += 1;
            result[i].seq = t;
            tl.push_back(i);
        }
        else
        {
            result[i].seq = 1;
            st = i;
        }
    }
    return result;
}

inline struct node getFirst(int seq, int a, int c, int g, int t)
{
    struct node n;
    if (seq == 0)
    {
        n.chr = '$';
        n.seq = 1;
    }
    else if (seq > 0 && seq < a + 1)
    {
        n.chr = 'A';
        n.seq = seq;
    }
    else if (seq > a && seq < a + c + 1)
    {
        n.chr = 'C';
        n.seq = seq - a;
    }
    else if (seq > a + c && seq < a + c + g + 1)
    {
        n.chr = 'G';
        n.seq = seq - a - c;
    }
    else if (seq > a + c + g && seq < a + c + g + t + 1)
    {
        n.chr = 'T';
        n.seq = seq - a - c - g;
    }
    else
    {
        std::cout << "Error!" << std::endl;
        n.seq = -1;
        n.chr = '#';
    }
    return n;
}

inline void invert(std::vector<struct node> &data, char chr, int seq, int &a, int &c, int &g, int &t)
{
    int ptr = -1;
    if (chr == '$')
    {
        ptr = st;
    }
    else if (chr == 'A')
    {
        if (seq - 1 >= al.size())
        {
            std::cout << "Error at A" << std::endl;
            return;
        }
        ptr = al[seq - 1];
    }
    else if (chr == 'C')
    {
        if (seq - 1 >= cl.size())
        {
            std::cout << "Error at C" << std::endl;
            return;
        }
        ptr = cl[seq - 1];
    }
    else if (chr == 'G')
    {
        if (seq - 1 >= gl.size())
        {
            std::cout << "Error at G" << std::endl;
            return;
        }
        ptr = gl[seq - 1];
    }
    else if (chr == 'T')
    {
        if (seq - 1 >= tl.size())
        {
            std::cout << "Error at T" << std::endl;
            return;
        }
        ptr = tl[seq - 1];
    }
    //std::cout << "ptr = " << ptr << std::endl;
    if (ptr == -1)
    {
        putchar('#');
        return;
    }
    else
    {
        struct node tar = getFirst(ptr, a, c, g, t);
        putchar(tar.chr);
        if (tar.chr == '$')
        {
            return;
        }
        else
        {
            return invert(data, tar.chr, tar.seq, a, c, g, t);
        }
    }
}

int main()
{
    std::string str;
    std::cin >> str;
    int a = 0, c = 0, g = 0, t = 0;
    std::vector<struct node> last = transform(str, a, c, g, t);
    //std::cout << "transform complete" << std::endl;
    invert(last, '$', 1, a, c, g, t);
    putchar('\n');
    return 0;
}
