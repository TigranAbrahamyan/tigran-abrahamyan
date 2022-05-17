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

  public:
    LinkedList();
    ~LinkedList();

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

  if (!_head) {
    _head = _tail = node;
  } else {
    _tail->_next = node;
    _tail = _tail->_next;
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

  if (!_tail) {
    _tail = node;
  }

	_size++;
}

template<typename T>
void LinkedList<T>::removeHead() {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  Node<T>* temp = _head;
  _head = _head->_next;
  _size--;
  delete temp;

  if (!_head) {
    _tail = NULL;
  }
}

template<typename T>
void LinkedList<T>::removeTail() {
  if (!_head) {
    throw std::runtime_error("List is null");
  }

  removeAtIndex(_size - 1);
}

template<typename T>
void LinkedList<T>::remove(T data) {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  if (_head->_data == data) {
    removeHead();
  } else {
    Node<T>* current = _head;
    bool isFound = false;

    while (current && !isFound) {
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
}

template<typename T>
void LinkedList<T>::removeAtIndex(int index) {
  if (!_head) {
    throw std::runtime_error("Head is null");
  }

  if (index == 0) {
    removeHead();
  } else {
    Node<T>* prev = getNodeByIndex(index - 1);
    Node<T>* temp = prev->_next;
    prev->_next = prev->_next->_next;
    delete temp;
    _size--;

    if (index == _size) {
      _tail = prev;
    }
  }
}

template<typename T>
void LinkedList<T>::removeAll() {
  while (_size) {
    removeHead();
  }
}

template<typename T>
Node<T>* LinkedList<T>::findNode(T data) {
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
Node<T>* LinkedList<T>::getNodeByIndex(int index) {
  if (!_head) {
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
  return _size == 0;
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
  out << std::endl;

  return out;
}

#endif
