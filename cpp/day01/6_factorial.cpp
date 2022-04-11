#include <iostream>
using namespace std;

int main() {
  int number = 0;
  int result = 1;
  cout << "Write a number: ";
  cin >> number;

  while (number != 0) {
    result = result * number;
    number--;
  }

  cout << "Factorial: " << result << endl;
}
