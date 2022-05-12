// -------separate_chaining_hash_table-------
#include "./separate_chaining_hash_table.hpp"

int main() {
  HashTable table;
  table.insert("John Smith", "123-456");
  table.insert("Smith John", "456-123");
  table.insert("Smith John", "456-123");
  table.insert("Smith John", "456-123");
  table.insert("Yandex Alica", "7-777-777-777");
  table.insert("Alica Yandex", "7-777-777-777");
  table.insert("Alica Yandex", "7-777-777-777");
  table.insert("Alica Yandex", "7-777-777-777");
  table.remove("John Smith");
  table.remove("Smith John");
  table.remove("Smith John");
  table.remove("Alica Yandex");
  table.printTable();
  cout << table.search("Yandex Alica") << endl;
  cout << table.search("Yandex") << endl;

  return 0;
}
// -------separate_chaining_hash_table-------

// -------open_addressing_hash_table-------
// #include "./open_addressing_hash_table.hpp"

// int main() {
//   HashTable table;
//   table.insert("John Smith", "123-456");
//   table.insert("Smith John", "456-123");
//   table.insert("Smith John", "456-123");
//   table.insert("Smith John", "456-123");
//   table.insert("Yandex Alica", "7-777-777-777");
//   table.insert("Alica Yandex", "7-777-777-777");
//   table.insert("Alica Yandex", "7-777-777-777");
//   table.insert("Alica Yandex", "7-777-777-777");
//   table.remove("John Smith");
//   table.remove("Smith John");
//   table.remove("Smith John");
//   table.remove("Alica Yandex");
//   table.printTable();
//   cout << table.search("Yandex Alica") << endl;
//   cout << table.search("Yandex") << endl;

//   return 0;
// }
// -------open_addressing_hash_table-------
