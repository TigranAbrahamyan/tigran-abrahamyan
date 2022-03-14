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

  int sum1Var;
  sum1(&a, &b, &sum1Var);
  cout << "sum1: " << sum1Var << endl << "============" << endl;

  int sum2Var;
  sum2(a, b, sum2Var);
  cout << "sum2: " << sum2Var << endl << "============" << endl;

  int sum3Var;
  sum3(a, b, sum3Var);
  cout << "sum3: " << sum3Var << endl << "============" << endl;

  int sum4Var;
  sum4(a, &b, sum4Var);
  cout << "sum4: " << sum4Var << endl << "============" << endl;

  int sum5Var;
  sum5(&a, &b, sum5Var);
  cout << "sum5: " << sum5Var << endl;

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
