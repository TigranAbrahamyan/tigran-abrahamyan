#include <iostream>
#include "./linked_list.hpp"

int main() {
  LinkedList<int> list;
  list.add(5);
  list.add(20);
  list.add(789);
  list.add(345);
  list.add(30);
  list.addAtIndex(1, 10);
  std::cout << list << std::endl;
  std::cout << "Size: " << list.getSize() << std::endl;
  list.removeAtIndex(3);
  list.remove(345);
  std::cout << list << std::endl;
  std::cout << "Size: " << list.getSize() << std::endl;

  return 0;
}
