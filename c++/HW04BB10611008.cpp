//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-14
//	FILENAME	: HW04BB10611008.cpp
//	DESCRIPTION : This is a program that calculate the sum of all the element in a matrix after matrix multiplication
//=================================================================

#include <iostream>
#include <vector>

double answer1;

template <typename T>
void print(std::vector<std::vector<T>> &data)
{
    // this is a function that output a matrix
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            std::cout << data[i][k] << ' ';
        }
        std::cout << std::endl;
    }
    return;
}
template <typename T>
T getElementSum(std::vector<std::vector<T>> &data)
{
    // This is a function that calculate the sum of all elements in a matrix
    T sum = 0;
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            sum += data[i][k];
        }
    }
    return sum;
}

int main()
{
    std::vector<std::vector<double>> matrixA = {{2.1, 3.1, 6.7, 7.1},
                                                {5.0, 3.0, 4.2, 2.2},
                                                {3.3, 4.4, 5.5, 0.5}};

    std::vector<std::vector<double>> matrixB = {{1.0, 1.1, 7.7, 2.1, 4.4},
                                                {2.2, 2.3, 2.3, 8.6, 3.3},
                                                {7.5, 8.1, 2.4, 9.2, 0.7},
                                                {9.1, 2.3, 9.9, 0.5, 0.9}};
    int x = matrixB[0].size();
    int y = matrixA.size(); // define the dimention of matrixC
    std::vector<std::vector<double>> matrixC(y, std::vector<double>(x));
    // perform matrix multiplication
    for (int i = 0; i < (int)matrixA.size(); i++)
    {
        for (int k = 0; k < (int)matrixB[0].size(); k++)
        {
            double sum = 0; // define the sum of each operation
            for (int r = 0; r < (int)matrixA[0].size(); r++)
            {
                sum += matrixA[i][r] * matrixB[r][k];
            }
            matrixC[i][k] = sum;
        }
    }
    print(matrixC);                   // print out matrixC after matrix multiplication
    answer1 = getElementSum(matrixC); // save the sum of all elements in matrixC for Autolab submission check
    return 0;
}