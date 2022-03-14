#include <iostream>

using namespace std;

void sumArray(int size, int *arr, int *result);

int main() {
  const int size = 6;
  int arr[size] = { 10, 2, 3, 4, 5, 6 };
  int result = 0;

  sumArray(size, arr, &result);
  cout << "res: " << result << endl;

  return 0;
}

void sumArray(int size, int *arr, int *result) {
  for (int i = 0; i < size; i++) {
    *result += *(arr++);
  }
}
