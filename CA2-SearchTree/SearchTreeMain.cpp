#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "BinaryTree.h"
#include "Utils.h"
#include "Entity.h"

using namespace std;

int min(BSTNode<int>* tree)
{
	while (tree->getLeft() != nullptr)
	{
		tree = tree->getLeft();
	}
	return tree->getItem();
}
int max(BSTNode<int>* tree)
{
	while (tree->getRight() != nullptr)
	{
		tree = tree->getRight();
	}
	return tree->getItem();
}

int main()
{
	BinaryTree<Games> games;
	Games gameVariable;
	Entity<int, string> treeMap;



	/*fstream MyFile("Top100Games.txt");
	if (MyFile.is_open())
	{
		
			getline(MyFile, gameVariable.developer);
			MyFile >> gameVariable.year;
			MyFile >> gameVariable.genre;
			MyFile >> gameVariable.rating;
			MyFile.ignore();

			games.add(gameVariable);
	}
	else
	{
		cout << "******************Couldn't open the file******************"<<endl;
	}*/

	//printBT(games.root);
		
	//MyFile.close();

} 