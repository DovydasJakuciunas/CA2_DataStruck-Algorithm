#pragma once
#include <string>
#include <iostream>
#include "BSTNode.h"
#include "BinaryTree.h"

using namespace std;

struct Games
{
	//Used chatgpt to generate "Top100Games"
	string name, developer, genre;
	int year;
	float rating;
	
	//Empty Constructor
	Games()
	{
		this->name = "";
		this->developer = "";
		this->genre = "";
		this->year = 0;
		this->rating = 0.0;
	}
	//Full Constructor
	Games(string name,string developer, int year, string genre, float rating)
	{
		this->name = name;
		this->developer = developer;
		this->year = year;
		this->genre = genre;
		this->rating = rating;
	}
	friend ostream& operator<<(ostream& out, Games& b)
	{
		out <<"" << b.name << " by" << b.developer << ",Year: " << b.year << ",Genre: "<<b.genre<<",Rating "<<b.rating;
		return out;
	}
	bool operator <(Games& b)
	{
		return name < b.name;
	}
	bool operator>(Games& b)
	{
		return name > b.name;
	}
	bool operator==(Games& b)
	{
		return name == b.name;
	}

};
//Printing out the variables in the tree
ostream& operator<<(ostream& out, Games* b)
{
	out << "" << b->name << " by" << b->developer << ",Year: " << b->year << ",Genre: " << b->genre << ",Rating " << b->rating;
	return out;
}

template<class T>
void printBT(const string& prefix, BSTNode<T>* node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		cout << (isLeft ? "<--" : ">--");

		//Print value of the node
		cout << node->getItem() << endl;

		//Enter the next tree level - left and right
		printBT(prefix + (isLeft ? "|  " : "   "), node->getLeft(), true);
		printBT(prefix + (isLeft ? "|  " : "   "), node->getRight(), false);

	}
}

//Displayes the function to print the tree
template <class T>
void printBT(BSTNode<T>* node)
{
	printBT("", node, true);
}

//Recurive funtion to add each element when balancing tree
void createBalancedTree(BinaryTree<int>& tree, int min, int max, int* arr)
{
	if (min < max)
	{
		int mid = (min + max) / 2;
		tree.add(arr[mid]);
		createBalancedTree(tree, min, mid, arr);
		createBalancedTree(tree, mid + 1, max, arr);
	}
}

//Recursive function used to balance a bianry tree
void balance(BinaryTree<int>& tree)
{
	int* arr = tree.toArray();
	int max = tree.count();
	tree.clear();
	createBalancedTree(tree, 0, max, arr);
	delete[] arr;
}

