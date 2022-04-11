#include <iostream>

using namespace std;

void fillMatrix(int **arr, int row, int col) {
  int **rowStart = arr;
  int **rowEnd = arr + row - 1;

  while (rowStart <= rowEnd) {
    *rowStart = new int[col];
    int *colStart = *rowStart;
    int *colEnd = colStart + col - 1;

    while (colStart <= colEnd) {
      *colStart = rand() % 10;
      colStart++;
    }

    rowStart++;
  }
}

void printMatrix(int **arr, int row, int col) {
  int **rowStart = arr;
  int **rowEnd = arr + row - 1;

  while (rowStart <= rowEnd) {
    int *colStart = *rowStart;
    int *colEnd = colStart + col - 1;

    while (colStart <= colEnd) {
      cout << *colStart << " ",
      colStart++;
    }

    cout << endl;
    rowStart++;
  }
}

void sortMatrix(int **arr, int row, int col) {
  int **rowStart = arr;
  int **rowEnd = arr + row - 1;

  while (rowStart <= rowEnd) {
    int *colStart = *rowStart;
    int *colEnd = colStart + col - 1;

    while (colStart <= colEnd) {
      int *colStartOuter = *rowStart;
      int *colEndOuter = colStartOuter + col - 1;

      while (colStartOuter <= colEndOuter) {
        if (*colStartOuter > *colStart) {
          int temp = *colStartOuter;
          *colStartOuter = *colStart;
          *colStart = temp;
        }

        colStartOuter++;
      }

      colStart++;
    }

    rowStart++;
  }
}

int main() {
  srand(time(0));

  int row, col;
  cout << "row, col" << endl;
  cin >> row >> col;

  int **arr = new int*[row];

  fillMatrix(arr, row, col);
  printMatrix(arr, row, col);
  sortMatrix(arr, row, col);
  cout << endl;
  printMatrix(arr, row, col);

  return 0;
}
