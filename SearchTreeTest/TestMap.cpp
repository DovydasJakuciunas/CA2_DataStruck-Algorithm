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
		TEST_METHOD(TestClearAllElements)
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

		TEST_METHOD(TestClearAllWithSizeCheck)
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

		TEST_METHOD(TestGetNonExistentKey)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 2;
			string word1 = "Hello";	
			tree.put(key1, word1);

			Assert::IsTrue(tree.get(key2).empty());
		}

		//Test for Binary keySet
		/*TEST_METHOD(TestEmptySet)
		{
			TreeMap<int, string> tree;
			BinaryTree<int> keyS = tree.keySet();
			Assert::IsNull(keyS.root);
		}*/

		//Test Remove key from TreeMap

		TEST_METHOD(TestRemoveEmptyKey)
		{
			TreeMap<int, string> tree;
			Assert::AreEqual(0, tree.size());
		}

		TEST_METHOD(TestRemoveOneKey)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(3, tree.size());
			tree.removeKey(key1);
			Assert::AreEqual(2, tree.size());

		}

		TEST_METHOD(TestRemoveNonExistentKey)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(3, tree.size());
			tree.removeKey(8);
			Assert::AreEqual(3, tree.size());
		}

		TEST_METHOD(TestRemoveAllKey)
		{
			TreeMap<int, string> tree;
			int key1 = 5, key2 = 10, key3 = 7;
			string word1 = "Hello", word2 = "Bye", word3 = "Hey";
			tree.put(key1, word1);
			tree.put(key2, word2);
			tree.put(key3, word3);

			Assert::AreEqual(3, tree.size());
			Assert::IsTrue(tree.removeKey(key1));
			Assert::IsTrue(tree.removeKey(key2));
			Assert::IsTrue(tree.removeKey(key3));
			Assert::AreEqual(0, tree.size());
			Assert::IsFalse(tree.containsKey(key1));
			Assert::IsFalse(tree.containsKey(key2));
			Assert::IsFalse(tree.containsKey(key3));

		}

		
	};
}
