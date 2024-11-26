#pragma once
#include "CppUnitTest.h"
#include "../CA2-SearchTree/BinaryTree.h"
#include "../CA2-SearchTree/TreeMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchTreeTest
{
	TEST_CLASS(TestMap)
	{
	public:
		TEST_METHOD(TestAddingOneElementIntoTree)
		{
			TreeMap<int, string> tree;
			int key1 = 5;
			string word1 = "Hello";
			tree.put(key1, word1);

			Assert::AreEqual(1, tree.size());
		}

		TEST_METHOD(TestAddingMultipleElementIntoTree)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 ="Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(3, tree.size());
		}

		TEST_METHOD(TestGettingWord)
		{
			TreeMap<int, string> tree;
			int key1 = 5;
			string word1 = "Hello";
			tree.put(key1, word1);

			Assert::AreEqual(word1, tree.get(key1));
		}

		TEST_METHOD(TestGettingRightWord)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(word3, tree.get(key3));
		}
		
		TEST_METHOD(TestRemovingAllElements)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(3,tree.size());
			tree.clear();
			Assert::IsNull(tree.root);
		}

		TEST_METHOD(TestRemoveWithSizeCheck)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(3, tree.size());
			tree.clear();
			Assert::AreEqual(0, tree.size());
			Assert::IsNull(tree.root);
		}
        
	};
}
