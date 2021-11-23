#include <iostream>
#include <vector>

int main()
{
    int n, m; // number of row and column
    std::cin >> n >> m;
    std::vector<std::vector<int>> data(n, std::vector<int>(m)); // initialize 2-D vector
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            std::cin >> data[i][k]; // data input
        }
    }
    int firstStudentValue;
    std::cin >> firstStudentValue;    // the student picked by the teacher
    int firstStudentX, firstStudentY; // the coordinate of the first student
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (data[i][k] == firstStudentValue)
            {
                firstStudentX = i;
                firstStudentY = k; // record the position of the first student
            }
        }
    }
    int biggest = 0; // smaller than the smallest number possible;
    // skip the first student
    for (int i = 0; i < n; i++)
    {
        if (data[i][firstStudentY] > biggest && i != firstStudentX)
        {
            biggest = data[i][firstStudentY]; // search for same y-axis
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (data[firstStudentX][i] > biggest && i != firstStudentY)
        {
            biggest = data[firstStudentX][i]; // search for same x-axis
        }
    }
    std::cout << biggest << std::endl; // output the answer
    return 0;
}