#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int genRandomNumberInRange(int max, int min) {
  return (rand() % (max + 1) - min) + min;
}

int main() {
  srand(time(0));

  const int min = 1;
  const int max = 9;
  const int m = 4;
  const int n = 3;

  int arr[m][n] = {};

  int rowPosition = 0;
  bool isFound = false;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = genRandomNumberInRange(max, min);
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < m && !isFound; i++) {
    int rowEvenNumbersCount = 0;

    for (int j = 0; j < n; j++) {
      if (arr[i][j] % 2 == 0) {
        rowEvenNumbersCount++;
      }
    }

    if (rowEvenNumbersCount == n) {
      rowPosition = i;
      isFound = true;
    }
  }

  if (isFound) {
    cout << "Row - " << rowPosition + 1;
  } else {
    cout << "No";
  }

  return 0;
}
