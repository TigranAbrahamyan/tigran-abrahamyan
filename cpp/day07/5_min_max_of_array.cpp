#include <iostream>

using namespace std;

void printArray(int size, int *arr);
void findMinAndMaxElementsOfArray(int size, int *arr, int *min, int *max);

int main() {
  const int size = 7;
  int arr[size] = { 10, 20, 33, 7, 4, 5, 6 };
  int min = arr[0];
  int max = arr[0];

  cout << "array: [";
  printArray(size, arr);
  cout << "]";

  findMinAndMaxElementsOfArray(size, arr, &min, &max);
  cout << endl << "min: " << min << " max: " << max;

  return 0;
}

void printArray(int size, int *arr) {
  int *start = arr;
  int *end = arr + size - 1;

  while (start <= end) {
    cout << *start;

    if (start != end) {
      cout << ", ";
    }

    start++;
  }
}

void findMinAndMaxElementsOfArray(int size, int *arr, int *min, int *max) {
  int *start = arr;
  int *end = arr + size - 1;

  while (start <= end) {
    if (*start < *min) {
      *min = *start;
    }

    if (*start > *max) {
      *max = *start;
    }

    start++;
  }
}
