#include "./iterator.hpp"

int main() {
  ConcreteAggregate* aggregate = new ConcreteAggregate();
  aggregate->add("AAA");
  aggregate->add("BBB");
  aggregate->add("CCC");

  Iterator* iterator = aggregate->createIterator();
  for (iterator->first(); !(iterator->isDone()); iterator->next()) {
    cout << "Element = " << iterator->currentItem() << endl;
  }

  return 0;
}
