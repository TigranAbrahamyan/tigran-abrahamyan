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
  const int size = 4;

  int firstArray[size][size] = {};
  int secondArray[size][size] = {};
  int resultArray[size][size] = {};

  cout << "First" << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      firstArray[i][j] = genRandomNumberInRange(max, min);
      cout << firstArray[i][j] << " ";
    }

    cout << endl;
  }

  cout << endl;
  cout << "Second" << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      secondArray[i][j] = genRandomNumberInRange(max, min);
      cout << secondArray[i][j] << " ";
    }

    cout << endl;
  }

  cout << endl;
  cout << "Result" << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      resultArray[i][j] = firstArray[i][j] + secondArray[i][j];
      cout << resultArray[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}
