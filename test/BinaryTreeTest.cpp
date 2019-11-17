#include "BinaryTree.h"
#include "gtest/gtest.h"



TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

	BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(tree, destructor) {
	// Destructor test, creates a tree and lets system call destructor
	TreeNode<int>* test = new TreeNode<int>(3);
	test->setLeft(new TreeNode<int>(1));
	test->setRight(new TreeNode<int>(5));

	test->getLeft()->setLeft(new TreeNode<int>(2));
	test->getLeft()->setRight(new TreeNode<int>(7));

	test->getRight()->setLeft(new TreeNode<int>(5));

	BinaryTree<int> destructorTree(test);
}

TEST(tree, in_order_iteratively) {
	// In order test, creates a tree, and tests the in_order vector with a hard coded answer

	TreeNode<int>* root = new TreeNode<int>(3);
	root->setLeft(new TreeNode<int>(1));
	root->setRight(new TreeNode<int>(5));

	root->getLeft()->setLeft(new TreeNode<int>(2));
	root->getLeft()->setRight(new TreeNode<int>(7));

	root->getRight()->setLeft(new TreeNode<int>(5));

	BinaryTree<int> tree(root);

	std::vector<int> result = tree.traverseInOrder();
	std::vector<int> answer;
	answer.push_back(2);
	answer.push_back(1);
	answer.push_back(7);
	answer.push_back(3);
	answer.push_back(5);
	answer.push_back(5);

	ASSERT_EQ(result, answer);
}


TEST(tree, post_order_iteratively) {
	// Post order test, creates a tree, and tests the post_order vector with a hard coded answer
	TreeNode<int>* root = new TreeNode<int>(3);
	root->setLeft(new TreeNode<int>(1));
	root->setRight(new TreeNode<int>(5));

	root->getLeft()->setLeft(new TreeNode<int>(2));
	root->getLeft()->setRight(new TreeNode<int>(7));

	root->getRight()->setLeft(new TreeNode<int>(5));

	BinaryTree<int> tree(root);

	std::vector<int> result = tree.traversePostOrder();
	std::vector<int> answer;
	answer.push_back(2);
	answer.push_back(7);
	answer.push_back(1);
	answer.push_back(5);
	answer.push_back(5);
	answer.push_back(3);

	ASSERT_EQ(result, answer);
}


TEST(tree, LCA) {
	// LCA test, creates the given example tree, and asserts that the LCA matches the provided example solutions
	TreeNode<int>* root = new TreeNode<int>(4);
	root->setLeft(new TreeNode<int>(8));
	root->setRight(new TreeNode<int>(6));

	root->getLeft()->setLeft(new TreeNode<int>(7));
	root->getLeft()->setRight(new TreeNode<int>(3));

	root->getRight()->setLeft(new TreeNode<int>(2));
	root->getRight()->setRight(new TreeNode<int>(9));

	BinaryTree<int> tree(root);
	
	ASSERT_EQ(tree.LCA(4,4), 4);
	ASSERT_EQ(tree.LCA(7, 7), 7);
	ASSERT_EQ(tree.LCA(7, 3), 8);
	ASSERT_EQ(tree.LCA(7, 8), 8);
	ASSERT_EQ(tree.LCA(8, 6), 4);
	ASSERT_EQ(tree.LCA(3, 2), 4);
}


