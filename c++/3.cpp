#include <iostream>

double answer1;

int main()
{
    double speed, freqOld, freqNew;
    freqOld = 2e10;
    freqNew = 2.0000004e10;
    speed = 6.685e8 * (freqNew - freqOld) / (freqNew + freqOld);
    std::cout << "The speed is " << speed << " miles/hour " << std::endl;
    answer1 = speed;
    return 0;
}