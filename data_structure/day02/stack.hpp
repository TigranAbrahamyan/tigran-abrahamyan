#ifndef STACK_H
#define STACK_H

#include "../day01/linked_list.hpp"

template<typename T>
class Stack {
  private:
    LinkedList<T> _list;

  public:
    void pushBack(T);
    T popBack();
    T peek();
    bool isEmpty();
};

template<typename T>
void Stack<T>::pushBack(T data) {
  _list.add(data);
}

template<typename T>
T Stack<T>::popBack() {
  T last = peek();
  _list.removeAtIndex(_list.getSize() - 1);
  return last;
}

template<typename T>
T Stack<T>::peek() {
  return _list.getDataByIndex(_list.getSize() - 1);
}

template<typename T>
bool Stack<T>::isEmpty() {
  return _list.isEmpty();
}

#endif
