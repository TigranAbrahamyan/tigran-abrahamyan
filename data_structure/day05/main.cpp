#include <iostream>
#include <chrono>

#define SIZE 40000

using namespace std;

void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void quickSort(int*, int, int);
void generateRandomNumber(int*);
void copyArray(int*, int*);

int main() {
  srand(time(0));

  int arr[SIZE];
  int merge[SIZE];
  int quick[SIZE];

  generateRandomNumber(arr);
  copyArray(arr, merge);
  copyArray(arr, quick);

  auto start = chrono::steady_clock::now();
  mergeSort(merge, 0, SIZE - 1);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << chrono::duration <double, milli> (diff).count() << " ms merge sort with count of elements: " << SIZE << endl;

  start = chrono::steady_clock::now();
  quickSort(quick, 0, SIZE);
  end = chrono::steady_clock::now();
  diff = end - start;
  cout << chrono::duration <double, milli> (diff).count() << " ms quick sort with count of elements: " << SIZE << endl;

  return 0;
}

void merge(int *arr, int left, int mid, int right) {
  int leftIndex = left;
  int rightIndex = mid + 1;
  int result[right - left + 1];
  int index = 0;

  while (leftIndex <= mid && rightIndex <= right) {
    if (arr[leftIndex] <= arr[rightIndex]) {
      result[index] = arr[leftIndex];
      leftIndex++;
    } else {
      result[index] = arr[rightIndex];
      rightIndex++;
    }

    index++;
  }

  while (leftIndex <= mid) {
    result[index] = arr[leftIndex];
    leftIndex++;
    index++;
  }

  while (rightIndex <= right) {
    result[index] = arr[rightIndex];
    rightIndex++;
    index++;
  }

  for (int i = 0; i <= right - left; i++) {
    arr[i + left] = result[i];
  }
}

void mergeSort(int* arr, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = (start + end) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

void quickSort(int* arr, int start, int end) {
  int i = start;
  int j = end;
  int mid = (i + j) / 2;
  int pivot = arr[mid];

  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }

    while (arr[j] > pivot) {
      j--;
    }

    if (i <= j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }

  if (i < end) {
    quickSort(arr, i, end);
  }

  if (j > start) {
    quickSort(arr, start, j);
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
