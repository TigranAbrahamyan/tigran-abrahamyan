#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));
  const int min = 1;
  const int max = 9;

  const int arraySize = 4;
  int array[arraySize][arraySize] = {};

  const int trianglesCount = 8;
  int trianglesSumArray[trianglesCount] = {};
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

      // top triangle
      if (row < column && row + column + 1 < arraySize) {
        trianglesSumArray[4] += array[row][column];
      }

      // left triangle
      if (row > column && row + column + 1 < arraySize) {
        trianglesSumArray[5] += array[row][column];
      }

      // right triangle
      if (row < column && arraySize - row - 1 < column) {
        trianglesSumArray[6] += array[row][column];
      }

      // bottom triangle
      if (row > column && arraySize - row - 1 < column) {
        trianglesSumArray[7] += array[row][column];
      }
    }
  }

  cout << "top-right triangle: " << trianglesSumArray[0] << endl;
  cout << "bottom-left triangle: " << trianglesSumArray[1] << endl;
  cout << "top-left triangle: " << trianglesSumArray[2] << endl;
  cout << "bottom-right triangle: " << trianglesSumArray[3] << endl;
  cout << "top triangle: " << trianglesSumArray[4] << endl;
  cout << "left triangle: " << trianglesSumArray[5] << endl;
  cout << "right triangle: " << trianglesSumArray[6] << endl;
  cout << "bottom triangle: " << trianglesSumArray[7] << endl;

  for (int i = 0; i < trianglesCount; i++) {
    trianglesSumResult += trianglesSumArray[i];
  }

  cout << "===============================" << endl;
  cout << "all triangles sum result: " << trianglesSumResult << endl;

  return 0;
}
