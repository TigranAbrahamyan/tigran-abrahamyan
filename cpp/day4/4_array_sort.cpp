#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void generateArray(
  int minNumberInRange,
  int maxNumberInRange,
  int arraySize,
  double array[]
) {
  for (int i = 0; i < arraySize; i++) {
    double randomNumber = rand() / (RAND_MAX + 0.0); // generate random numbers between 0 to 1
    double randomNumberInRange = (randomNumber * (maxNumberInRange - minNumberInRange)) + minNumberInRange;
    double fixedTwoDecimalPlaces = round(randomNumberInRange * 100) / 100;
    array[i] = fixedTwoDecimalPlaces;
  }
}

void sortArray(int arraySize, double array[]) {
  for (int i = 0; i < arraySize; i++) {
    int indexOfMin = i;
    for (int j = i + 1; j < arraySize; j++) {
      if (array[j] < array[indexOfMin]) {
        indexOfMin = j;
      }
    }

    double temp = array[i];
    array[i] = array[indexOfMin];
    array[indexOfMin] = temp;
  }
}

void printArray(int arraySize, double array[]) {
  for (int i = 0; i < arraySize; i++) {
    cout << array[i];
    if (i != arraySize - 1) {
      cout << ", ";
    }
  }
}

int main() {
  const int currentTime = time(0);
  srand(currentTime);

  int minNumberInRange;
  int maxNumberInRange;
  int arraySize;

  cout << "Set a numbers range" << endl;
  cout << "Min: ";
  cin >> minNumberInRange;

  cout << "Max: ";
  cin >> maxNumberInRange;

  if (minNumberInRange > maxNumberInRange) {
    cout << "Min number should be less than max number" << endl;
    return 0;
  }

  cout << "Set array size: ";
  cin >> arraySize;
  cout << "==================================" << endl;

  double array[arraySize];

  generateArray(minNumberInRange, maxNumberInRange, arraySize, array);

  cout << "Array: ";
  printArray(arraySize, array);
  cout << endl;

  sortArray(arraySize, array);

  cout << "Sorted array: ";
  printArray(arraySize, array);

  return 0;
}
