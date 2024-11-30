#include <iostream>

#include "CppUnitTest.h"
#include "../CA2-SearchTree/Entity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestMap	//Tests for put() and size() has been used on near all tests
{
	TEST_CLASS(TestEntity)
	{
	public:
		//Testing to see if the constructor works
		TEST_METHOD(TestConstructor)
		{
			Entity <int, int> tree;
			tree.put(1, 2);
			Assert::AreEqual(1, tree.size());
		}
		TEST_METHOD(TestEmptyConstructor)
		{
			Entity <int, int> tree;
			Assert::AreEqual(0, tree.size());
		}
		TEST_METHOD(TestMultipleConstructor)
		{
			Entity <int, int> tree;
			tree.put(1, 3);
			tree.put(3, 2);
			tree.put(5, 1);
			Assert::AreEqual(3, tree.size());

		}

		//Teststing clear function
		TEST_METHOD(TestClear)
		{
			Entity <int, int> tree;
			tree.put(1, 2);
			tree.put(3, 3);
			tree.put(5, 1);
			Assert::AreEqual(3, tree.size());
			tree.clear();
			Assert::AreEqual(0, tree.size());
		}

		//Testing containsKey functions
		TEST_METHOD(TestContainsKey)
		{
			Entity <int, int> tree;
			tree.put(1, 3);
			tree.put(3, 2);
			tree.put(5, 1);
			Assert::AreEqual(3, tree.size());
			Assert::IsTrue(tree.containsKey(5));
		}
		TEST_METHOD(TestEmptyContainsKey)
		{
			Entity <int, int> tree;
			Assert::IsFalse(tree.containsKey(5));
		}
		TEST_METHOD(TestMiddleContainsKey)
		{
			Entity <int, int> tree;
			tree.put(5, 7);
			tree.put(9, 6);
			tree.put(3, 5);
			tree.put(7, 4);
			tree.put(1, 1);
			tree.put(8, 2);
			Assert::AreEqual(6, tree.size());
			Assert::IsTrue(tree.containsKey(7));
		}

		//Testing getting functions
		TEST_METHOD(TestGetWord)
		{
			Entity <int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			Assert::AreEqual(3, tree.size());
            Assert::AreEqual(string("Hi"), tree.get(5));
		}

		TEST_METHOD(TestGetNumber)
		{
			Entity <int, int> tree;
			tree.put(5, 7);
			tree.put(9, 6);
			tree.put(3, 5);
			tree.put(7, 4);
			tree.put(1, 1);
			tree.put(8, 2);
			int nullValue = tree.get(10);
			Assert::AreEqual(0, tree.get(10));
		}

		TEST_METHOD(TestGetNonExistentKey)
		{
			Entity <int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");

			tree.get(7); 
			string& nullValue = tree.get(7); 
			Assert::AreEqual(string(""), nullValue);
            
		}

		TEST_METHOD(TestGetAfterClear)
		{
			Entity<int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			tree.clear();
			string& nullValue = tree.get(1);
			Assert::AreEqual(string(""), nullValue);
		}
		
		//Testing collectKeys function
		TEST_METHOD(TestCollectKeys)
		{
			Entity<int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			BinaryTree<int> keys = tree.keySet();
			Assert::AreEqual(3, keys.count());
		}
		TEST_METHOD(TestClearCollectKeys)
		{
			Entity<int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			BinaryTree<int> keys = tree.keySet();
			Assert::AreEqual(3, keys.count());
			keys.clear();
			Assert::AreEqual(0, keys.count());
		}

		//Testing removeKey function
		TEST_METHOD(TestRemoveKey)
		{
			Entity<int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			Assert::AreEqual(3, tree.size());
			tree.removeKey(1);
			Assert::AreEqual(2, tree.size());
		}

		TEST_METHOD(TestNoTreeRemoveKey)
		{
			Entity<int, string> tree;
			Assert::AreEqual(0, tree.size());
			tree.removeKey(1);
			Assert::AreEqual(0, tree.size());
		}

		TEST_METHOD(TestNonExistentKey)
		{
			Entity<int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			Assert::AreEqual(3, tree.size());
			tree.removeKey(7);
			Assert::AreEqual(3, tree.size());
		}

		//Test Operatro funtionality
		TEST_METHOD(TestOperatorModifyKey)
		{
			Entity<int, string> tree;
			tree.put(1, "Hello");
			tree.put(3, "Bye");
			tree.put(5, "Hi");
			Assert::AreEqual(3, tree.size());
			Assert::AreEqual(string("Hi"), tree[5]);
			tree[5] = "Goodbye";
			Assert::AreEqual(string("Goodbye"), tree[5]);
		}
		
	};
}