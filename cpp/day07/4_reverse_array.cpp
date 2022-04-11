#include <iostream>

using namespace std;

void printArray(int size, int *arr);
void reverseArray(int size, int *arr);

int main() {
  const int size = 7;
  int arr[size] = { 10, 20, 33, 7, 4, 5, 6 };

  cout << "initial array: [";
  printArray(size, arr);
  cout << "]";

  reverseArray(size, arr);

  cout << endl << "reversed array: [";
  printArray(size, arr);
  cout << "]";

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

void reverseArray(int size, int *arr) {
  int *start = arr;
  int *end = arr + size - 1;

  while (start < end) {
    int temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}
