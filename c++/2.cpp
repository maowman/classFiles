// This program computes the sum and the average of two grades;
#include <iostream>

double answer1, answer2; // Autolab submission check

int main()
{
    double grade1, grade2, total, average; // declare variables
    grade1 = 85.5;
    grade2 = 97.0; // set the value of two grade
    total = grade1 + grade2;
    average = total / 2;  // compute the total and average value of two grade
    std::cout << "The average grade is " << average << std::endl; // output
    answer1 = total;
    answer2 = average; // store the value of total & avergae for Autolab submission check
    return 0; // program exit
}