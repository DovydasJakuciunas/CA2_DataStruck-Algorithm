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
			tree.add(1, 2);
			tree.add(3, 4);
			tree.add(5, 6);
			Assert::AreEqual(3, tree.count());

		}
        
	};
}