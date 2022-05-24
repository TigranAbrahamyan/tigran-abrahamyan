#include "./deque.hpp"

int main() {
  Deque<int>* deque = new Deque<int>();
  deque->pushFront(5);
  deque->pushBack(105);
  deque->pushFront(15);
  std::cout << "Pop front: " << deque->popFront() << std::endl;
  std::cout << "Pop back: " << deque->popBack() << std::endl;

  return 0;
}
