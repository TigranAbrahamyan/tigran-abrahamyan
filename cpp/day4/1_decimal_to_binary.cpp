#include <iostream>
#include <string>

using namespace std;

void decimalToBinary(int n) {
  int num = n;
  string binaries;

  while (num >= 1) {
    binaries = (num % 2 == 0 ? "0" : "1") + binaries;
    num = num / 2;
  }

  cout << binaries;
}

// void decimalToBinaryRecursive(int n, string binaries = "") {
//   if (n < 1) {
//     return;
//   }

//   decimalToBinaryRecursive(n / 2, (n % 2 == 0 ? "0" : "1") + binaries);
//   cout << binaries;
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

  return 0;
}
