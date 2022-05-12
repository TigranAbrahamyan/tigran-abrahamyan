#include "./separate_chaining_hash_table.hpp"

int main() {
  HashTable table;
  table.insert("John Smith", "123-456");
  table.insert("Smith John", "456-123");
  table.insert("Yandex Alica", "7-777-777-777");
  table.remove("John Smith");
  table.printTable();
  cout << table.search("Yandex Alica") << endl;
  cout << table.search("Yandex") << endl;

  return 0;
}
