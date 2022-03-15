#include <iostream>
#include "myatoi.h"

using namespace std;

int main() {
  cout << "====================" << endl;
  cout << "atoi" << endl;
  cout << "(200): " << atoi("200") << endl;                     // 200
  cout << "(5.33): " << atoi("5.33") << endl;                   // 5
  cout << "(533.123): " << atoi("533 123") << endl;             // 533
  cout << "(Hello): " << atoi("Hello") << endl;                 // 0
  cout << "(2a01): " << atoi("2a01") << endl;                   // 2
  cout << "(24a01): " << atoi("24a01") << endl;                 // 24
  cout << "(240 350 460): " << atoi("240 350 460") << endl;     // 240
  cout << "(aa55bb): " << atoi("aa55bb") << endl;               // 0
  cout << "(5a6): " << atoi("5a6") << endl;                     // 5
  cout << "====================" << endl;
  cout << "my atoi" << endl;
  cout << "(200): " << myatoi("200") << endl;                   // 200
  cout << "(5.33): " << myatoi("5.33") << endl;                 // 5
  cout << "(533.123): " << myatoi("533 123") << endl;           // 533
  cout << "(Hello): " << myatoi("Hello") << endl;               // 0
  cout << "(2a01): " << myatoi("2a01") << endl;                 // 2
  cout << "(24a01): " << myatoi("24a01") << endl;               // 24
  cout << "(240 350 460): " << myatoi("240 350 460") << endl;   // 240
  cout << "(aa55bb): " << myatoi("aa55bb") << endl;             // 0
  cout << "(5a6): " << myatoi("5a6") << endl;                   // 5
  cout << "====================" << endl;

  return 0;
}
