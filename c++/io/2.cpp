#include <iostream>
#include <fstream>
#include <string>
double answer1;
int main()
{
    std::string name, filename = "grades.dat";
    std::ifstream readFile;
    readFile.open(filename.c_str());
    double a, b, c, avrg;
    while (readFile >> name >> a >> b >> c)
    {
        avrg = (a + b + c) / 3.0;
    }
    answer1 = avrg;
    return 0;
}