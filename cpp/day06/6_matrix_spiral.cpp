#include <iostream>

using namespace std;

int digitCount(int n);
void printSpace(int n);

int main() {
  const int size = 12;
  const int spiralMaxDigitLength = digitCount(size * size);

  int arr[size][size] = {};

  int counter = 1;
  int startRow = 0;
  int endRow = size - 1;
  int startColumn = 0;
  int endColumn = size - 1;

  while (startRow <= endRow && startColumn <= endColumn) {
    for (int i = startColumn; i <= endColumn; i++) {
      arr[startRow][i] = counter;
      counter++;
    }
    startRow++;

    for (int i = startRow; i <= endRow; i++) {
      arr[i][endColumn] = counter;
      counter++;
    }
    endColumn--;

    for (int i = endColumn; i >= startColumn; i--) {
      arr[endRow][i] = counter;
      counter++;
    }
    endRow--;

    for (int i = endRow; i >= startRow; i--) {
      arr[i][startColumn] = counter;
      counter++;
    }
    startColumn++;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printSpace(spiralMaxDigitLength - digitCount(arr[i][j]));
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}

int digitCount(int n) {
  return n >= 10 ? digitCount(n / 10) + 1 : 1;
}

void printSpace(int n) {
  while (n--) {
    cout << " ";
  }
}
