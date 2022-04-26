#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template<typename T>
struct Node {
  T _data;
  Node<T>* _next;

  Node(T data, Node<T>* next = NULL) {
    _data = data;
    _next = next;
  }
};

template<typename T>
class LinkedList {
  private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;
    Node<T>* getNodeByIndex(int);

  public:
    LinkedList();
    ~LinkedList();

    void add(T);
    void addAtIndex(int, T);
    void remove(T);
    void removeAtIndex(int);
    void removeAll();
    T getDataByIndex(int);
    int getSize() const;
    bool isEmpty();

    template<typename Out>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<Out>&);
};

template<typename T>
LinkedList<T>::LinkedList() {
  _head = NULL;
  _tail = NULL;
  _size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
  removeAll();
  _head = NULL;
  _tail = NULL;
}

template<typename T>
void LinkedList<T>::add(T data) {
  Node<T>* node = new Node<T>(data);

  if (_head == NULL) {
    _head = _tail = node;
  } else {
    _tail->_next = node;
    _tail = node;
  }

	_size++;
}

template<typename T>
void LinkedList<T>::addAtIndex(int index, T data) {
  if (index < 0 || index > _size) {
    throw std::runtime_error("Index out of range");
  }

  Node<T>* node = new Node<T>(data);

  if (index == 0) {
    node->_next = _head;
    _head = node;
  } else {
    Node<T>* prev = getNodeByIndex(index - 1);
    node->_next = prev->_next;
    prev->_next = node;
  }

  if (_tail == NULL) {
    _tail = node;
  }

	_size++;
}

template<typename T>
void LinkedList<T>::remove(T data) {
  if (_head == NULL) {
    throw std::runtime_error("Head is null");
  }

  Node<T>* current = _head;
  bool isFound = false;

  while (current != NULL && !isFound) {
    if (current->_next->_data == data) {
      if (_tail->_data == data) {
        _tail = current;
      }

      isFound = true;
      Node<T>* temp = current->_next;
      current->_next = current->_next->_next;
      delete temp;
    } else {
      current = current->_next;
    }
  }

  if (isFound) {
    _size--;
  } else {
    throw std::runtime_error("Element not found");
  }
}

template<typename T>
void LinkedList<T>::removeAtIndex(int index) {
  Node<T>* temp = _head;

  if (index == 0) {
    _head = _head->_next;
    delete temp;
  } else {
    Node<T>* prev = getNodeByIndex(index - 1);
    temp = prev->_next;
    prev->_next = prev->_next->_next;
    delete temp;

    if (index == _size) {
      _tail = prev;
    }
  }

  _size--;
}

template<typename T>
void LinkedList<T>::removeAll() {
  while (_size - 1 > 0) {
    removeAtIndex(_size);
  }
}

template<typename T>
Node<T>* LinkedList<T>::getNodeByIndex(int index) {
  if (_head == NULL) {
    throw std::runtime_error("Head is null");
  }

  if (index < 0 || index > _size) {
    throw std::runtime_error("Index out of range");
  }

  Node<T>* current = _head;
  int count = 0;

  while (current && count != index) {
    current = current->_next;
    count++;
  }

  return current;
}

template<typename T>
T LinkedList<T>::getDataByIndex(int index) {
  return getNodeByIndex(index)->_data;
}

template<typename T>
int LinkedList<T>::getSize() const {
  return _size;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
  return getSize() == 0;
}

template<typename T>
std::ostream& operator<<(std::ostream &out, const LinkedList<T>& list) {
  Node<T>* current = list._head;

  out << "[";
  while (current) {
    out << current->_data;

    if (current->_next) {
      out << ", ";
    }

    current = current->_next;
  }
  out << "]";

  return out;
}

#endif
