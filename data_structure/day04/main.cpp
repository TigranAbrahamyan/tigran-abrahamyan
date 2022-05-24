#include <iostream>
#include <chrono>

#define SIZE 40000

using namespace std;

void bubbleSort(int*);
void insertionSort(int*);
void generateRandomNumber(int*);
void copyArray(int*, int*);

int main() {
  srand(time(0));

  int arr[SIZE];
  int bubble[SIZE];
  int insertion[SIZE];

  generateRandomNumber(arr);
  copyArray(arr, bubble);
  copyArray(arr, insertion);

  auto start = chrono::steady_clock::now();
  bubbleSort(bubble);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << chrono::duration <double, milli> (diff).count() << " ms bubble sort with count of elements: " << SIZE << endl;

  start = chrono::steady_clock::now();
  insertionSort(insertion);
  end = chrono::steady_clock::now();
  diff = end - start;
  cout << chrono::duration <double, milli> (diff).count() << " ms insertion sort with count of elements: " << SIZE << endl;

  return 0;
}

void bubbleSort(int* arr) {
  for (int i = 0; i < SIZE; i++) {
    bool swapped = true;
    for (int j = 0; j < SIZE - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = false;
      }
    }

    if (swapped) {
      break;
    }
  }
}

void insertionSort(int* arr) {
  for (int i = 0; i < SIZE; i++) {
    int current = arr[i];
    int j;

    for (j = i - 1; j >= 0 && arr[j] > current; j--) {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = current;
  }
}

void generateRandomNumber(int* arr) {
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % SIZE;
  }
}

void copyArray(int* copyArray, int *newArray) {
  for (int i = 0; i < SIZE; i++) {
    newArray[i] = copyArray[i];
  }
}
