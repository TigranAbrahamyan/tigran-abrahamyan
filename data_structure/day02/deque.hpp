#ifndef DEQUE_H
#define DEQUE_H

#include "../day01/linked_list.hpp"

template<typename T>
class Deque {
  private:
    LinkedList<T> _list;

  public:
    void pushFront(T);
    T popFront();

    void pushBack(T);
    T popBack();

    T getLast();
    T getFirst();
};

template<typename T>
void Deque<T>::pushFront(T data) {
  _list.addAtIndex(0, data);
}

template<typename T>
T Deque<T>::popFront() {
  T first = getFirst();
  _list.removeAtIndex(0);
  return first;
}

template<typename T>
void Deque<T>::pushBack(T data) {
  _list.add(data);
}

template<typename T>
T Deque<T>::popBack() {
  T last = getLast();
  _list.removeAtIndex(_list.getSize() - 1);
  return last;
}

template<typename T>
T Deque<T>::getLast() {
  return _list.getDataByIndex(_list.getSize() - 1);
}

template<typename T>
T Deque<T>::getFirst() {
  return _list.getDataByIndex(0);
}

#endif
