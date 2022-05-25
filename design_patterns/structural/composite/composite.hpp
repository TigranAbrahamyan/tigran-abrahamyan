#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <vector>

using namespace std;

class Component {
  public:
    virtual void traverse() = 0;
};

class Leaf : public Component {
  private:
    int _value;

  public:
    Leaf(int value) {
      _value = value;
    }

    void traverse() {
      cout << _value << " ";
    }
};

class Composite : public Component {
  private:
    vector<Component*> childrens;

  public:
    void add(Component *component) {
      childrens.push_back(component);
    }

    void traverse() {
      for (int i = 0; i < childrens.size(); i++) {
        childrens[i]->traverse();
      }
    }
};

#endif
