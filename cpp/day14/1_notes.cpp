#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <dirent.h>

#include "../lib/alphabet/alphabet.h"

using namespace std;

int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

enum WEEKDAYS {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};

struct Note {
  string note;
  string weekday;
  int weekdayNumber;
};

void getSplittedDate(string, string*);
string getWeekday(int);
void getWeekday(int, int, int, Note&);
void writeNoteToFile(int, int, int, string, string, Note);
void readFilesFromDir(DIR*);

int main() {
  Note myNote;

  while (true) {
    string date = "";
    cout << "Input date: ";
    getline(cin, date);

    string splittedDate[3] = {};
    getSplittedDate(date, splittedDate);

    int day = stoi(splittedDate[0]);
    int month = stoi(splittedDate[1]);
    int year = stoi(splittedDate[2]);

    DAYS[1] = year % 4 == 0 ? 29 : 28;

    if (day <= DAYS[month - 1] && month <= 12 && year >= 1900) {
      string note = "";
      cout << "Add note: ";
      getline(cin, note);

      getWeekday(day, month, year, myNote);
      writeNoteToFile(day, month, year, date, note, myNote);

      string command = "";
      cout << "Command (add/exit, or another key): ";
      cin >> command;
      cin.ignore();

      if (strToLower(command) != "add") {
        break;
      }
    } else {
      cout << "Invalid date, try again" << endl;
    }
  }

  cout << "==================" << endl;

  DIR *dir = opendir("./notes");

  if (dir == NULL) {
    cout << "Directory not found" << endl;
  } else {
    readFilesFromDir(dir);
  }

  closedir(dir);

  return 0;
}

void getSplittedDate(string date, string *splittedDate) {
  int j = 0;

  for (int i = 0; i < date.length(); i++) {
    if (date[i] == '/' || date[i] == '.' || date[i] == '-' || date[i] == ' ') {
      j++;
      continue;
    }

    splittedDate[j] += date[i];
  }
}

string getWeekday(int weekdayNumber) {
  string weekday = "";

  switch (weekdayNumber) {
    case SUNDAY:
      weekday = "Sunday";
      break;
    case MONDAY:
      weekday = "Monday";
      break;
    case TUESDAY:
      weekday = "Tuesday";
      break;
    case WEDNESDAY:
      weekday = "Wednesday";
      break;
    case THURSDAY:
      weekday = "Thursday";
      break;
    case FRIDAY:
      weekday = "Friday";
      break;
    case SATURDAY:
      weekday = "Saturday";
      break;
    default:
      break;
  }

  return weekday;

  // const string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  // return weekdays[weekdayNumber];
}

void getWeekday(int day, int month, int year, Note &myNote) {
  tm time_in = {
    0, 0, 0, // second, minute, hour
    day, month - 1, year - 1900 // 1-based day, 0-based month, year since 1900
  };

  const time_t time_temp = mktime(&time_in);
  const tm * time_out = localtime(&time_temp);

  myNote.weekdayNumber = time_out->tm_wday; // Sunday == 0, Monday == 1
  myNote.weekday = getWeekday(myNote.weekdayNumber);
}

void writeNoteToFile(int day, int month, int year, string date, string note, Note myNote) {
  string convertedDay = day < 10 ? "0" + to_string(day) : to_string(day);
  string convertedMonth = month < 10 ? "0" + to_string(month) : to_string(month);
  string convertedYear = to_string(year);

  string filename = "./notes/" + convertedDay + "_" + convertedMonth + "_" + convertedYear + ".txt";

  string fileLine = "";
  ifstream inputNoteFile(filename);
  ofstream outputNoteFile(filename, ios::app);

  if (inputNoteFile.is_open()) {
    while (getline(inputNoteFile, fileLine)) {
      if (fileLine != myNote.weekday) {
        outputNoteFile << "- " << "Note: " << note << endl;
        break;
      }
    }
  } else {
    outputNoteFile << myNote.weekday + " " + date << endl;
    outputNoteFile << "- " << "Note: " << note << endl;
  }

  inputNoteFile.close();
  outputNoteFile.close();
}

void readFilesFromDir(DIR *dir) {
  struct dirent *entity;
  entity = readdir(dir);

  while (entity != NULL) {
    string file = entity->d_name;
    regex txtRegex(".*\\.txt$");
    bool isTXT = regex_match(file, txtRegex);

    if (isTXT) {
      string str = "";
      ifstream noteFile;
      noteFile.open("./notes/" + file);

      try {
        if (noteFile.fail()) {
          throw ("File " + file + " not found.");
        }

        while (getline(noteFile, str)) {
          cout << str << endl;
        }

        cout << endl;
        noteFile.close();
      } catch (const string err) {
        cout << err;
      }
    }

    entity = readdir(dir);
  }
}
