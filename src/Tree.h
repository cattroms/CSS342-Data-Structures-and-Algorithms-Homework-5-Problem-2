#pragma once

#include <vector>

template<class T>
class Tree {
public:
    virtual bool add(const T &) = 0;
    virtual bool remove(const T &) = 0;
    virtual int height() = 0;
    virtual bool contains(T val) = 0;

    virtual std::vector<T> traverseInOrder() = 0;
    virtual std::vector<T> traversePreOrder() = 0;
    virtual std::vector<T> traversePostOrder() = 0;

    virtual ~Tree() {};
};
