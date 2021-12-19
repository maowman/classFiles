#include <fstream>
#include <iostream>
#include <string>

std::string answer1;

int main()
{
    int n = 5;
    std::string name, filename = "grades.dat";
    double grade1, grade2, grade3;
    std::ofstream outputFile;
    outputFile.open(filename.c_str());
    for (int i = 0; i < n; i++)
    {
        std::cin >> name >> grade1 >> grade2 >> grade3;
        outputFile << name << ' ' << grade1 << ' ' << grade2 << ' ' << grade3 << std::endl;
    }
    answer1 = name;
    return 0;
}