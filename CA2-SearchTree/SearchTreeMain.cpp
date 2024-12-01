#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

#include "Utils.h"
#include "Entity.h"

using namespace std;

string firstLetterCap(const string& str);

int Stage2(bool& retFlag);

void loadCSV(const string& filePath, BinaryTree<Games>& tree);
void displayMenu(BinaryTree<Games>& tree);


int main()
{
    //Extracted Method for Stage 2
    /*
     bool retFlag;
    int retVal = Stage2(retFlag);
    if (retFlag) return retVal;
    */
   
    BinaryTree<Games> gameTree;

    // Load data from the CSV file into the binary tree
    loadCSV("Game_Data.csv", gameTree);

    // Display the menu for user interaction
    displayMenu(gameTree);

    return 0;

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

void loadCSV(const string& filePath, BinaryTree<Games>& tree) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filePath << "\n";
        return;
    }

    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;
        stringstream ss(line);
        string name, developer, genre, yearStr, ratingStr;

        // Extract fields from the CSV line
        getline(ss, name, ',');
        getline(ss, developer, ',');
        getline(ss, yearStr, ',');
        getline(ss, genre, ',');
        getline(ss, ratingStr, ',');

        try {
            // Trim whitespace
            name = name.empty() ? "Unknown" : name;
            developer = developer.empty() ? "Unknown" : developer;
            genre = genre.empty() ? "Unknown" : genre;

            // Convert year and rating with validation
            if (!yearStr.empty() && all_of(yearStr.begin(), yearStr.end(), ::isdigit)) {
                int year = stoi(yearStr);

                float rating = stof(ratingStr); // Convert rating to float
                if (rating < 0.0 || rating > 10.0) {
                    throw invalid_argument("Invalid rating range.");
                }

                // Create a Games object and add it to the binary tree
                Games game(name, developer, year, genre, rating);
                tree.add(game);
            }
            else {
                throw invalid_argument("Invalid year or empty fields.");
            }
        }
        catch (const exception& e) {
            cerr << "Error on line " << lineNumber << ": " << e.what() << " | Skipping line: " << line << "\n";
        }
    }

    file.close();
    cout << "Data successfully loaded into the binary tree.\n";
}

void createIndex(BinaryTree<Games>& tree, const string& field) {
    map<string, int> indexMap;
    vector<Games> gamesList;
    tree.printInOrder(); // Assuming this outputs data to console; modify if necessary

    cout << "\nIndex for field: " << field << "\n";
    for (auto& game : gamesList) {
        string key;
        if (field == "name") key = game.name;
        else if (field == "developer") key = game.developer;
        else if (field == "genre") key = game.genre;
        else if (field == "year") key = to_string(game.year);
        else if (field == "rating") key = to_string(game.rating);
        else {
            cout << "Invalid field.\n";
            return;
        }
        indexMap[key]++;

    }

    for (const auto& pair : indexMap) {
        cout << pair.first << ": " << pair.second << " entries\n";
    }
}

void displayMenu(BinaryTree<Games>& tree) {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display all games in order\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nGames in sorted order:\n";
            tree.printInOrder(); // Display all games in sorted order
        }
        else if (choice == 2) {
            break; // Exit the program
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}