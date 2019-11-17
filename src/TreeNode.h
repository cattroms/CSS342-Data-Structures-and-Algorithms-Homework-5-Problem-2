#pragma once

template <class T> class BinaryTree;

template <class T>
class TreeNode {
    friend class BinaryTree<T>;
private:
    T val;
    TreeNode<T> * left;
    TreeNode<T> * right;

public:
    TreeNode() : left(nullptr), right(nullptr) {
    }

    TreeNode(T val) : TreeNode() {
        this->val = val;
    }

    void setLeft(TreeNode<T> *left) {
        this->left = left;
    }

    void setRight(TreeNode<T> *right) {
        this->right = right;
    }

    TreeNode *getLeft() const {
        return left;
    }

    TreeNode *getRight() const {
        return right;
    }
};
