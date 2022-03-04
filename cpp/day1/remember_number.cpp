#include <iostream>
using namespace std;

int rememberNumber(
  string message = "Remember a number between 0-100: "
) {
  int n = 0;
  cout << message;
  cin >> n;

  if (n >= 0 && n <= 100) {
    return n;
  } else {
    return rememberNumber("Remember again: ");
  }
}

int main() {
  int rememberedNumber = rememberNumber();
  bool isFound = false;

  do {
    int number = 0;
    cout << "============================\n";
    cout << "Guess the number: ";
    cin >> number;

    if (rememberedNumber == number) {
      cout << "Number is found\n";
      isFound = true;
    } else if (number > rememberedNumber) {
      cout << "Your number is greater than the remembered number\n";
    } else if (number < rememberedNumber) {
      cout << "Your number is less than the remembered number\n";
    }
  } while (isFound == false);
}
