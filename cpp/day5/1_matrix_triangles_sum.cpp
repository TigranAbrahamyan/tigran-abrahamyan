#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));
  const int arraySize = 3;
  const int min = 1;
  const int max = 9;
  int array[arraySize][arraySize] = {};

  const int trianglesCountIncludingDiagonals = 5;
  int trianglesSumArray[trianglesCountIncludingDiagonals] = {};
  int trianglesSumResult = 0;

  for (int i = 0; i < arraySize; i++) {
    for (int j = 0; j < arraySize; j++) {
      array[i][j] = (rand() % (max + 1) - min) + min;
      cout << array[i][j] << " ";
    }

    cout << endl;
  }

  for (int row = 0; row < arraySize; row++) {
    for (int column = 0; column < arraySize; column++) {
      // top-right
      if (row < column) {
        trianglesSumArray[0] += array[row][column];
      }

      // bottom-left
      if (row > column) {
        trianglesSumArray[1] += array[row][column];
      }

      // top-left
      if (row < arraySize - column - 1) {
        trianglesSumArray[2] += array[row][column];
      }

      // bottom-right
      if (row > arraySize - column - 1) {
        trianglesSumArray[3] += array[row][column];
      }

      // exclude numbers on diagonals and get numbers in non-diagonals
      if ((row != column) && (row + column) != (arraySize - 1)) {
        trianglesSumArray[4] += array[row][column];
      }
    }
  }

  cout << "top-right triangle sum: " << trianglesSumArray[0] << endl;
  cout << "bottom-left triangle sum: " << trianglesSumArray[1] << endl;
  cout << "top-left triangle sum: " << trianglesSumArray[2] << endl;
  cout << "bottom-right triangle sum: " << trianglesSumArray[3] << endl;
  cout << "big triangles sum: " << trianglesSumArray[4] << endl;

  for (int i = 0; i < trianglesCountIncludingDiagonals; i++) {
    trianglesSumResult += trianglesSumArray[i];
  }

  cout << "===============================" << endl;
  cout << "all triangles sum result: " << trianglesSumResult << endl;

  return 0;
}
