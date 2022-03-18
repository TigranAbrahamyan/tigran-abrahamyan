#include <iostream>
using namespace std;

int main() {
  int chickenLegs = 2;
  int cowLegs = 4;
  int pigLegs = 4;

  int chickens = 0;
  int cows = 0;
  int pigs = 0;

  int result = 0;

  cout << "Hello Fermer! Please tell me how many animals do you have: \n";
  cout << "Chickens: ";
  cin >> chickens;
  cout << "Cows: ";
  cin >> cows;
  cout << "Pigs: ";
  cin >> pigs;

  result = (chickens * chickenLegs) + (cows * cowLegs) + (pigs * pigLegs);

  cout << "Result: " << result << endl;
}
