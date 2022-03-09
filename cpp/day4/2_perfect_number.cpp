#include <iostream>

using namespace std;

/*
  perfect number - if sum of number divisors equal to number it is a perfect number
**/

void isNumberPerfect(int n) {
  int sum = 0;

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      sum = sum + i;
    }
  }

  if (sum == n) {
    cout << "Number is perfect";
  } else {
    cout << "Number is not perfect";
  }
}

int main() {
  int n;

  cout << "Write a non-negative number: ";
  cin >> n;

  while (n <= 0) {
    cout << "Error! write again: ";
    cin >> n;
  }

  isNumberPerfect(n);
  cout << endl;

  return 0;
}
