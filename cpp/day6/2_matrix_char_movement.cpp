#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));
  const int min = 1;
  const int max = 9;

  const int m = 3;
  const int n = 3;
  char arr[m][n] = {};

  const char firstUpper = 'A';
  const char firstLower = 'a';
  const char alphabetLength = 'Z' - firstUpper;

  cout << "Array" << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (rand() % 2 == 0) {
        arr[i][j] = (rand() % alphabetLength) + firstUpper;
      } else {
        arr[i][j] = (rand() % alphabetLength) + firstLower;
      }
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < m; i++) {
    char rowMinChar = arr[i][0];
    char rowMaxChar = arr[i][0];
    int rowMinIndex = i;
    int rowMaxIndex = i;

    for (int j = 0; j < n; j++) {
      if (rowMinChar <= arr[i][j]) {
        rowMinChar = arr[i][j];
        rowMinIndex = j;
      }
      if (rowMaxChar >= arr[i][j]) {
        rowMaxChar = arr[i][j];
        rowMaxIndex = j;
      }
    }

    arr[i][rowMinIndex] = rowMaxChar;
    arr[i][rowMaxIndex] = rowMinChar;
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
