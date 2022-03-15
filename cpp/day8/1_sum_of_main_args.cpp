#include <iostream>
#include "../lib/myatoi/myatoi.h"

using namespace std;

int main(int argc, char *argv[]) {
  int sum = 0;
  char **start = argv + 1;
  char **end = argv + argc - 1;

  while (start <= end) {
    sum += myatoi(*start);
    start++;
  }

  cout << "sum: " << sum << endl;

  return 0;
}
