#include "SingleLinkedList.h"

template <class T>
void SingleLinkedList<T>::append(T val){
    ListNode<T> *ptr = head;

    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }

    ptr->next = new ListNode<T>(val);
}

template <class T>
void SingleLinkedList<T>::prepend(T val) {
    ListNode<T> *newNode = new ListNode<T>(val);
    newNode->next = head->next;
    head->next = newNode;
}


template <class T>
T SingleLinkedList<T>::size() const {
    T count = 0;
    ListNode<T> *ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
        count++;
    }

    return count;
}

template <class T>
void SingleLinkedList<T>::clear() {
    ListNode<T>* ptr = head->next;
    while (ptr != nullptr) {
        ListNode<T>* curr = ptr;
        ptr = ptr->next;
        delete curr;
    }
    head->next = nullptr;
}

template <class T>
std::vector<T> SingleLinkedList<T>::toVector() const {
    std::vector<T> output;
    for (ListNode<T> *ptr = head->next; ptr != nullptr; ptr = ptr->next) {
        output.push_back(ptr->val);
    }
    return output;
}

template <class T>
bool SingleLinkedList<T>::equal(SingleLinkedList &otherList) {
    auto it = begin(), otherIt = otherList.begin();
    while (it != end() && otherIt != otherList.end()) {
        if (*it != *otherIt) {
            return false;
        }
        it++;
        otherIt++;
    }

    return it == end() && otherIt == otherList.end();
}

template <class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList &list) {
    // NOT IMPLEMENTED
}

template <class T>
void SingleLinkedList<T>::popHead() {
    ListNode<T>* ptr = head->next;
    if (ptr != nullptr) {
        head->next = ptr->next;
        delete ptr;
    }
    return;
}

template <class T>
void SingleLinkedList<T>::popTail() {
    auto p0 = head, p1 = head->next;

    // move both p0 and p1 forward until p1 is the last element or nullptr
    while (p1 != nullptr && p1->next != nullptr) {
        p1 = p1->next;
        p0 = p0->next;
    }

    if (p1 != nullptr) {
        p0->next = nullptr;
        delete p1;
    }
}

template <class T>
SingleLinkedList<T>::Iterator::Iterator(ListNode<T> *currNode) : m_currNode(currNode) {}

/*
 * Removes from the container all the elements that compare equal to val
 */
template <class T>
bool SingleLinkedList<T>::remove(T val) {
    // NOT IMPLEMENTED
    return false;
}

template <class T>
typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::erase(SingleLinkedList<T>::Iterator it) {
    for (auto ptr = head; it != Iterator(nullptr) && ptr->next != nullptr;) {
        if (Iterator(ptr->next) == it) {
            auto newNext = ptr->next->next;
            delete ptr->next;
            ptr->next = newNext;
            return Iterator(newNext);
        } else {
            ptr = ptr->next;
        }

    }
    return SingleLinkedList<T>::Iterator(nullptr);
}


