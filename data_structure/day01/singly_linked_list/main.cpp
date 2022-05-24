#include "./singly_linked_list.hpp"

int main() {
  SinglyLinkedList<int> list;
  list.add(5);
  list.add(20);
  list.add(789);
  list.add(345);
  list.add(30);
  list.add(100);
  list.add(50);
  list.add(80);
  list.add(90);
  list.addAtIndex(0, 10);
  list.add(1005);
  std::cout << "Size: " << list.getSize() << std::endl;
  std::cout << list << std::endl;
  list.removeAtIndex(0);
  list.removeAtIndex(5);
  list.remove(30);
  list.remove(345);
  list.removeAtIndex(1);
  list.removeAtIndex(list.getSize() - 1);
  list.removeAtIndex(list.getSize() - 1);
  std::cout << "Size: " << list.getSize() << std::endl;
  std::cout << list << std::endl;
  list.removeHead();
  std::cout << "Size: " << list.getSize() << std::endl;
  std::cout << list << std::endl;
  list.removeTail();
  std::cout << "Size: " << list.getSize() << std::endl;
  std::cout << list << std::endl;

  return 0;
}
