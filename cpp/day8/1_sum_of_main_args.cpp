#include <iostream>
#include "../lib/myatoi/myatoi.h"

using namespace std;

int main(int argc, char *argv[]) {
  int sumMyAtoi = 0;
  int sumAtoi = 0;
  char **start = argv + 1;
  char **end = argv + argc - 1;

  while (start <= end) {
    sumMyAtoi += myatoi(*start);
    sumAtoi += atoi(*start);
    start++;
  }

  cout << "sumMyAtoi: " << sumMyAtoi << endl;
  cout << "sumAtoi: " << sumAtoi << endl;

  return 0;
}
