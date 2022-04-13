#include <iostream>

using namespace std;

class Polynomial {
  private:
    int _degree;
    int _x;
    int* _arr;
    int* _nArr;

  public:
    Polynomial(int, int);

    void print(int, char);
    int add();
    int subtract();
    int multiply();
};
