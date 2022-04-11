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

struct Diary {
  string note;
  string weekday;
  int weekdayNumber;
};

void getSplittedDate(string, string*);
string getWeekday(int);
void getWeekday(int, int, int, Diary&);
void writeNoteToFile(int, int, int, Diary);
void readFilesFromDir(DIR*);

int main() {
  Diary myDiary;

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
      cout << "Add note: ";
      getline(cin, myDiary.note);

      getWeekday(day, month, year, myDiary);
      writeNoteToFile(day, month, year, myDiary);

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
  switch (weekdayNumber) {
    case SUNDAY:
      return "Sunday";
    case MONDAY:
      return "Monday";
    case TUESDAY:
      return "Tuesday";
    case WEDNESDAY:
      return "Wednesday";
    case THURSDAY:
      return "Thursday";
    case FRIDAY:
      return "Friday";
    case SATURDAY:
      return "Saturday";
  }

  return "";
  // const string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  // return weekdays[weekdayNumber];
}

void getWeekday(int day, int month, int year, Diary &myDiary) {
  tm time_in = {
    0, 0, 0, // second, minute, hour
    day, month - 1, year - 1900 // 1-based day, 0-based month, year since 1900
  };

  const time_t time_temp = mktime(&time_in);
  const tm * time_out = localtime(&time_temp);

  myDiary.weekdayNumber = time_out->tm_wday; // Sunday == 0, Monday == 1
  myDiary.weekday = getWeekday(myDiary.weekdayNumber);
}

void writeNoteToFile(int day, int month, int year, Diary myDiary) {
  string convertedDay = day < 10 ? "0" + to_string(day) : to_string(day);
  string convertedMonth = month < 10 ? "0" + to_string(month) : to_string(month);
  string convertedYear = to_string(year);
  string convertedDate = convertedDay + "_" + convertedMonth + "_" + convertedYear;
  string filename = "./notes/" + convertedDate + ".txt";
  ifstream inputDiaryFile(filename);
  ofstream outputDiaryFile(filename, ios::app);

  if (inputDiaryFile.good()) {
    string fileLine = "";
    while (getline(inputDiaryFile, fileLine)) {
      if (fileLine != myDiary.weekday) {
        outputDiaryFile << "- " << "Note: " << myDiary.note << endl;
        break;
      }
    }
  } else {
    outputDiaryFile << myDiary.weekday + " " + convertedDate << endl;
    outputDiaryFile << "- " << "Note: " << myDiary.note << endl;
  }

  inputDiaryFile.close();
  outputDiaryFile.close();
}

void readFilesFromDir(DIR *dir) {
  struct dirent *entity;
  entity = readdir(dir);

  while (entity != NULL) {
    string file = entity->d_name;
    regex txtRegex(".*\\.txt$");
    bool isTXT = regex_match(file, txtRegex);

    if (isTXT) {
      ifstream diaryFile;
      diaryFile.open("./notes/" + file);

      try {
        if (diaryFile.fail()) {
          throw ("File " + file + " not found.");
        }

        string str = "";
        while (getline(diaryFile, str)) {
          cout << str << endl;
        }
      } catch (const string err) {
        cout << err << endl;
      }

      cout << endl;
      diaryFile.close();
    }

    entity = readdir(dir);
  }
}
