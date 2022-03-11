#include <iostream>

using namespace std;

int main() {
  const int min = 1;
  const int max = 9;

  const int size = 3;
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
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}
