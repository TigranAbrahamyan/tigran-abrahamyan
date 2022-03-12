#include <iostream>

using namespace std;

int main() {
  const int maxNumberOneLimit = 10;
  const int arraySize = 10;

  int array[arraySize] = {};
  int arrayElements = 0;

  int numberOne = 1;
  int numberTwo = 1;

  while (arrayElements != arraySize) {
    int sum = (numberOne * numberOne) + (numberTwo * numberTwo);

    if (sum % 5 == 0) {
      // check for uniqueness
      int arrayIndex = 0;
      bool shouldAddElemntToArray = true;

      while (arrayIndex < arrayElements) {
        if (array[arrayIndex] == sum) {
          shouldAddElemntToArray = false;
        }

        arrayIndex++;
      }

      // then add element to array if it unique
      if (shouldAddElemntToArray) {
        cout << numberOne * numberOne << "+" << numberTwo * numberTwo << "=" << sum << endl;
        array[arrayElements] = sum;
        arrayElements++;
      }
    }

    numberOne++;

    if (numberOne == maxNumberOneLimit) {
      numberOne = 1;
      numberTwo++;
    }
  }

  // Print array
  cout << "================" << endl;
  cout << "[";
  for (int i = 0; i < arraySize; i++) {
    cout << array[i];
    if (i != arraySize - 1) {
      cout << ", ";
    }
  }
  cout << "]";

  return 0;
}
