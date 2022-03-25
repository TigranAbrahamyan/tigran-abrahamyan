#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "../lib/alphabet/alphabet.h"

using namespace std;

int COUNTRIES_SIZE = 5;
ifstream COUNTRIES_FILE;
string COUNTRIES_FILENAME = "countries.txt";

enum PhoneCodes {
  ARMENIA = 374,
  Georgia = 995,
  Russia = 7,
  USA = 1,
  Germany = 49,
};

enum SearchModes {
  COUNTRY_NAME = 1,
  CAPITAL = 2,
  DOMAIN = 3
};

struct Country {
  string countryName;
  string capital;
  string domain;
  string population;
  string area;
  string GDP;
};

void initializeCountries(Country*);

void searchCountryInfo(Country *country) {
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

  cout << "Output: ";
  for (int i = 0; i < COUNTRIES_SIZE; i++) {
    if (
      (searchMode == COUNTRY_NAME && country[i].countryName == option)
      || (searchMode == CAPITAL && country[i].capital == option)
      || (searchMode == DOMAIN && country[i].domain == option)
    ) {
      cout << "Country - " << country[i].countryName << endl;
      cout << "\tCapital - " << country[i].capital << endl;
      cout << "\tDomain - " << country[i].domain << endl;
      cout << "\tPopulation - " << country[i].population << endl;
      cout << "\tArea - " << country[i].area << endl;
      cout << "\tGDP - " << country[i].GDP << endl;
      // TODO: Update phone code
      cout << "\tPhone Code - " << "+" << 374 << endl;
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  Country country[COUNTRIES_SIZE];

  initializeCountries(country);

  char searchMode[] = "search";

  if (strcmp(argv[1], searchMode) == 0) {
    searchCountryInfo(country);
  }

  return 0;
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
      string countriesInfo[6] = {};
      int j = 0;

      for (int i = 0; i < fileLine.length(); i++) {
        if (fileLine[i] == ',') {
          j++;
          continue;
        }

        countriesInfo[j] += fileLine[i];
      }

      country[countryIndex].countryName = countriesInfo[0];
      country[countryIndex].capital = countriesInfo[1];
      country[countryIndex].domain = countriesInfo[2];
      country[countryIndex].population = countriesInfo[3];
      country[countryIndex].area = countriesInfo[4];
      country[countryIndex].GDP = countriesInfo[5];

      countryIndex++;
    }

    COUNTRIES_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    exit(0);
  }
}
