#include <iostream>

double answer1;

int main()
{
    int student = 4;
    int exam = 3;
    for (int i = 0; i < student; i++)
    {
        double total = 0;
        for (int k = 0; k < exam; k++)
        {
            double score;
            std::cin >> score;
            total += score;
        }
        answer1 = total / (double)exam;
    }
    return 0;
}