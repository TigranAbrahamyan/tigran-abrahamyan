#include <iostream>
using namespace std;

int main() {
  int currentYear = 2022;
  int leapYearCount = 0;

  while (leapYearCount != 20) {
    if (currentYear % 4 == 0) {
      cout << (leapYearCount + 1) << ") " << currentYear << endl;
      leapYearCount++;
    }

    currentYear++;
  }
}
