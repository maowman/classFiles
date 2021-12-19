//=================================================================
//	PROGRAMMER  : 梁安哲
//	DATE	    : 2021-11-28
//	FILENAME	: HW05AB10611008.cpp
//	DESCRIPTION : This is a Caesar Shift Cipher Decoder
//=================================================================
#include <iostream>
#include <string>

char answer1;
char answer2;

int main()
{
    std::string encrypted = "O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN"; // the message we want to decode
    std::string decrypted;
    int shift = -6; // the shift of caesar algorithm
    for (int i = 0; i < (int)encrypted.size(); i++)
    {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') // check if encrypted[i] is a upper letter
        {
            decrypted.push_back((encrypted[i] + shift - 'A' + 26) % 26 + 'A'); // decryption process
        }
        else
        {
            decrypted.push_back(encrypted[i]);
        }
    }
    std::cout << decrypted << std::endl;
    answer1 = decrypted[0];
    answer2 = decrypted[decrypted.size() - 1]; // save the first and last character of decrypted for Autolab submission check
    return 0;
}