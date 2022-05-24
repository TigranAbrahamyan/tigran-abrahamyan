#ifndef QUEUE_H
#define QUEUE_H

#include "../day01/linked_list.hpp"

template<typename T>
class Queue {
  private:
    LinkedList<T> _list;

  public:
    void pushBack(T);
    T popFront();
    T peek();
    bool isEmpty();
};

template<typename T>
void Queue<T>::pushBack(T data) {
  _list.add(data);
}

template<typename T>
T Queue<T>::popFront() {
  T first = peek();
  _list.removeAtIndex(0);
  return first;
}

template<typename T>
T Queue<T>::peek() {
  return _list.getDataByIndex(0);
}

template<typename T>
bool Queue<T>::isEmpty() {
  return _list.isEmpty();
}

#endif
