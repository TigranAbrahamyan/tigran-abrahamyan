#include <iostream>
#include <math.h>
#include "./polynomial.h"

using namespace std;

Polynomial::Polynomial(int degree, int x) {
  _degree = degree;
  _x = x;
  _arr = new int[_degree];
  _nArr = new int[_degree];
  for (int i = 0; i <= _degree; i++) {
    _arr[i] = i;
  }
}

void Polynomial::print(int result, char polynomialOperatorChar) {
  for (int i = _degree; i >= 0; i--) {
    cout << "(" << to_string(_nArr[i]) << "*x^" << to_string(i) << ")";
    if (i != 0) {
      cout << polynomialOperatorChar;
    }
  }

  cout << " = " << result;
}

int Polynomial::add() {
  int n;
  int result = 0;

  for (int i = _degree; i >= 0; i--) {
    cout << "a[" << i << "] = ";
    cin >> n;
    _nArr[i] = n;
    result += (n * pow(_x, i));
  }

  return result;
}

int Polynomial::subtract() {
  int n;
  int result = 0;

  for (int i = _degree; i >= 0; i--) {
    cout << "a[" << i << "] = ";
    cin >> n;
    _nArr[i] = n;
    result -= (n * pow(_x, i));
  }

  return result;
}

int Polynomial::multiply() {
  int n;
  int result = 1;

  for (int i = _degree; i >= 0; i--) {
    cout << "a[" << i << "] = ";
    cin >> n;
    _nArr[i] = n;
    result *= (n * pow(_x, i));
  }

  return result;
}

int main() {
  char polynomialOperatorChar;
  int polynomialOperator;
  int degree;
  int x;

  cout << "1) Add" << endl << "2) Subtract" << endl << "3) Multiply" << endl << "Option: ";
  cin >> polynomialOperator;

  cout << "Input degree: ";
  cin >> degree;

  cout << "Input x: ";
  cin >> x;

  int result;
  Polynomial* polynomial = new Polynomial(degree, x);

  switch (polynomialOperator) {
    case 1:
      result = polynomial->add();
      polynomialOperatorChar = '+';
      break;
    case 2:
      result = polynomial->subtract();
      polynomialOperatorChar = '-';
      break;
    case 3:
      result = polynomial->multiply();
      polynomialOperatorChar = '*';
      break;
    default:
      cout << "Operator not found\n";
      return 0;
  }

  polynomial->print(result, polynomialOperatorChar);

  return 0;
}
