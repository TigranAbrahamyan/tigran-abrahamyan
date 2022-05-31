#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <string>

using namespace std;

class Database {
  private:
    string _name;
    static Database* instance;
    Database(string);

  public:
    static Database* getInstance(string);
    string getName();
};

Database* Database::instance = NULL;

Database::Database(string name) {
  _name = name;
}

Database* Database::getInstance(string name) {
  if (!instance) {
    instance = new Database(name);
  }

  return instance;
}

string Database::getName() {
  return _name;
}

#endif
