#ifndef QUEUE_FROM_STACK_H
#define QUEUE_FROM_STACK_H

#include "./stack.hpp"

template<typename T>
class QueueFromStack {
  private:
    Stack<T> firstStack;
    Stack<T> secondStack;

  public:
    void pushBack(T);
    T popFront();
    T peek();
};

template<typename T>
void QueueFromStack<T>::pushBack(T data) {
  firstStack.pushBack(data);
}

template<typename T>
T QueueFromStack<T>::popFront() {
  while (!firstStack.isEmpty()) {
    secondStack.pushBack(firstStack.popBack());
  }

  T removed = secondStack.popBack();

  while (!secondStack.isEmpty()) {
    firstStack.pushBack(secondStack.popBack());
  }

  return removed;
}

template<typename T>
T QueueFromStack<T>::peek() {
  while (!firstStack.isEmpty()) {
    secondStack.pushBack(firstStack.popBack());
  }

  T first = secondStack.peek();

  while (!secondStack.isEmpty()) {
    firstStack.pushBack(secondStack.popBack());
  }

  return first;
}

#endif
