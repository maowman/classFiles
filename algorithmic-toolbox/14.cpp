#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> ad(n), slot(n);
    for (int i = 0; i < ad.size(); i++)
    {
        std::cin >> ad[i];
    }
    for (int i = 0; i < slot.size(); i++)
    {
        std::cin >> slot[i];
    }
    std::sort(ad.begin(), ad.end());
    std::sort(slot.begin(), slot.end());
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        result +=(long long) ad[i] * slot[i];
    }
    std::cout<<result<<std::endl;
    return 0;
}