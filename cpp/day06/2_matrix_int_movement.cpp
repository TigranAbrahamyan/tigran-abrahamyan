#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));

  const int m = 3;
  const int n = 3;
  int arr[m][n] = {};

  cout << "Array" << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = rand() % 10;
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < m; i++) {
    int rowMinNumber = arr[i][0];
    int rowMaxNumber = arr[i][0];
    int rowMinIndex = i;
    int rowMaxIndex = i;

    for (int j = 0; j < n; j++) {
      if (rowMinNumber <= arr[i][j]) {
        rowMinNumber = arr[i][j];
        rowMinIndex = j;
      }

      if (rowMaxNumber >= arr[i][j]) {
        rowMaxNumber = arr[i][j];
        rowMaxIndex = j;
      }
    }

    arr[i][rowMinIndex] = rowMaxNumber;
    arr[i][rowMaxIndex] = rowMinNumber;
  }

  cout << endl;
  cout << "Result" << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}
