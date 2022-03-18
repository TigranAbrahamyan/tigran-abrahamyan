#include <iostream>

using namespace std;

void swap(int *a, int *b);

int main() {
  int a = 5;
  int b = 6;

  cout << "old = " << "a: " << a << ", b: " << b << endl;
  swap(&a, &b);
  cout << "new = " << "a: " << a << ", b: " << b << endl;

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
