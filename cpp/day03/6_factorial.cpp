#include <iostream>

using namespace std;

int factorial(int n) {
  if (n == 1) {
    return n;
  }

  return n * factorial(n - 1);
}

int main() {
  int number = 0;

  cout << "Write a number: ";
  cin >> number;

  if (number > 0) {
    int numberFactorial = factorial(number);
    cout << "Factorial: " << numberFactorial << endl;
  } else {
    cout << "Your number should be greater than 0" << endl;
  }

  return 0;
}
