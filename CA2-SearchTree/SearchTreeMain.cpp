#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Utils.h"
#include "Entity.h"

using namespace std;

string firstLetterCap(const string& str);

int Stage2(bool& retFlag);

int main()
{
    //Extracted Method for Stage 2
    /*
     bool retFlag;
    int retVal = Stage2(retFlag);
    if (retFlag) return retVal;
    */
   
}

int Stage2(bool& retFlag)
{
    retFlag = true;
    Entity<char, BinaryTree<string>> treeMap; //Created map of Entity with char and BinaryTree for string
    ifstream file("UniqueWords.txt");
    string word;

    if (file.is_open()) {
        while (file >> word) {
            word = firstLetterCap(word); //First letter capital, rest lower
            treeMap[word[0]].add(word);
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    cout << "Letters in the tree with words(Only first letter counts): ";
    treeMap.printLetters();

    char letter;
    cout << "Enter a letter to see words: ";
    cin >> letter;
    letter = toupper(letter);
    if (treeMap.get(letter).count() == 0)
    {
        cout << "No words found for the letter " << letter << endl;
    }
    else
    {
        treeMap.printWords(letter);
    }
    retFlag = false;
    return {};
}

string firstLetterCap(const string& str) {
    if (str.empty()) return str; 
    string upper = str;
    upper[0] = toupper(upper[0]);
    transform(upper.begin() + 1, upper.end(), upper.begin() + 1, ::tolower);
    return upper;
}