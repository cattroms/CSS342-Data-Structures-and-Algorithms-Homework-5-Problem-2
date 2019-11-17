#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

	// helper method for tree destructor, destroys tree in preorder (root -> left -> right)
	void clearTree(TreeNode<T>* node) {
		// if the node is null, do nothing
		if (node == nullptr) {
			return;
		}	

		// temp variables to hold the left and right of soon to be deleted node
		TreeNode<T>* tempLeft = node->left;
		TreeNode<T>* tempRight = node->right;

		delete node; // deletes root first
		clearTree(tempLeft); // then goes left
		clearTree(tempRight); // then goes right
		
	}

	// helper method for LCA, modified from in class example 
	T _LCA(TreeNode <T>* node, T val1, T val2) {
		// if root is empty, return -1
		if (node == nullptr) {
			return -1;
		}

		// if the root is equal to either given value, return the root
		if (node->val == val1 || node->val == val2) {
			return node->val;
		}

		// go left and right
		T left = _LCA(node->left, val1, val2);
		T right = _LCA(node->right, val1, val2);

		// if both are found, return node
		if (left != -1 && right != -1) {
			return node->val;
		}

		// if both are not found, return -1
		if (left == -1 && right == -1) {
			return -1;
		}

		// if left is not found, return right
		if (left == -1) {
			return right;
		}

		// otherwise, return left
		return left;
	}

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

	// modified traverseInOrder from in class example
    std::vector<T> traverseInOrder() override {
		LinkedStack<TreeNode<T>*> stack;
		TreeNode<T>* current = root;
		std::vector<T> retVal;
		
		// if the provided tree is empty, return empty vector
		if (current == nullptr) {
			return retVal;
		}

		// while current has a value or stack is not empty yet
		while (current != nullptr || stack.isEmpty() == false) {

			while (current != nullptr) { // push this value to the stack and go left
				stack.push(current);
				current = current->left;
			}

			// after everything to the left has been pushed, pop it and add to the vector
			current = stack.peek();
			stack.pop();
			retVal.push_back(current->val);
			current = current->right; // then go right

		}
		return retVal;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

	// modified traversePostOrder from https://www.geeksforgeeks.org/iterative-postorder-traversal/
    std::vector<T> traversePostOrder() override {
		LinkedStack<TreeNode<T>*> stack1;
		LinkedStack<TreeNode<T>*> stack2;
		TreeNode<T>* current = root;
		std::vector<T> retVal;

		// if the provided tree is empty, return empty vector
		if (current == nullptr) {
			return retVal;
		}
	
		// push the root
		stack1.push(current);
		
		// while stack is not empty yet
		while (stack1.isEmpty() == false) {
			// pushes nodes into stack in proper order, using additional stack to reverse
			current = stack1.peek();
			stack1.pop();
			stack2.push(current);

			if (current->getLeft() != nullptr) { // now go left
				stack1.push(current->left);
			}
			if (current->getRight() != nullptr) { // now go right
				stack1.push(current->right);
			}
		}

		// take the correctly ordered stack2 and push results into returned vector
		while (stack2.isEmpty() == false) {
			current = stack2.peek();
			stack2.pop();
			retVal.push_back(current->val);
		}
		
		return retVal;

    }

	virtual ~BinaryTree() {
		// calls helper method
		clearTree(root);
	}
	
    T LCA(T node1, T node2) {
		// calls helper method
		return _LCA(root, node1, node2);
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
