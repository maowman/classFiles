#include <iostream>
#include <string>

char answer1;

int main()
{
    char input;
    std::string grade = "";
    std::cout << "Enter a specification code:";
    std::cin >> input;
    if (input == 'S')
    {
        grade = "space exploration";
    }
    else if (input == 'M')
    {
        grade = "military";
    }
    else if (input == 'C')
    {
        grade = "commercial";
    }
    else if (input == 'T')
    {
        grade = "toy";
    }
    if (grade.length() == 0)
    {
        std::cout << "An invalid code was entered" << std::endl;
    }
    else
    {
        std::cout << "The item is " << grade << "." << std::endl;
    }
    answer1 = input;
    return 0;
}