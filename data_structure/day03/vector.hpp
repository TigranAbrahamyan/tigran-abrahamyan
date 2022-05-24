#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector {
  private:
    T *arr;
    int size;
    int capacity;

    void copyArray();

  public:
    Vector();

    void addFront(T);
    void add(T);
    void addAt(int, T);
    void removeAt(int);
    void removeAll();

    int getSize() const;
    int getCapacity() const;

    const T operator[](int index);

    template <typename Out>
    friend std::ostream&operator<<(std::ostream&, const Vector<Out>&);
};

template <typename T>
Vector<T>::Vector() {
  capacity = 4;
  size = 0;
  arr = new T[capacity];
}

template <typename T>
void Vector<T>::copyArray() {
  T *copiedArray = new T[capacity];

  for (int i = 0; i < size; i++) {
    copiedArray[i] = arr[i];
  }

  arr = copiedArray;
}

template <typename T>
void Vector<T>::add(T data) {
  addAt(getSize(), data);
}

template <typename T>
void Vector<T>::addFront(T data) {
  addAt(0, data);
}

template <typename T>
void Vector<T>::addAt(int index, T data) {
  if (index < 0 || index > getSize()) {
    throw std::runtime_error("Index out of range");
  }

  if (getSize() == getCapacity()) {
    capacity *= 2;
    copyArray();
  }

  for (int i = size; i > index; i--) {
    arr[i] = arr[i - 1];
  }

  arr[index] = data;
  size++;
}

template <typename T>
void Vector<T>::removeAt(int index) {
  if (index < 0 || index > getSize()) {
    throw std::runtime_error("Index out of range");
  }

  if (getSize() == getCapacity() && getCapacity() != 4) {
    capacity /= 2;
    copyArray();
  }

  for (int i = index; i < getSize(); i++) {
    arr[i] = arr[i + 1];
  }

  size--;
}

template <typename T>
void Vector<T>::removeAll() {
  delete[] arr;
  capacity = 4;
  size = 0;
  arr = new T[capacity];
}

template <typename T>
int Vector<T>::getSize() const {
  return size;
}

template <typename T>
int Vector<T>::getCapacity() const {
  return capacity;
}

template <typename T>
const T Vector<T>::operator[](int index) {
  return arr[index];
}

template <typename Out>
std::ostream&operator<<(std::ostream &out, const Vector<Out>& vector) {
  for (int i = 0; i < vector.getSize(); i++) {
    out << vector.arr[i] << " ";
  }

  return out;
}

#endif
