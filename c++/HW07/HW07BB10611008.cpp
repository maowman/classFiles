//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-12-26
//	FILENAME	: HW07BB10611008.cpp
//	DESCRIPTION : This is a program that calculate the data of many people
//=================================================================

#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <functional>

int answer1, answer2, answer3, answer4;

class Person
{
public:
    Person(int inputAge, std::string inputFirstname, std::string inputLastname) // constructor of Person
    {
        firstname = inputFirstname;
        lastname = inputLastname;
        age = inputAge;
    }
    auto getData()
    {
        return std::make_tuple(age, firstname, lastname); // return the age , firstname and lastname using tuple
    }

private:
    std::string firstname, lastname;
    int age;
};

double getAvrgAge(std::vector<Person> &data) // return the average age given a vecrtor of Person
{
    double sum = 0;
    for (auto el : data)
    {
        sum += std::get<0>(el.getData());
    }
    return (sum / data.size());
}

double getExtremeAge(std::vector<Person> &data, std::function<bool(int, int)> cmp) // return the extreme age of a given vetor of Person , provided proper compare function
{
    if (data.size() == 0)
    {
        return -1; // means error
    }
    int extremeValue = std::get<0>(data[0].getData()); // initail value
    for (int i = 1; i < (int)data.size(); i++)
    {
        int cacheAge = std::get<0>(data[i].getData());
        if (cmp(extremeValue, cacheAge) == true) // if satisfy the compare function
        {
            extremeValue = cacheAge;
        }
    }
    return extremeValue;
}

int main()
{
    std::vector<Person> people;
    std::ifstream inputFile("person.txt");
    int age;
    std::string firstname, lastname;
    while (inputFile >> firstname >> lastname >> age) // read from person.txt
    {
        people.push_back(Person(age, firstname, lastname)); // add new Person to people
    }
    double avrgAge = getAvrgAge(people);
    int maxAge = getExtremeAge(people, [](int a, int b)
                               { return a < b; }); // get extreme large value
    int minAge = getExtremeAge(people, [](int a, int b)
                               { return a > b; }); // get extreme small value
    std::cout << "Average age : " << avrgAge << std::endl;
    std::cout << "Max age : " << maxAge << std::endl;
    std::cout << "Min age : " << minAge << std::endl; // output result
    answer1 = people.size();
    answer2 = (int)avrgAge;
    answer3 = maxAge;
    answer4 = minAge; // store the result for Autolab submission check
    return 0;
}