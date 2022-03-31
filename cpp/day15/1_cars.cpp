#include <iostream>
#include <fstream>
#include <string>
#include "../lib/alphabet/alphabet.h"

using namespace std;

ifstream CARS_FILE;
const string CARS_FILENAME = "cars.txt";

struct Car {
  string brand;
  string model;
  string gearbox;
  string color;
  int price;
  int mileage;
  int year;
  double enginyCapacity;
};

enum CarFilterOptionsEnum {
  ALL_CARS = 1,
  BRAND = 2,
  PRICE = 3,
  MILEAGE = 4,
  GEARBOX = 5,
  ENGINY_CAPACITY = 6,
  YEAR = 7,
  COLOR = 8
};

enum MinMaxEnum {
  MIN = 1,
  MAX = 2,
  MIN_MAX = 3
};

int getCarsLength();
void initializeCars(Car*);
void showMenu();
bool isOptionsInvalid(int);
void filterCars(Car*, int);
void showCars(Car*, int);
void filterByOption(Car*, int, int, string);
void filterByMinMax(Car*, int, int, string);

int main() {
  cout.precision(1);
  cout << fixed;

  const int carsLength = getCarsLength();
  Car cars[carsLength];
  initializeCars(cars);
  filterCars(cars, carsLength);

  return 0;
}

int getCarsLength() {
  int result = 0;
  string fileLine = "";
  CARS_FILE.open(CARS_FILENAME);

  while (getline(CARS_FILE, fileLine)) {
    result++;
  }

  CARS_FILE.close();

  return result;
}

void initializeCars(Car *car) {
  try {
    CARS_FILE.open(CARS_FILENAME);

    if (CARS_FILE.fail()) {
      throw ("File " + CARS_FILENAME + " not found");
    }

    string fileLine = "";
    int carIndex = 0;

    while (getline(CARS_FILE, fileLine)) {
      string carsInfo[8] = {};
      int j = 0;

      for (int i = 0; i < fileLine.length(); i++) {
        if (fileLine[i] == ',') {
          j++;
          if (fileLine[i + 1] == ' ') {
            i++;
          }
          continue;
        }

        carsInfo[j] += fileLine[i];
      }

      car[carIndex].brand = carsInfo[0];
      car[carIndex].model = carsInfo[1];
      car[carIndex].price = stoi(carsInfo[2]);
      car[carIndex].mileage = stoi(carsInfo[3]);
      car[carIndex].enginyCapacity = stod(carsInfo[4]);
      car[carIndex].gearbox = carsInfo[5];
      car[carIndex].year = stoi(carsInfo[6]);
      car[carIndex].color = carsInfo[7];

      carIndex++;
    }

    CARS_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    CARS_FILE.close();
    exit(0);
  }
}

void showMenu() {
  cout << "==================================" << endl;
  cout << "1) Show all cars" << endl;
  cout << "2) Filter cars by brand" << endl;
  cout << "3) Filter cars by price" << endl;
  cout << "4) Filter cars by mileage" << endl;
  cout << "5) Filter cars by gearbox" << endl;
  cout << "6) Filter cars by enginy capacity" << endl;
  cout << "7) Filter cars by year" << endl;
  cout << "8) Filter cars by color" << endl;
  cout << "9) Exit (or another key)" << endl;
  cout << "==================================" << endl;
}

bool isOptionsValid(int option) {
  bool isValid = false;

  for (int i = ALL_CARS; i <= COLOR; i++) {
    if (option == i) {
      isValid = true;
      break;
    }
  }

  return isValid;
}

void filterCars(Car *car, int carsLength) {
  cout << endl;
  while (true) {
    showMenu();

    int mode;
    cout << "Option: ";
    cin >> mode;

    if (!isOptionsValid(mode)) {
      break;
    }

    switch (mode) {
      case ALL_CARS:
        showCars(car, carsLength);
        break;
      case BRAND:
        filterByOption(car, carsLength, mode, "brand");
        break;
      case GEARBOX:
        filterByOption(car, carsLength, mode, "gearbox");
        break;
      case COLOR:
        filterByOption(car, carsLength, mode, "color");
        break;
      case PRICE:
        filterByMinMax(car, carsLength, mode, "price");
        break;
      case MILEAGE:
        filterByMinMax(car, carsLength, mode, "mileage");
        break;
      case ENGINY_CAPACITY:
        filterByMinMax(car, carsLength, mode, "enginy capacity");
        break;
      case YEAR:
        filterByMinMax(car, carsLength, mode, "year");
        break;
      default:
        cout << "Option not found" << endl;
        break;
    }
  }
}

