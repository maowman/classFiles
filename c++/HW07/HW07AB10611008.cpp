//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-12-26
//	FILENAME	: HW07AB10611008.cpp
//	DESCRIPTION : This is a word checker
//=================================================================

#include <fstream>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>

int answer1, answer2;

std::string getReverse(std::string str) // this is a funciton that returns the reversed string
{
    std::reverse(str.begin(), str.end());
    return str;
}

int main()
{
    std::ifstream inputFile("words.txt"); // open words.txt
    std::string inputWord;
    std::set<std::string> wordSet; // the word set
    int wordCount = 0;             // store the number of word
    while (inputFile >> inputWord)
    {
        wordCount += 1;
        // std::cout << inputWord << std::endl;
        if (inputWord.size() == 0)
        {
            continue;
        }
        for (int i = 0; i < (int)inputWord.size(); i++)
        {
            inputWord[i] = tolower(inputWord[i]); // convert all character to lowercase
        }
        wordSet.insert(inputWord); // add the word to the wordSet
    }
    std::cout << "Total number of words in words.txt = " << wordCount << std::endl;
    std::string longestResult;
    for (auto word : wordSet)
    {
        if (word.size() > longestResult.size() && wordSet.count(getReverse(word)) != 0) // if the word is longer than the longestResult and the reversed word is in the set
        {
            longestResult = word; // update the longest result
        }
    }
    std::cout << "The longest word we find is : " << longestResult << std::endl;
    answer1 = wordCount;
    answer2 = longestResult.size(); // store the result for Autolab submission check
    return 0;
}