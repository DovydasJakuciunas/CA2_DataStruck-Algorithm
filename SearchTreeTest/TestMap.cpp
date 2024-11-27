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
		//Testss for adding elements into the treeMap
		TEST_METHOD(TestAddingOneElementIntoTree)
		{
			TreeMap<int, string> tree;
			int key1 = 5;
			string word1 = "Hello";
			tree.put(key1, word1);

			Assert::IsNotNull(tree.root);
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

		//Testing clear method in TreeMap
		TEST_METHOD(TestRemovedAllElements)
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

		TEST_METHOD(TestRemovedAllWithSizeCheck)
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

		//Testing for contains key method in TreeMap
		TEST_METHOD(TestContainsKey)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::IsTrue(tree.containsKey(key3));
		}
        
		TEST_METHOD(TestNoContainsKey)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7, key4 = 8;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey", word4 = "See Ya";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::IsFalse(tree.containsKey(key4));
		}

		TEST_METHOD(TestContainsKeyEmptyTreeMap)
		{
			TreeMap<int, int> tree;
			int key = 5;
			Assert::IsFalse(tree.containsKey(key));
		}

		//Testsing get method from treeMap
		TEST_METHOD(TestGettingWord)
		{
			TreeMap<int, string> tree;
			int key1 = 5;
			string word1 = "Hello";
			tree.put(key1, word1);

			Assert::AreEqual(word1, tree.get(key1));
		}

		TEST_METHOD(TestNoGettingWord)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7, key4 = 2;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey", word4 = "";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);
			tree.put(key4, word4);

			Assert::AreEqual(word4, tree.get(key4));
		}

		TEST_METHOD(TestGettingRightWord)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(word2, tree.get(key2));
		}


	};
}
