#include <iostream>

using namespace std;

int allAnimalsLegsCount() {
  int chickenLegs = 2;
  int cowLegs = 4;
  int pigLegs = 4;

  int chickens = 0;
  int cows = 0;
  int pigs = 0;

  cout << "Hello Fermer! Please tell me how many animals do you have: " << endl;
  cout << "Chickens: ";
  cin >> chickens;
  cout << "Cows: ";
  cin >> cows;
  cout << "Pigs: ";
  cin >> pigs;

  return (chickens * chickenLegs) + (cows * cowLegs) + (pigs * pigLegs);;
}

int main() {
  int animalLegsCount = allAnimalsLegsCount();
  cout << animalLegsCount << endl;

  return 0;
}
