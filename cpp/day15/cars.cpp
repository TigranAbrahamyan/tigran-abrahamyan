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
  double price;
  double mileage;
  double enginyCapacity;
  int year;
};

struct Filter {
  string brand;
  string gearbox;
  string color;
  double minPrice;
  double maxPrice;
  double minMileage;
  double maxMileage;
  double minEnginyCapacity;
  double maxEnginyCapacity;
  double minYear;
  double maxYear;
} filter;

enum CarFilterOptionsEnum {
  SHOW_FILTRATION_RESULT = 0,
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
  MAX = 2
};

int getCarsLength();
void initCars(Car*);
void showMenu();
void showCars(Car*, int);
bool isOptionsInvalid(int);
void minMaxHelper(double*, double*, string);
void filterCars(Car*, int);
void filtrationResult(Car*, int);

int main() {
  cout.precision(1);
  cout << fixed;

  const int carsLength = getCarsLength();
  Car cars[carsLength];
  initCars(cars);
  filterCars(cars, carsLength);

  return 0;
}

int getCarsLength() {
  try {
    CARS_FILE.open(CARS_FILENAME);

    if (CARS_FILE.fail()) {
      throw ("File " + CARS_FILENAME + " not found");
    }

    int counter = 0;
    string fileLine = "";

    while (getline(CARS_FILE, fileLine)) {
      counter++;
    }

    CARS_FILE.close();

    return counter;
  } catch (const string err) {
    cout << err << endl;
    CARS_FILE.close();
    exit(0);
  }
}

void initCars(Car *car) {
  string fileLine = "";
  int carIndex = 0;
  CARS_FILE.open(CARS_FILENAME);

  while (getline(CARS_FILE, fileLine)) {
    string carsInfo[8] = {};
    int j = 0;

    for (int i = 0; i < fileLine.length(); i++) {
      if (fileLine[i] == ',' && fileLine[i + 1] == ' ') {
        j++;
        i++;
        continue;
      }

      carsInfo[j] += fileLine[i];
    }

    car[carIndex].brand = carsInfo[0];
    car[carIndex].model = carsInfo[1];
    car[carIndex].price = stod(carsInfo[2]);
    car[carIndex].mileage = stod(carsInfo[3]);
    car[carIndex].enginyCapacity = stod(carsInfo[4]);
    car[carIndex].gearbox = carsInfo[5];
    car[carIndex].year = stoi(carsInfo[6]);
    car[carIndex].color = carsInfo[7];

    carIndex++;
  }

  CARS_FILE.close();
}

void showMenu() {
  cout << "==================================" << endl;
  cout << "0) Show filtration result" << endl;
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

bool isOptionsValid(int option) {
  bool isValid = false;

  for (int i = SHOW_FILTRATION_RESULT; i <= COLOR; i++) {
    if (option == i) {
      isValid = true;
      break;
    }
  }

  return isValid;
}

void minMaxHelper(double *filterMin, double *filterMax, string ctx) {
  int minMaxOption;
  double min, max;
  cout << "1) Min " << ctx << endl;
  cout << "2) Max " << ctx << endl;
  cout << "Option: ";
  cin >> minMaxOption;

  if (minMaxOption == MIN) {
    cout << "Min " << ctx << ": ";
    cin >> min;
    *filterMin = min;
  } else if (minMaxOption == MAX) {
    cout << "Max " << ctx << ": ";
    cin >> max;
    *filterMax = max;
  } else {
    cout << "Option not found" << endl;
  }
}

void filterCars(Car *car, int carsLength) {
  while (true) {
    showMenu();
    int option;
    cout << "Option: ";
    cin >> option;

    if (!isOptionsValid(option)) {
      break;
    }

    string value;

    switch (option) {
      case SHOW_FILTRATION_RESULT:
        filtrationResult(car, carsLength);
        break;
      case ALL_CARS:
        showCars(car, carsLength);
        break;
      case BRAND:
        cout << "Input brand: ";
        cin >> value;
        filter.brand = value;
        break;
      case GEARBOX:
        cout << "Input gearbox: ";
        cin >> value;
        filter.gearbox = value;
        break;
      case COLOR:
        cout << "Input color: ";
        cin >> value;
        filter.color = value;
        break;
      case PRICE:
        minMaxHelper(&filter.minPrice, &filter.maxPrice, "price");
        break;
      case MILEAGE:
        minMaxHelper(&filter.minMileage, &filter.maxMileage, "mileage");
        break;
      case ENGINY_CAPACITY:
        minMaxHelper(&filter.minEnginyCapacity, &filter.maxEnginyCapacity, "enginy capacity");
        break;
      case YEAR:
        minMaxHelper(&filter.minYear, &filter.maxYear, "year");
        break;
      default:
        cout << "Option not found" << endl;
        break;
    }
  }
}

void filtrationResult(Car *car, int carsLength) {
  Car filteredCars[carsLength];
  bool isFound = false;

  for (int i = 0; i < carsLength; i++) {
    if (
      (filter.brand != "" && strToLower(car[i].brand) != strToLower(filter.brand))
      || (filter.gearbox != "" && strToLower(car[i].gearbox) != strToLower(filter.gearbox))
      || (filter.color != "" && strToLower(car[i].color) != strToLower(filter.color))
      || (filter.minPrice && car[i].price < filter.minPrice)
      || (filter.maxPrice && car[i].price > filter.maxPrice)
      || (filter.minMileage && car[i].mileage < filter.minMileage)
      || (filter.maxMileage && car[i].mileage > filter.maxMileage)
      || (filter.minEnginyCapacity && (car[i].enginyCapacity < filter.minEnginyCapacity))
      || (filter.maxEnginyCapacity && car[i].enginyCapacity > filter.maxEnginyCapacity)
      || (filter.minYear && (car[i].year < filter.minYear))
      || (filter.maxYear && car[i].year > filter.maxYear)
    ) {
      continue;
    } else {
      filteredCars[i] = car[i];
      isFound = true;
    }
  }

  if (isFound) {
    showCars(filteredCars, carsLength);
  } else {
    cout << "Car not found" << endl;
  }

  exit(0);
}