void showCars(Car *car, int carsLength) {
  cout << "================================================================================================================================================" << endl;
  cout << "Brand\t\t | Model\t\t | Price\t | Mileage\t\t | Enginy Capacity\t | Gearbox\t | Year\t | Color" << endl;
  cout << "================================================================================================================================================" << endl;

  for (int i = 0; i < carsLength; i++) {
    if (car[i].brand == "" || car[i].model == "" || car[i].gearbox == "" || !car[i].year || car[i].color == ""  || !car[i].price || !car[i].mileage || !car[i].enginyCapacity) {
      continue;
    }

    cout << car[i].brand << "\t\t | ";
    cout << car[i].model << (car[i].model.length() <= 4 ? "\t\t\t" : "\t\t") << " | ";
    cout << "$" << car[i].price << "\t | ";
    cout << car[i].mileage << " KM \t\t | ";
    cout << car[i].enginyCapacity << " L\t\t | ";
    cout << car[i].gearbox << "\t | ";
    cout << car[i].year << "\t | ";
    cout << car[i].color << endl;
  }

  cout << "================================================================================================================================================" << endl;
  cout << endl;
}

void filterByOption(Car *car, int carsLength, int mode, string ctx) {
  string option;
  cout << "Input " << ctx << ": ";
  cin >> option;

  Car filteredCars[carsLength];
  bool isFound = false;

  for (int i = 0; i < carsLength; i++) {
    if (
      (mode == BRAND && strToLower(car[i].brand) == strToLower(option))
      || (mode == GEARBOX && strToLower(car[i].gearbox) == strToLower(option))
      || (mode == COLOR && strToLower(car[i].color) == strToLower(option))
    ) {
      filteredCars[i] = car[i];
      isFound = true;
    }
  }

  if (isFound) {
    showCars(filteredCars, carsLength);
  } else {
    cout << "Car not found" << endl;
  }
}

void filterByMinMax(Car *car, int carsLength, int mode, string ctx) {
  int option;
  cout << "1) Min " << ctx << endl;
  cout << "2) Max " << ctx << endl;
  cout << "3) Min-Max " << endl;
  cout << "Option: ";
  cin >> option;

  double min = 0;
  double max = 0;

  if (option == MIN) {
    cout << "Min " << ctx << ": ";
    cin >> min;
  } else if (option == MAX) {
    cout << "Max " << ctx << ": ";
    cin >> max;
  } else if (option == MIN_MAX) {
    cout << "Min-Max " << ctx << ": " << endl;
    cin >> min >> max;
  } else {
    cout << "(min, max) - Option not found" << endl;
    return;
  }

  Car filteredCars[carsLength];
  bool isFound = false;

  for (int i = 0; i < carsLength; i++) {
    if (
      // --------price--------
      (mode == PRICE && option == MIN && car[i].price >= min)
      || (mode == PRICE && option == MAX && car[i].price <= max)
      || (mode == PRICE && option == MIN_MAX && (car[i].price <= max && car[i].price >= min))
      // --------mileage--------
      || (mode == MILEAGE && option == MIN && car[i].mileage >= min)
      || (mode == MILEAGE && option == MAX && car[i].mileage <= max)
      || (mode == MILEAGE && option == MIN_MAX && (car[i].mileage <= max && car[i].mileage >= min))
      // --------enginy capacity--------
      || (mode == ENGINY_CAPACITY && option == MIN && car[i].enginyCapacity >= min)
      || (mode == ENGINY_CAPACITY && option == MAX && car[i].enginyCapacity <= max)
      || (mode == ENGINY_CAPACITY && option == MIN_MAX && (car[i].enginyCapacity <= max && car[i].enginyCapacity >= min))
      // --------year--------
      || (mode == YEAR && option == MIN && car[i].year >= min)
      || (mode == YEAR && option == MAX && car[i].year <= max)
      || (mode == YEAR && option == MIN_MAX && (car[i].year <= max && car[i].year >= min))
    ) {
      filteredCars[i] = car[i];
      isFound = true;
    }
  }

  if (isFound) {
    showCars(filteredCars, carsLength);
  } else {
    cout << "Car not found" << endl;
  }
}
