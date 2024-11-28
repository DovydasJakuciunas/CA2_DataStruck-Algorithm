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
			Entity<int, int> tree(1, 1);
			Assert::IsTrue(1, )
		}
	};
}