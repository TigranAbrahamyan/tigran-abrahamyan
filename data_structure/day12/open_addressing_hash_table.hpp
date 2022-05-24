#ifndef OPEN_ADDRESSING_HASH_TABLE_H
#define OPEN_ADDRESSING_HASH_TABLE_H

#include <iostream>
#include <string>

using namespace std;

#define DEFAULT_CAPACITY 10

class Table {
  public:
    string _key;
    string _value;

    Table(string key, string value) {
      _key = key;
      _value = value;
    }
};

class HashTable {
  private:
    Table** _table;
    int _capacity;

    int hashFunction(string);
    void resize();
    void rehash();
    int getLastPosition();

  public:
    HashTable();
    void insert(string, string);
    void remove(string);
    string search(string);
    void printTable();
};

HashTable::HashTable() {
  _capacity = DEFAULT_CAPACITY;
  _table = new Table*[_capacity];

  for (int i = 0; i < _capacity; i++) {
    _table[i] = NULL;
  }
}

int HashTable::hashFunction(string key) {
  int result = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    result += key[i];
  }

  return result % _capacity;
}

void HashTable::resize() {
  _capacity *= 2;
  Table** temp = new Table*[_capacity];

  for (int i = 0; i < _capacity; i++) {
    temp[i] = NULL;
  }

  for (int i = 0; i < _capacity / 2; i++) {
    temp[i] = _table[i];
  }

  _table = temp;
}

void HashTable::rehash() {
  _capacity /= 2;
  Table** temp = new Table*[_capacity];

  for (int i = 0; i < _capacity; i++) {
    temp[i] = NULL;
  }

  for (int i = 0; i < _capacity; i++) {
    temp[i] = _table[i];
  }

  _table = temp;
}

int HashTable::getLastPosition() {
  for (int i = _capacity - 1; i >= 0; i--) {
    if (_table[i]) {
      return i;
    }
  }

  return -1;
}

void HashTable::insert(string key, string value) {
  int position = hashFunction(key);

  if (_table[position]) {
    while (_table[position]) {
      position++;
      if (position >= _capacity) {
        resize();
      }
    }

    _table[position] = new Table(key, value);
  } else {
    _table[position] = new Table(key, value);
  }
}

void HashTable::remove(string key) {
  int position = hashFunction(key);

  for (int i = position; i < _capacity; i++) {
    if (_table[i] && _table[i]->_key == key) {
      _table[i] = NULL;
      break;
    }
  }

  if (getLastPosition() < _capacity / 2 && _capacity != DEFAULT_CAPACITY) {
    rehash();
  }
}

string HashTable::search(string key) {
  int position = hashFunction(key);

  if (_table[position] && _table[position]->_key == key) {
    while (_table[position]) {
      if (_table[position]->_key == key) {
        return _table[position]->_value;
      }

      position++;
    }
  }

  return "Key '" + key + "' not found";
}

void HashTable::printTable() {
  for (int i = 0; i < _capacity; i++) {
    cout << "[" << i << "]: ";
    if (_table[i]) {
      cout << "[" << _table[i]->_key << ", " << _table[i]->_value << "] ";
    }
    cout << endl;
  }
}

#endif
