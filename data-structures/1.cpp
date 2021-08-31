#include <iostream>
#include <map>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::string instruction;
    std::map<int, std::string> db;
    for (int i = 0; i < n; i++)
    {
        std::cin >> instruction;
        if (instruction == "add")
        {
            int number;
            std::string name;
            std::cin >> number >> name;
            db[number] = name;
        }
        else if (instruction == "find")
        {
            int target;
            std::cin >> target;
            std::map<int, std::string>::iterator it = db.find(target);
            if (it == db.end())
            {
                std::cout << "not found" << std::endl;
            }
            else
            {
                std::cout << it->second << std::endl;
            }
        }
        else if (instruction == "del")
        {
            int target;
            std::cin >> target;
            std::map<int, std::string>::iterator it = db.find(target);
            if (it != db.end()){
                db.erase(it);
            }
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }
}