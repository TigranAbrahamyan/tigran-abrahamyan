#ifndef SEPARATE_CHAINING_HASH_TABLE_H
#define SEPARATE_CHAINING_HASH_TABLE_H

#include <iostream>
#include <string>

using namespace std;

#define CAPACITY 10

class LinkedTable {
  public:
    string _key;
    string _value;
    LinkedTable* _next;

    LinkedTable(string key, string value, LinkedTable *next = NULL) {
      _key = key;
      _value = value;
      _next = next;
    }
};

class HashTable {
  private:
    LinkedTable** _table;

    int hashFunction(string);

  public:
    HashTable();
    void insert(string, string);
    void remove(string);
    string search(string);
    void printTable();
};

HashTable::HashTable() {
  _table = new LinkedTable*[CAPACITY];
  for (int i = 0; i < CAPACITY; i++) {
    _table[i] = NULL;
  }
}

int HashTable::hashFunction(string key) {
  int result = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    result += key[i];
  }

  return result % CAPACITY;
}

void HashTable::insert(string key, string value) {
  int position = hashFunction(key);

  if (_table[position]) {
    LinkedTable* current = _table[position];

    while (current->_next) {
      current = current->_next;
    }

    current->_next = new LinkedTable(key, value);
  } else {
    _table[position] = new LinkedTable(key, value);
  }
}

void HashTable::remove(string key) {
  int position = hashFunction(key);
  LinkedTable* current = _table[position];

  if (!current) {
    throw invalid_argument("Key not found");
  }

  if (current->_key == key) {
    _table[position] = current->_next;
    delete current;
  } else {
    while (current) {
      if (current->_next->_key == key) {
        LinkedTable* temp = current->_next;
        current->_next = current->_next->_next;
        delete temp;
        break;
      }

      current = current->_next;
    }
  }
}

string HashTable::search(string key) {
  int position = hashFunction(key);
  LinkedTable* current = _table[position];

  while (current) {
    if (current->_key == key) {
      return current->_value;
    }

    current = current->_next;
  }

  return "Key '" + key + "' not found";
}

void HashTable::printTable() {
  for (int i = 0; i < CAPACITY; i++) {
    cout << "[" << i << "]: ";
    LinkedTable* current = _table[i];

    while (current) {
      cout << "[" << current->_key << ", " << current->_value << "] ";
      current = current->_next;
    }

    cout << endl;
  }
}

#endif
