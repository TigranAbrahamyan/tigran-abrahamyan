#include <iostream>

using namespace std;

void decimalToBinary(int n) {
  int num = n;

  while (num >= 1) {
    cout << num % 2;
    num = num / 2;
  }
}

// void decimalToBinaryRecursion(int n) {
//   if (n < 1) {
//     return;
//   }

//   cout << n % 2;
//   decimalToBinaryRecursion(n / 2);
// }

int main() {
  int n;

  cout << "Write a non-negative number: ";
  cin >> n;

  while (n <= 0) {
    cout << "Error! write again: ";
    cin >> n;
  }

  decimalToBinary(n);
  cout << endl;

  return 0;
}
