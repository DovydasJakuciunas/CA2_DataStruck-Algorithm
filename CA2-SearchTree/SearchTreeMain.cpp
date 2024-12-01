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

void loadCSV(const string& fileLoc, BinaryTree<Games>& tree, vector<Games>& gameList);
void displayMenu(const BinaryTree<Games>& tree, const vector<Games>& gameList);

void createIndex(const vector<Games>& gameList, const string& field);


int main()
{
    //Extracted Method for Stage 2
    /*
     bool retFlag;
    int retVal = Stage2(retFlag);
    if (retFlag) return retVal;
    */
   
    BinaryTree<Games> gameTree;
    vector<Games> gameList;

    // Load data from CSV file
    loadCSV("Game_Data.csv", gameTree, gameList);

    // Call menu
    displayMenu(gameTree, gameList);


}

int Stage2(bool& retFlag)
{
    retFlag = true;
    Entity<char, BinaryTree<string>> treeMap; 
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
    transform(upper.begin() + 1, upper.end(), upper.begin() + 1, tolower);
    return upper;
}


void loadCSV(const string& fileLoc, BinaryTree<Games>& tree, vector<Games>& gameList) {
    ifstream file(fileLoc);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << fileLoc << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, developer, genre, yearString, ratingString;    

        getline(ss, name, ',');
        getline(ss, developer, ',');
        getline(ss, yearString, ',');
        getline(ss, genre, ',');
        getline(ss, ratingString, ',');

        
        if (!yearString.empty() && all_of(yearString.begin(), yearString.end(), isdigit)) //Making sure no mistakes in year formation 
        {
            int year = stoi(yearString);
            float rating = stof(ratingString);

			Games game(name, developer, year, genre, rating);   
            tree.add(game);        
            gameList.push_back(game); 
        }

    }
    file.close();
}

void createIndex(const vector<Games>& gameList, const string& field) {
    map<string, int> indexMap;

	//Create index based on the field
    for (const auto& game : gameList) {
        string key;
        if (field == "name") {
            key = game.name;
        }
        else if (field == "developer") {
            key = game.developer;
        }
        else if (field == "year") {
            key = to_string(game.year);
        }
        else if (field == "genre") {
            key = game.genre;
        }
        else if (field == "rating") {
            key = to_string(game.rating);
        }
        else {
            cerr << "Invalid field: " << field << "\n";
            return;
        }

        indexMap[key]++;
    }

    //Getting a neat | print out
    size_t maxLength = 0;
    for (const auto& pair : indexMap) {
        maxLength = max(maxLength, pair.first.length());
    }

    // Display the index
    cout << "\nIndex for field: " << field << "\n";
    cout << "Value" << string(maxLength - 5 + 2, ' ') << "| Count\n";
    cout << string(maxLength + 8, '-') << "\n";

    for (const auto& pair : indexMap) {
        cout << pair.first << string(maxLength - pair.first.length() + 2, ' ') << "| " << pair.second << "\n";
    }
}
template <class T, class FieldExtractor>
void createIndex(const vector<Games>& items, const string& fieldName) {
    map<string, int> indexMap;

    //Get item based on field
    for (const auto& game : items) {
        string key;
        if (fieldName == "name") {
            key = game.name;
        }
        else if (fieldName == "developer") {
            key = game.developer;
        }
        else if (fieldName == "year") {
            key = to_string(game.year);
        }
        else if (fieldName == "genre") {
            key = game.genre;
        }
        else if (fieldName == "rating") {
            key = to_string(game.rating);
        }
        else {
            cerr << "Invalid field: " << fieldName << "\n";
            return;
        }
        indexMap[key]++;
    }

    //Makes the | print out neater
    size_t maxLength = 0;
    for (const auto& pair : indexMap) {
        maxLength = max(maxLength, pair.first.length());
    }

    // Display the index
    cout << "\nIndex for field: " << fieldName << "\n";
    cout << "Value" << string(maxLength - 5 + 2, ' ') << "| Count\n";   //For making the | neater
    cout << string(maxLength + 8, '-') << "\n";

    for (const auto& pair : indexMap) {
        cout << pair.first << string(maxLength - pair.first.length() + 2, ' ') << "| " << pair.second << "\n";  //Allignes the | with each value and based on count
    }
}

template <class T, class Predicate >    //Overall predicate to print out filterd items
vector<T> filterItems(const vector<T>& items, Predicate predicate) {
    vector<T> filteredItems;

    for (const auto& item : items) {
        if (predicate(item)) {
            filteredItems.push_back(item);
        }
    }

    return filteredItems;
}

void displayMenu(const BinaryTree<Games>& tree, const vector<Games>& gameList) {
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display all games\n";
        cout << "2. Create an index based on a specific field\n";
        cout << "3. Filter games by a predicate (genre,rating,developer)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (const auto& game : gameList) {
                cout << game << "\n";
            }
            break;

        case 2: {
            string field;
            cout << "Enter the field to index (name/developer/year/genre/rating): ";
            cin >> field;

            createIndex(gameList, field);
            break;
        }

        case 3: 
        {
            string field;
            cout << "Enter the field to filter by (genre/rating/developer): ";
            cin >> field;

            if (field == "genre") {
                string genreFilter;
                cout << "Enter genre to filter by: ";
                cin >> genreFilter;

                // Use a predicate to filter games by genre
                auto filteredGames = filterItems(gameList, [&](const Games& game) {
                    return game.genre == genreFilter;
                    });

                cout << "\nFiltered games:\n";
                for (const auto& game : filteredGames) {
                    cout << game << "\n";
                }
            }
            else if (field == "rating") 
            {
                float ratingFilter;
                cout << "Enter value to search by: ";
                cin >> ratingFilter;

                // Check if the input is valid
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Not in the tree. Go for another number:\n";
                    break;
                }

                // Use a predicate to filter games by rating
                auto filteredGames = filterItems(gameList, [&](const Games& game) {
                    return game.rating == ratingFilter;
                    });

                cout << "\nFiltered games:\n";
                for (const auto& game : filteredGames) {
                    cout << game << "\n";
                }
            }
            else if (field == "developer")
            {
                string devFilter;
                cout << "Enter developer to filter by: ";
                cin.ignore(); // Ignore any leftover input
                getline(cin, devFilter); // Allow full names with spaces

                if (devFilter.empty()) {
                    cout << "Invalid input. Developer name cannot be empty.\n";
                    break;
                }

                // Using predicate to filter by developer
                auto devFilteredGames = filterItems(gameList, [&](const Games& game) {
                    return game.developer == devFilter;
                    });

                if (devFilteredGames.empty()) {
                    cout << "No games found for developer: " << devFilter << "\n";
                }
                else {
                    cout << "\nFiltered games:\n";
                    for (const auto& game : devFilteredGames) {
                        cout << game << "\n";
                    }
                }
				
            }
            else {
                cout << "Invalid field: " << field << ". Please choose 'genre','rating' or 'developer'.\n";
            }
            break;
        }

        case 4:
            return;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}