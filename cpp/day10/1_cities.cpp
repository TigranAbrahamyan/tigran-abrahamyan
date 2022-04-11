#include <iostream>
#include <string>
#include <ctime>
#include "../lib/alphabet/alphabet.h"

using namespace std;

string CITIES[] = {
  "Yerevan",
  "Gyumri",
  "Vanadzor",
  "Vagharshapat",
  "Abovyan",
  "Kapan",
  "Hrazdan",
  "Armavir",
  "Artashat",
  "Ijevan",
  "Gavar",
  "Goris",
  "Charentcavan",
  "Ararat",
  "Masis",
  "Artik",
  "Sevan",
  "Ashtarak",
  "Gegharkunik",
  "Dilijan",
  "Sisian",
  "Dvin",
  "Alaverdi",
  "Stepanavan",
  "Martuni",
  "Spitak",
  "Vardenis",
  "Yeghvard",
  "Vedi",
  "Byureghavan",
  "Metsamor",
  "Berd",
  "Exegnadzor",
  "Tashir",
  "Kajaran",
  "Aparan",
  "Vayk",
  "Chambarak",
  "Maralik",
  "Noyemberyan",
  "Norashen",
  "Nor-armavir",
  "Talin",
  "Jermuk",
  "Meghri",
  "Ayrum",
  "Akhtala",
  "Tumanyan",
  "Tsaghkadzor"
};

const int CITIES_LENGTH = sizeof(CITIES) / sizeof(CITIES[0]);

void userErrorMessage(string, string, string, string *, int *, int *);
string getCorrectCity(char);
bool isCityExists(string);

int main() {
  srand(time(0));

  int startPoint = 1;
  int attempts = 5;
  string lastCity = "";

  cout << "================" << endl;
  cout << "Press 1 - if you want a start game" << endl;
  cout << "Press 2 - if you want a computer start game" << endl;
  cout << "Press 3 - or another key to exit" << endl;
  cout << "================" << endl;

  cin >> startPoint;

  if (startPoint != 1 && startPoint != 2) {
    return 0;
  }

  if (startPoint == 2) {
    lastCity = strToLower(CITIES[rand() % CITIES_LENGTH]);
    cout << "================\n" << "Computer: " << lastCity << endl;
    startPoint = 1;
  }

  while (true) {
    if (attempts < 1) {
      cout << endl << "You lose" << endl;
      break;
    }

    cout << "================\n";

    if (startPoint == 2) {
      const char lastLetter = lastCity[lastCity.length() - 1];
      string foundedCity = getCorrectCity(lastLetter);

      if (foundedCity == "") {
        cout << "Computer is could not guess and lose";
        break;
      }

      lastCity = foundedCity;
      cout << "Computer: " << lastCity << endl;
      startPoint = 1;
    }

    if (startPoint == 1) {
      const char lastLetter = lastCity[lastCity.length() - 1];
      string keepLastCity = lastCity;

      cout << "Attempts left " << attempts << endl << "Enter city: ";
      cin >> lastCity;

      if (lastLetter && toLower(lastCity[0]) != toLower(lastLetter)) {
        userErrorMessage("letter need to start", string(1, lastLetter), keepLastCity, &lastCity, &startPoint, &attempts);
        continue;
      }

      if (!isCityExists(lastCity)) {
        userErrorMessage("not found on my cities list or it is already entered", lastCity, keepLastCity, &lastCity, &startPoint, &attempts);
        continue;
      }

      startPoint = 2;
    }
  }

  return 0;
}

void userErrorMessage(string message, string context, string keepLastCity, string *lastCity, int *startPoint, int *attempts) {
  cout << "'" << context << "' " << message << ", try again" << endl;
  *lastCity = keepLastCity;
  *startPoint = 1;
  *attempts -= 1;
}

string getCorrectCity(char lastLetter) {
  string result = "";

  for (int i = 0; i < CITIES_LENGTH; i++) {
    if (toLower(CITIES[i][0]) == toLower(lastLetter)) {
      result = CITIES[i];
      CITIES[i] = "0";
      break;
    }
  }

  return result;
}

bool isCityExists(string lastCity) {
  bool result = false;

  for (int i = 0; i < CITIES_LENGTH; i++) {
    if (strToLower(CITIES[i]) == strToLower(lastCity)) {
      result = true;
      CITIES[i] = "0";
      break;
    }
  }

  return result;
}
