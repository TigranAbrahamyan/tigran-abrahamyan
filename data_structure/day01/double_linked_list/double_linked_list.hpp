#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

template<typename T>
struct Node {
  T _data;
  Node<T>* _next;
  Node<T>* _prev;

  Node(T data, Node<T>* next = NULL, Node<T>* prev = NULL) {
    _data = data;
    _next = next;
    _prev = prev;
  }
};

template<typename T>
class DoubleLinkedList {
  private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void add(T);
    void addAtIndex(int, T);
    void removeHead();
    void removeTail();
    void remove(T);
    void removeAtIndex(int);
    void removeAll();
    Node<T>* findNode(T);
    Node<T>* getNodeByIndex(int);
    T getDataByIndex(int);
    int getSize() const;
    bool isEmpty();

    template<typename Out>
    friend std::ostream& operator<<(std::ostream&, const DoubleLinkedList<Out>&);
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
  _head = NULL;
  _tail = NULL;
  _size = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  removeAll();
  _head = NULL;
  _tail = NULL;
}

template<typename T>
void DoubleLinkedList<T>::add(T data) {
  Node<T>* node = new Node<T>(data);

  if (!_head) {
    _head = node;
    _tail = node;
  } else {
    _tail->_next = node;
    node->_prev = _tail;
    _tail = node;
  }

  _size++;
}

template<typename T>
void DoubleLinkedList<T>::addAtIndex(int index, T data) {
  if (index < 0 || index > _size) {
    throw std::invalid_argument("Index out of range");
  }

  Node<T>* node = new Node<T>(data);

  if (!_head && !_tail) {
    _head = node;
    _tail = node;
  } else if (index == 0) {
    node->_next = _head;
    _head->_prev = node;
    _head = node;
  } else {
    Node<T>* prev = getNodeByIndex(index)->_prev;
    node->_next = prev->_next;
    node->_prev = prev;
    prev->_next = node;
    if (node->_next->_prev) {
      node->_next->_prev = node;
    }
  }

  _size++;
}

template<typename T>
void DoubleLinkedList<T>::removeHead() {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  Node<T>* temp = _head;
  _head = _head->_next;
  _size--;
  delete temp;

  if (_head) {
    _head->_prev = NULL;
  } else {
    _tail = NULL;
  }
}

template<typename T>
void DoubleLinkedList<T>::removeTail() {
  if (!_head) {
    throw std::runtime_error("List is null");
  }

  Node<T>* temp = _tail;
  _tail = _tail->_prev;
  _tail->_next = NULL;
  _size--;
  delete temp;
}

template<typename T>
void DoubleLinkedList<T>::remove(T data) {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  if (_head->_data == data) {
    removeHead();
  } else if (_tail->_data == data) {
    removeTail();
  } else {
    Node<T>* current = _head;
    bool isFound = false;

    while (current && !isFound) {
      if (current->_next->_data == data) {
        Node<T>* temp = current->_next;
        current->_next = current->_next->_next;
        current->_next->_prev = current;
        isFound = true;
        delete temp;
      } else {
        current = current->_next;
      }
    }

    if (isFound) {
      _size--;
    } else {
      throw std::invalid_argument("Element not found");
    }
  }
}

template<typename T>
void DoubleLinkedList<T>::removeAtIndex(int index) {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  if (index == 0) {
    removeHead();
  } else if (index == _size - 1) {
    removeTail();
  } else {
    Node<T>* prev = getNodeByIndex(index)->_prev;
    Node<T>* temp = prev->_next;
    prev->_next = prev->_next->_next;
    prev->_next->_prev = prev;
    _size--;
    delete temp;
  }
}

template<typename T>
void DoubleLinkedList<T>::removeAll() {
  while (_size) {
    removeHead();
  }
}

template<typename T>
Node<T>* DoubleLinkedList<T>::findNode(T data) {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  Node<T>* current = _head;

  while (current && current->_data != data) {
    current = current->_next;
  }

  return current;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::getNodeByIndex(int index) {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  if (index < 0 || index > _size) {
    throw std::invalid_argument("Index out of range");
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
T DoubleLinkedList<T>::getDataByIndex(int index) {
  return getNodeByIndex(index)->_data;
}

template<typename T>
int DoubleLinkedList<T>::getSize() const {
  return _size;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
  return _size == 0;
}

template<typename T>
std::ostream& operator<<(std::ostream &out, const DoubleLinkedList<T>& list) {
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
  out << std::endl;

  return out;
}

#endif
