#pragma once
#include "CppUnitTest.h"
#include "../CA2-SearchTree/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchTreeTest
{
	TEST_CLASS(TestTree)
	{
	public:
		//Testing to pass adding one element into tree
		TEST_METHOD(TestAddingElementsIntoTree)
		{
			BinaryTree<int> tree;
			int x = 5;
			tree.add(x);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(5, tree.root->getItem());
		}

		//Testing to see node is one the left when adding a smaller value
		TEST_METHOD(TestAddToRootLeft)
		{
			BinaryTree<int> tree;
			int x = 2, y = 1;
			tree.add(x);
			tree.add(y);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			Assert::IsNotNull(left);
			Assert::AreEqual(1, left->getItem());
		}

		/*
		This test ensures a node is created on the right branch
		when value is less than root.
		*/
		TEST_METHOD(TestAddToRootRight)
		{
			BinaryTree<int> tree;
			int x = 2, y = 3;
			tree.add(x);
			tree.add(y);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			BSTNode<int>* right = tree.root->getRight();
			Assert::IsNotNull(right);
			Assert::AreEqual(3, right->getItem());
		}

		/*
		Test the count function for empty tree
		*/

		TEST_METHOD(TestCountOnEmpty)
		{
			BinaryTree<int> tree;
			Assert::AreEqual(0, tree.count());
		}

		/*
		Test the count function for full tree
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestCountOnFullTree)
		{
			BinaryTree<int> tree;
			int a = 4, b = 2, c = 6, d = 1, e = 3, f = 5, g = 7;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);

			Assert::AreEqual(7, tree.count());
		}

		//Test to see if remove function which isnt in the tree

		TEST_METHOD(TestRemoveItemNotPresent)
		{
			BinaryTree<int> tree;
			int a = 4, b = 2, c = 6, d = 1, e = 3, f = 5, g = 7 , h = 8;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);
			Assert::AreEqual(7, tree.count());
			tree.remove(h);
			Assert::AreEqual(7, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		4
		/ \
		2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestRemoveLeafNode)
		{
			BinaryTree<int> tree;
			int a = 4, b = 2, c = 6, d = 1, e = 3, f = 5, g = 7;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);
			Assert::AreEqual(7, tree.count());
			tree.remove(f);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(7, right->getRight()->getItem());
		}


		/*
		Test the remove function to try and remove a node with one child to the right
		to test this we will use the following tree
		  4
		 / \
		 2   6
		/ \ / \
		1   5  7
				\
				 8
		*/

		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			BinaryTree<int> tree;
			int a = 4, b = 2, c = 6, d = 1, e = 5, f = 7, g = 8;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);
			Assert::AreEqual(7, tree.count());
			tree.remove(f);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(8, right->getRight()->getItem());
		}

		/*
			Test the remove function to try and remove a leaf node
			to test this we will use the following tree
			4
			/ \
			2   6
			/ \ / \
			1 3 5  7
			*/

			TEST_METHOD(TestRemoveNodeWithTwoChildren)
		{
			BinaryTree<int> tree;
			int a = 4, b = 2, c = 6, d = 1, e = 3, f = 5, g = 7;
			tree.add(a);
			tree.add(b);
			tree.add(c);
			tree.add(d);
			tree.add(e);
			tree.add(f);
			tree.add(g);
			Assert::AreEqual(7, tree.count());
			tree.remove(b);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNull(left->getRight());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

			/*
		Test the remove function to try and a node with multiple children
		to test this we will use the following tree:

				   8
				/    \
			   /      \
			  /        \
			 4          12
			/ \        /   \
		   2   6      10   14
		  / \ / \    / \  / \
		 1  3 5  7  9  11 13 15

		 When we remove a node in the middle of the tree, the algorithm
		 should move the next lowest item up to the place of the removed node.
		 In this case 13 will be moved up to the place of 12
		*/

			TEST_METHOD(TestRemoveNodeWithMultipleChildren)
			{
				BinaryTree<int> tree;
				int a = 8, b = 4, c = 12, d = 2, e = 6, f = 1, g = 3, h = 5, i = 7, j = 10, k = 14, l = 9, m = 11, n = 13, o = 15;	
				tree.add(a);
				tree.add(b);
				tree.add(c);
				tree.add(d);
				tree.add(e);
				tree.add(f);
				tree.add(g);
				tree.add(h);
				tree.add(i);
				tree.add(j);
				tree.add(k);
				tree.add(l);
				tree.add(m);
				tree.add(n);
				tree.add(o);
				Assert::AreEqual(15, tree.count());
				Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
				Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getItem());
				tree.remove(c);
				Assert::AreEqual(14, tree.count());
				Assert::AreEqual(13, tree.root->getRight()->getItem());
				Assert::IsNull(tree.root->getRight()->getRight()->getLeft());
			}

			/*	
			This is code to test steps 1 for the project
			*/


	};
}
