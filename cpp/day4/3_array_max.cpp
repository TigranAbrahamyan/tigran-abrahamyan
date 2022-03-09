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
  int rangeDiff = (maxNumberInRange + 1) - minNumberInRange;

  /*
    time - returns the current calendar time of the system in seconds.
  **/
  int currentTime = time(0);

  /*
    srand - set random
    Initializing a random number based on some number on each program run,
    so that the number generation - 'rand() - fn' is not to be the same number on each program run.
  **/
  srand(currentTime);

  cout << "Array: ";

  for (int i = 0; i < arraySize; i++) {
    array[i] = (rand() % rangeDiff) + minNumberInRange;
    cout << array[i];
    if (i != arraySize - 1) {
      cout << ", ";
    }
  }
}

void getArrayMaxMinNumber(int arraySize, int array[]) {
  int arrayMinNumber = array[0];
  int arrayMaxNumber = array[0];

  for (int i = 0; i < arraySize; i++) {
    if (array[i] > arrayMaxNumber) {
      arrayMaxNumber = array[i];
    }

    if (array[i] < arrayMinNumber) {
      arrayMinNumber = array[i];
    }
  }

  cout << "Array max: " << arrayMaxNumber << endl;
  cout << "Array min: " << arrayMinNumber << endl;
}

int main() {
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

  generateArray(minNumberInRange, maxNumberInRange, arraySize, array);
  cout << endl;

  getArrayMaxMinNumber(arraySize, array);
  cout << endl;

  return 0;
}
