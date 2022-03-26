#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "../lib/alphabet/alphabet.h"

using namespace std;

ifstream COUNTRIES_FILE;
string COUNTRIES_FILENAME = "countries.txt";

enum SearchModes {
  COUNTRY_NAME = 1,
  CAPITAL = 2,
  DOMAIN = 3
};

struct Country {
  string countryName;
  string capital;
  string domain;
  int population;
  int area;
  int countryCode;
  long long int GDP;
};

int getCountriesSize();
void initializeCountries(Country*);
void searchCountryInfo(Country*, int);
char diff(long long, long long);
void getFirstAndSecondCountry(Country*, Country&, Country&, int);
void compareCountries(Country*, int);

int main(int argc, char *argv[]) {
  int countriesSize = getCountriesSize();
  Country country[countriesSize];
  initializeCountries(country);

  if (argc != 1 && strcmp(argv[1], "search") == 0) {
    searchCountryInfo(country, countriesSize);
  } else if (argc != 1 && strcmp(argv[1], "compare") == 0) {
    compareCountries(country, countriesSize);
  } else {
    cout << "You need to pass argument 'search' or 'compare'" << endl;
  }

  return 0;
}

int getCountriesSize() {
  int result = 0;
  string fileLine = "";
  COUNTRIES_FILE.open(COUNTRIES_FILENAME);

  while (getline(COUNTRIES_FILE, fileLine)) {
    result++;
  }

  COUNTRIES_FILE.close();

  return result;
}

void initializeCountries(Country *country) {
  try {
    COUNTRIES_FILE.open(COUNTRIES_FILENAME);

    if (COUNTRIES_FILE.fail()) {
      throw ("File " + COUNTRIES_FILENAME + " not found");
    }

    string fileLine = "";
    int countryIndex = 0;

    while (getline(COUNTRIES_FILE, fileLine)) {
      string countriesInfo[7] = {};
      int j = 0;

      for (int i = 0; i < fileLine.length(); i++) {
        if (fileLine[i] == ',') {
          j++;
          continue;
        }

        if (fileLine[i] != ' ') {
          countriesInfo[j] += fileLine[i];
        }
      }

      country[countryIndex].countryName = countriesInfo[0];
      country[countryIndex].capital = countriesInfo[1];
      country[countryIndex].domain = countriesInfo[2];
      country[countryIndex].population = stoi(countriesInfo[3]);
      country[countryIndex].area = stoi(countriesInfo[4]);
      country[countryIndex].GDP = stoll(countriesInfo[5]);
      country[countryIndex].countryCode = stoi(countriesInfo[6]);

      countryIndex++;
    }

    COUNTRIES_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    COUNTRIES_FILE.close();
    exit(0);
  }
}

void searchCountryInfo(Country *country, int countriesSize) {
  int searchMode;
  cout << "Input search mode '1) Country name / 2) Capital / 3) Domain': ";
  cin >> searchMode;

  if (searchMode != COUNTRY_NAME && searchMode != CAPITAL && searchMode != DOMAIN) {
    cout << "Invalid search mode" << endl;
    exit(0);
  }

  string searchModes[4] = {"", "Country name", "Capital", "Domain"};
  string option = "";
  cout << "Input " << searchModes[searchMode] <<  ": ";
  cin >> option;

  bool isFound = false;
  cout << "Output: ";

  for (int i = 0; i < countriesSize; i++) {
    if (
      (searchMode == COUNTRY_NAME && strToLower(country[i].countryName) == strToLower(option))
      || (searchMode == CAPITAL && strToLower(country[i].capital) == strToLower(option))
      || (searchMode == DOMAIN && strToLower(country[i].domain) == strToLower(option))
    ) {
      cout << "Country - " << country[i].countryName << endl;
      cout << "\tCapital - " << country[i].capital << endl;
      cout << "\tDomain - " << country[i].domain << endl;
      cout << "\tPopulation - " << country[i].population << endl;
      cout << "\tArea - " << country[i].area << endl;
      cout << "\tGDP - " << "$" << country[i].GDP << endl;
      cout << "\tCountry Code - " << "+" << country[i].countryCode << endl;
      isFound = true;
      break;
    }
  }

  if (!isFound) {
    cout << "'" << option << "' is not found on my " << searchModes[searchMode] << " list" << endl;
    exit(0);
  }
}

void compareCountries(Country *country, int countriesSize) {
  Country firstCountry;
  Country secondCountry;

  cout << "Input first Country: ";
  cin >> firstCountry.countryName;
  cout << "Input second Country: ";
  cin >> secondCountry.countryName;

  getFirstAndSecondCountry(country, firstCountry, secondCountry, countriesSize);

  char populationDiff = diff(firstCountry.population, secondCountry.population);
  char areaDiff = diff(firstCountry.area, secondCountry.area);
  char GDPDiff = diff(firstCountry.GDP, secondCountry.GDP);

  cout << "========================================================" << endl;
  cout << "\t\t | " << firstCountry.countryName << (firstCountry.countryName.length() <= 4 ? "\t\t\t | " : "\t\t | ") << secondCountry.countryName << endl;
  cout << "========================================================" << endl;
  cout << "Capital \t | " << firstCountry.capital << (firstCountry.capital.length() <= 4 ? "\t\t\t | " : "\t\t | ") << secondCountry.capital << endl;
  cout << "Domain \t\t | " << firstCountry.domain << (firstCountry.domain.length() <= 4 ? "\t\t\t | " : "\t\t | ") << secondCountry.domain << endl;
  cout << "Population \t | " << firstCountry.population << "\t\t " << populationDiff << " " << secondCountry.population << endl;
  cout << "Area \t\t | " << firstCountry.area << "\t\t " << areaDiff << " " << secondCountry.area << endl;
  cout << "GDP \t\t | $" << firstCountry.GDP << (to_string(firstCountry.GDP).length() <= 11 ? "\t\t " : "\t ") << GDPDiff << " $" << secondCountry.GDP << endl;
  cout << "Country Code \t | +" << firstCountry.countryCode << (firstCountry.domain.length() <= 3 ? "\t\t\t | " : "\t\t | ") << "+" << secondCountry.countryCode << endl;
}

char diff(long long a, long long b) {
  if (a > b) {
    return '>';
  } else if (a < b) {
    return '<';
  } else {
    return '=';
  }
}

void getFirstAndSecondCountry(Country *country, Country &firstCountry, Country &secondCountry, int countriesSize) {
  bool isFoundFirstCountry = false;
  bool isFoundSecondCountry = false;

  for (int i = 0; i < countriesSize; i++) {
    if (strToLower(firstCountry.countryName) == strToLower(country[i].countryName)) {
      firstCountry = country[i];
      isFoundFirstCountry = true;
      continue;
    }

    if (strToLower(secondCountry.countryName) == strToLower(country[i].countryName)) {
      secondCountry = country[i];
      isFoundSecondCountry = true;
      continue;
    }
  }

  if (!isFoundFirstCountry) {
    cout << "'" << firstCountry.countryName << "' not find on my countries list" << endl;
    exit(0);
  }

  if (!isFoundSecondCountry) {
    cout << "'" << secondCountry.countryName << "' not find on my countries list" << endl;
    exit(0);
  }
}
