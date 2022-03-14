#include <iostream>

using namespace std;

void sum1(int *a, int *b, int *sum);
void sum2(int &a, int &b, int &sum);
void sum3(int a, int b, int &sum);
void sum4(int a, int *b, int &sum);
void sum5(int *a, int *b, int &sum);

int main() {
  int a = 5;
  int b = 6;
  int sum;

  sum1(&a, &b, &sum);
  cout << "sum1: " << sum << endl << "============" << endl;

  sum2(a, b, sum);
  cout << "sum2: " << sum << endl << "============" << endl;

  sum3(a, b, sum);
  cout << "sum3: " << sum << endl << "============" << endl;

  sum4(a, &b, sum);
  cout << "sum4: " << sum << endl << "============" << endl;

  sum5(&a, &b, sum);
  cout << "sum5: " << sum << endl;

  return 0;
}

void sum1(int *a, int *b, int *sum) {
  *sum = *a + *b;
}

void sum2(int &a, int &b, int &sum) {
  sum = a + b;
}

void sum3(int a, int b, int &sum) {
  sum = a + b;
}

void sum4(int a, int *b, int &sum) {
  sum = a + *b;
}

void sum5(int *a, int *b, int &sum) {
  sum = *a + *b;
}
