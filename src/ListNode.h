#pragma once

template <class T> class SingleLinkedList;

template <class T>
class ListNode {
    friend class SingleLinkedList<T>;
private:
    T val;
    ListNode * next;

public:
    // val(0) to make valgrind happy
    ListNode() : next(nullptr) {
    }

    ListNode(T val) : val(val), next(nullptr) {}
};
