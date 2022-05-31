#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <vector>
using namespace std;

class Iterator;
class ConcreteIterator;

class Aggregate {
  public:
    virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
  private:
    vector<string> _elements;

  public:
    Iterator* createIterator();

    int size() {
      return _elements.size();
    }

    void add(string value) {
      _elements.push_back(value);
    }

    string get(int index) {
      return _elements.at(index);
    }
};

class Iterator {
  public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual string currentItem() = 0;
};

class ConcreteIterator : public Iterator {
  private:
    ConcreteAggregate* _aggregate;
    int _currentElement;

  public:
    ConcreteIterator(ConcreteAggregate* aggregate) {
      _aggregate = aggregate;
      _currentElement = 0;
    }

    void first() override {
      _currentElement = 0;
    }

    void next() override {
      _currentElement++;
    }

    bool isDone() override {
      return _currentElement >= _aggregate->size();
    }

    string currentItem() override {
      return _aggregate->get(_currentElement);
    }
};

Iterator* ConcreteAggregate::createIterator() {
  return new ConcreteIterator(this);
}

#endif
