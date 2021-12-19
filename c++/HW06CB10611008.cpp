//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-12-12
//	FILENAME	: HW06CB10611008.cpp
//	DESCRIPTION : This is a pangram checker
//=================================================================

#include <set>
#include <vector>
#include <iostream>
#include <fstream>

int answer1, answer2;

bool checkPangram(std::string &target)
{
    std::set<char> charSet;
    bool flag = false; // whether the target is pangram
    for (int i = 0; i < 26; i++)
    {
        charSet.insert('a' + i); // define the alphabet set , from 'a' to 'z'
    }
    for (int i = 0; i < (int)target.size(); i++)
    {
        if (charSet.count(target[i]) != 0) // if the i-th character is in the alphabet set , then delete that character in the alphabet set
        {
            charSet.erase(target[i]);
        }
        if (charSet.size() == 0) // if the size of alphabet set is 0 , than it means all the character in the alphabet set has appeared somewhere in the target string
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    std::ifstream inputFile("PangramList.txt");
    std::string sentence;
    std::vector<std::string> data, isPangram, notPangram;
    while (std::getline(inputFile, sentence))
    {
        data.push_back(sentence); // append new sentence to data
    }
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            data[i][k] = tolower(data[i][k]); // convert all the characters in the i-th string into lowercase
        }
        if (checkPangram(data[i])) // check if the i-th string in data is pangram
        {
            isPangram.push_back(data[i]);
        }
        else
        {
            notPangram.push_back(data[i]);
        }
    }
    std::cout << "The following sentences are not pangram:" << std::endl;
    for (auto str : notPangram)
    {
        std::cout << str << std::endl; // output all the strings in notPangram
    }
    answer1 = (int)notPangram.size();
    answer2 = (int)isPangram.size(); // save the size of notPangram and isPangram for Autolab submission check
    inputFile.close();               // close the files
    return 0;
}