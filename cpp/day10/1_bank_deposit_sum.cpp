#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void getCurrentMonthNumber(string currentTime, string *month, int *monthNumber);
void getCurrentDay(string currentTime, string *currentDay);

int main(int argc, char **argv) {
  double money = stod(argv[1]) + 0.0;
  double percent = stod(argv[2]) + 0.0;
  int month = atoi(argv[3]);

  double totalProfit;

  time_t now = time(0);
  string currentTime = ctime(&now);

  string currentMonth = "";
  int currentMonthNumber = 1;
  getCurrentMonthNumber(currentTime.substr(0, 10), &currentMonth, &currentMonthNumber);

  string currentDay;
  getCurrentDay(currentTime.substr(0, 10), &currentDay);

  cout << "====================" << endl;
  cout << "Current time: " << currentTime;
  cout << "Percent: " << percent << "%" << endl;
  cout << "Duration " << month << " Month" << endl;
  cout << "====================" << endl;
  for (int i = currentMonthNumber; i <= currentMonthNumber + month; i++) {
    double monthProfit = (money * (percent / 12.0)) / 100.0;

    totalProfit += monthProfit;
    money += monthProfit;

    monthProfit = floor(monthProfit * 100) / 100;
    money = floor(money * 100) / 100;

    cout << "Month: " << i << " | " << "Profit: " << monthProfit << " | " << "Money: " << money << endl;
  }

  totalProfit = floor(totalProfit * 100) / 100;

  cout << "====================" << endl;
  cout << "Total profit: " << totalProfit << endl;
  cout << "Total money: " << money << endl;
  cout << "====================" << endl;

  return 0;
}

void getCurrentMonthNumber(string currentTime, string *month, int *monthNumber) {
  string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  for (int i = 0; i < 12; i++) {
    int position = currentTime.find(months[i]);

    if (position != -1) {
      *monthNumber = i + 1;
      *month = months[i];
      break;
    }
  }
}

void getCurrentDay(string currentTime, string *currentDay) {
  string days[31] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
  int dayPosition = -1;

  for (int i = 10; i <= 31; i++) {
    dayPosition = currentTime.find(days[i]);

    if (dayPosition != -1) {
      *currentDay = days[i];
      break;
    }
  }

  if (dayPosition == -1) {
      for (int i = 0; i <= 9; i++) {
      dayPosition = currentTime.find(days[i]);

      if (dayPosition != -1) {
        *currentDay = days[i];
        break;
      }
    }
  }
}
