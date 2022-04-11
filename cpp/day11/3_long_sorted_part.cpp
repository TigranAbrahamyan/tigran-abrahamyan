#include <iostream>

using namespace std;

int main() {
  srand(time(0));

  int size = 0;
  const int min = -50;
  const int max = 50;

  cout << "Array size: ";
  cin >> size;

  int *arr = new int[size];

  cout << "[";
  for (int i = 0; i < size; i++) {
    arr[i] = (rand() % (max - min)) + min;
    cout << arr[i];

    if (i != size - 1) {
      cout << ", ";
    }
  }
  cout << "]";

  int startIndex = 0;
  int maxElemSorted = 1;
  int count = 1;

  for (int i = 0; i < size; i++) {
    if (arr[i] > arr[i - 1]) {
      count++;
    } else {
      if (count > maxElemSorted) {
        maxElemSorted = count;
        startIndex = i - maxElemSorted;
      }

      count = 1;
    }
  }

  cout << endl << "[";
  for (int i = startIndex; i < startIndex + maxElemSorted; i++) {
    cout << arr[i];

    if (i != startIndex + maxElemSorted - 1) {
      cout << ", ";
    }
  }
  cout << "]";

  return 0;
}
