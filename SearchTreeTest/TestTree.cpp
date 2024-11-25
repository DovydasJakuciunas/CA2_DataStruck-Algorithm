
#include "CppUnitTest.h"
#include "../CA2-SearchTree/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchTreeTest
{
	TEST_CLASS(TestTree)
	{
	public:
		
		TEST_METHOD(TestAddingElementsIntoTree)
		{
			BinaryTree<int> tree;
			
			Assert::AreEqual(5, tree.root->getItem());
		}
	};
}
