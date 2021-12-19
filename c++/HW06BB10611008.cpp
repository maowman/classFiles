//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-12-12
//	FILENAME	: HW06BB10611008.cpp
//	DESCRIPTION : This is a word finder
//=================================================================

#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

int answer1, answer2;

int main()
{
    std::ifstream dictionaryText("Dictionary.txt");
    std::ofstream saveResult("ValidWords.txt");
    std::string word;
    std::set<std::string> dictionary, result;
    while (dictionaryText >> word) // read from "Dictionary.txt"
    {
        // std::cout << word << std::endl;
        dictionary.insert(word); // add the word to dictionary
    }

    answer1 = (int)dictionary.size(); // save the size of dictionary for Autolab submission check
    std::string target = "stable$";   // character $ means the end of sub-string
    std::sort(target.begin(), target.end());
    do
    {
        // std::cout << target << std::endl;
        std::string generatedSubString;
        for (int i = 0; i < (int)target.size(); i++)
        {
            if (target[i] == '$')
            {
                break; // means the eand of sub-string
            }
            else
            {
                generatedSubString += target[i];
            }
        }
        if ((int)generatedSubString.size() > 0 && dictionary.count(generatedSubString) != 0)
        {
            result.insert(generatedSubString);
            dictionary.erase(generatedSubString); // if the generatedSubString exists in the dictionary , then add it to result and remove it from the dictionary
        }
    } while (std::next_permutation(target.begin(), target.end())); // use next_permutation to generate all possible sub-string
    std::cout << "All the possible word generated from the word: stable" << std::endl;
    for (auto it : result)
    {
        std::cout << it << std::endl;
        saveResult << it << std::endl; // output each word to screen and "ValidWords.txt"
    }
    answer2 = (int)result.size(); // save the size of result for Autolab submission check
    std::cout << answer1 << ' ' << answer2 << std::endl;
    dictionaryText.close();
    saveResult.close(); // close the files
    return 0;
}