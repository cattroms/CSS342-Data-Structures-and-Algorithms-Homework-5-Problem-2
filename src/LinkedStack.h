#ifndef STACK_LINKEDSTACK_H
#define STACK_LINKEDSTACK_H

#include "Stack.h"
#include <cassert>
#include "SingleLinkedList.h"

template<class T>
class LinkedStack : public Stack<T> {
private:
    SingleLinkedList<T> *items;
public:
    LinkedStack();

    LinkedStack(LinkedStack &);

    virtual ~LinkedStack();

    bool isEmpty() const override;

    bool push(const T &) override;

    bool pop() override;

    T peek() const override;
};

template<class T>
bool LinkedStack<T>::isEmpty() const {
    return items->begin() == items->end();
}

template<class T>
bool LinkedStack<T>::push(const T &val) {
    items->prepend(val);
    return true;
}

template<class T>
bool LinkedStack<T>::pop() {
    items->popHead();
    return true;
}

template<class T>
T LinkedStack<T>::peek() const {
    assert(!isEmpty());
    return *(items->begin());
}

template<class T>
LinkedStack<T>::LinkedStack(LinkedStack<T> &anotherStack) {
    items = new SingleLinkedList<T>();
    for (auto it = anotherStack.items->begin(); it != anotherStack.items->end(); it++) {
        items->append(*it);
    }
}

template<class T>
LinkedStack<T>::LinkedStack() {
    items = new SingleLinkedList<T>();
}

template<class T>
LinkedStack<T>::~LinkedStack() {
    delete items;
}

#endif //STACK_LINKEDSTACK_H
