#include "./singleton.hpp"

int main() {
  Database* mySQL = Database::getInstance("MySQL");
  Database* mongoDB = Database::getInstance("MongoDB");

  cout << mySQL->getName() << endl;
  cout << mongoDB->getName() << endl;

  return 0;
}
