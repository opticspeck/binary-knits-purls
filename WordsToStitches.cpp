/***********************************************************
* WordsToStitches.cpp
* Olivia Mark
*
* This program compares takes a literal string and
* converts it to binary before converting to knits/purls.
* It was made for Remy in March of 2019.
***********************************************************/

#include<iostream>

// Main method that runs the other functions.
int main()
{
    std::string userInput = "";
    std::string inputAsBinary = "";
    std::string inputAsKPs = "";
    int rowSize = 0;

    // getting string input
    std::cout << "Please enter the phrase to be converted:\t";
    getline(std::cin, userInput);

    // converting to binary
    for (int i = 0; i < userInput.size(); i++)
    {
        std::bitset<8> b(userInput.c_str()[i]);
        inputAsBinary += b.to_string();
    } // end for

    // converting to K/Ps
    for (int z = 0; z < inputAsBinary.size(); z++)
    {
        if (inputAsBinary[z] == '0')
            inputAsKPs += 'k';
        else if (inputAsBinary[z] == '1')
            inputAsKPs += 'p';
    } // end for

    std::cout << "How many K/Ps do you want each row to have? "
                 "\n(Hint, your phrase contains " << inputAsKPs.size() << " K/Ps)\t\t";
    std::cin >> rowSize;

    std::cout << "*************************************************\nPurl/Knit pattern:"
                 "\n*************************************************";

    // splitting string into rows
    for (int x = 0; x < inputAsKPs.size(); x++)
    {
        if ((x % rowSize) == 0)
            std::cout << std::endl;
        std::cout << inputAsKPs[x];
    } // end for

} // end main