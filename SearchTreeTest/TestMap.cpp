#include <iostream>

#include "CppUnitTest.h"
#include "../CA2-SearchTree/Entity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestMap
{
	TEST_CLASS(TestEntity)
	{
	public:
		//Testing to see if the constructor works
		TEST_METHOD(TestConstructor)
		{
			Entity <int, int> tree;
			tree.add(1, 2);
			Assert::AreEqual(1, tree.count());
		}
		TEST_METHOD(TestEmptyConstructor)
		{
			Entity <int, int> tree;
			Assert::AreEqual(0, tree.count());
		}
		TEST_METHOD(TestMultipleConstructor)
		{
			Entity <int, int> tree;
			tree.add(1, 3);
			tree.add(3, 2);
			tree.add(5, 1);
			Assert::AreEqual(3, tree.count());

		}

		//Teststing clear function
		TEST_METHOD(TestClear)
		{
			Entity <int, int> tree;
			tree.add(1, 2);
			tree.add(3, 3);
			tree.add(5, 1);
			Assert::AreEqual(3, tree.count());
			tree.clear();
			Assert::AreEqual(0, tree.count());
		}

		//Testing containsKey functions
		TEST_METHOD(TestContainsKey)
		{
			Entity <int, int> tree;
			tree.add(1, 3);
			tree.add(3, 2);
			tree.add(5, 1);
			Assert::AreEqual(3, tree.count());
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
			tree.add(5, 7);
			tree.add(9, 6);
			tree.add(3, 5);
			tree.add(7, 4);
			tree.add(1, 1);
			tree.add(8, 2);
			Assert::AreEqual(6, tree.count());
			Assert::IsTrue(tree.containsKey(7));
		}

		//Testing getting functions
		TEST_METHOD(TestGetWord)
		{
			Entity <int, string> tree;
			tree.add(1, "Hello");
			tree.add(3, "Bye");
			tree.add(5, "Hi");
			Assert::AreEqual(3, tree.count());
            Assert::AreEqual(string("Hi"), tree.get(5));
		}

		TEST_METHOD(TestGetNumber)
		{
			Entity <int, int> tree;
			tree.add(5, 7);
			tree.add(9, 6);
			tree.add(3, 5);
			tree.add(7, 4);
			tree.add(1, 1);
			tree.add(8, 2);
			int nullValue = tree.get(10);
			Assert::AreEqual(0, tree.get(10));
		}

		TEST_METHOD(TestGetNonExistentKey)
		{
			Entity <int, string> tree;
			tree.add(1, "Hello");
			tree.add(3, "Bye");
			tree.add(5, "Hi");

			tree.get(7); 
			string& nullValue = tree.get(7); 
			Assert::AreEqual(string(""), nullValue);
            
		}

		TEST_METHOD(TestGetAfterClear)
		{
			Entity<int, string> tree;
			tree.add(1, "Hello");
			tree.add(3, "Bye");
			tree.add(5, "Hi");
			tree.clear();
			string& nullValue = tree.get(1);
			Assert::AreEqual(string(""), nullValue);
		}
		
	};
}