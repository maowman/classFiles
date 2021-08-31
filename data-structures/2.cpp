#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int p = 1000000007;
int x = 263;
int strlength = 20;

std::vector<long long> precal(int stringLimit, int prime, int randomNumber)
{
    std::vector<long long> result(stringLimit);
    result[0] = 1;
    for (int i = 1; i < result.size(); i++)
    {
        result[i] = (result[i - 1] * randomNumber) % prime;
        if (result[i] < 0)
        {
            result[i] += prime;
        }
        //std::cout<<result[i]<<std::endl;
    }
    return result;
}

long long cal(std::string str, int m)
{
    std::vector<long long> cache = precal(strlength, p, x);
    long long result = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int tmp = (int)str[i];
        //std::cout<<((tmp * cache[i]) % p)<<std::endl;
        result += ((tmp * cache[i]) % p);
    }
    result = (result % p) % m;
    //std::cout<<"Hash "<<str<<"="<<result<<std::endl;
    return result;
}

int main()
{
    int m, n;
    std::string instruction;
    std::cin >> m >> n;
    std::vector<std::vector<std::string>> db(m);
    for (int i = 0; i < n; i++)
    {
        std::cin >> instruction;
        if (instruction == "add")
        {
            std::string str;
            std::cin >> str;
            long long hash = cal(str, m);
            bool flag = false;
            for (int k = 0; k < db[hash].size(); k++)
            {
                if (db[hash][k] == str)
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                db[hash].insert(db[hash].begin() , str);
            }
        }
        else if (instruction == "check")
        {
            int target;
            std::cin >> target;
            for (int k = 0; k < db[target].size(); k++)
            {
                std::cout << db[target][k] << ' ';
            }
            std::cout << std::endl;
        }
        else if (instruction == "find")
        {
            std::string str;
            std::cin >> str;
            long long hash = cal(str, m);
            bool flag = false;
            for (int k = 0; k < db[hash].size(); k++)
            {
                if (db[hash][k] == str)
                {
                    flag = true;
                    break;
                }
            }
            if (flag == true)
            {
                std::cout << "yes" << std::endl;
            }
            else
            {
                std::cout << "no" << std::endl;
            }
        }
        else if (instruction == "del")
        {
            std::string str;
            std::cin >> str;
            long long hash = cal(str, m);
            for (int k = 0; k < db[hash].size(); k++)
            {
                if (db[hash][k] == str)
                {
                    db[hash].erase(db[hash].begin() + k);
                    break;
                }
            }
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }
}