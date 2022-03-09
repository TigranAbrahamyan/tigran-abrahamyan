#include <iostream>

using namespace std;

int getChickenLegsCount(int chickens) {
  return chickens * 2;
}

int getCowLegsCount(int cow) {
  return cow * 4;
}

int getPigLegsCount(int pig) {
  return pig * 4;
}

int main() {
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

  int totalLegs = getChickenLegsCount(chickens) + getCowLegsCount(cows) + getPigLegsCount(pigs);
  cout << totalLegs << endl;

  return 0;
}
