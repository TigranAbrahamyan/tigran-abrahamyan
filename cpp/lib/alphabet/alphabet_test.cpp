#include <iostream>
#include "alphabet.h"

using namespace std;

int main() {
  cout << "====================" << endl;
  cout << "is upper('a'): " << isUpper('a') << endl;
  cout << "is upper('A'): " << isUpper('A') << endl;
  cout << "====================" << endl;
  cout << "is lower('b'): " << isLower('b') << endl;
  cout << "is lower('B'): " << isLower('B') << endl;
  cout << "====================" << endl;
  cout << "is alpha('5'): " << isAlpha('5') << endl;
  cout << "is alpha('c'): " << isAlpha('c') << endl;
  cout << "====================" << endl;
  cout << "to upper('a'): " << toUpper('a') << endl;
  cout << "to lower('A'): " << toLower('A') << endl;
  cout << "====================" << endl;
  cout << "str to upper('FoO bOo'): " << strToUpper("FoO bOo") << endl;
  cout << "str to lower('FoO bOo'): " << strToLower("FoO bOo") << endl;
  cout << "====================" << endl;

  return 0;
}
