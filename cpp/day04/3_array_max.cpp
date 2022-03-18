#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateArray(
  int minNumberInRange,
  int maxNumberInRange,
  int arraySize,
  int array[]
) {
  for (int i = 0; i < arraySize; i++) {
    array[i] = (rand() % ((maxNumberInRange + 1) - minNumberInRange)) + minNumberInRange;
    cout << array[i];
    if (i != arraySize - 1) {
      cout << ", ";
    }
  }
}

void getArrayMaxMinNumber(int arraySize, int array[]) {
  int arrayMaxNumber = array[0];
  int arrayMinNumber = array[0];

  for (int i = 0; i < arraySize; i++) {
    if (array[i] > arrayMaxNumber) {
      arrayMaxNumber = array[i];
    }

    if (array[i] < arrayMinNumber) {
      arrayMinNumber = array[i];
    }
  }

  cout << "Array max: " << arrayMaxNumber << ", Array min: " << arrayMinNumber;
}

int main() {
  // time - returns the current calendar time of the system in seconds.
  const int currentTime = time(0);

  /*
    srand - set random
    Initializing a random number based on some number on each program run,
    so that the number generation - 'rand() - fn' is not to be the same number on each program run.
  **/
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

  int array[arraySize];

  cout << "Array: ";
  generateArray(minNumberInRange, maxNumberInRange, arraySize, array);
  cout << endl;

  getArrayMaxMinNumber(arraySize, array);

  return 0;
}
