#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_

#include "ListNode.h"
#include <vector>

template <class T>
class SingleLinkedList {
private:
    ListNode<T> *head;
public:
    SingleLinkedList() {
        head = new ListNode<T>();
    }

    // copy constructor
    SingleLinkedList(SingleLinkedList &list);

    ~SingleLinkedList() {
        clear();
        delete head;
    }

    std::vector<T> toVector() const;
    bool equal(SingleLinkedList &);
    T size() const;

    // add a node
    void append(T);
    void prepend(T);

    // remove an end
    void popHead();
    void popTail();

    // remove node(s)
    bool remove(T val);
    void clear();

    class Iterator {
    private:
        ListNode<T> *m_currNode;
    public:
        Iterator(ListNode<T> *);

        Iterator &operator++() {
            if (m_currNode != nullptr) {
                m_currNode = m_currNode->next;
            }

            return *this;
        }

        Iterator operator++(int) {
            Iterator it(*this);
            operator++();
            return it;
        }

        T operator*() {
            return m_currNode->val;
        }

        bool operator!=(const Iterator &it) {
            return m_currNode != it.m_currNode;
        }

        bool operator==(const Iterator &it) {
            return m_currNode == it.m_currNode;
        }

    };

    Iterator erase(Iterator);

    Iterator erase(Iterator, Iterator);

    Iterator begin() {
        return Iterator(head->next);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator tail() {
        if (head->next == nullptr) {
            return end();
        }

        ListNode<T> *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return Iterator(ptr);
    }
};

#include "SingleLinkedList.cpp"

#endif
