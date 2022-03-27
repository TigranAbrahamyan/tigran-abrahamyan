#include <iostream>

using namespace std;

int main() {
  int seconds;
  cout << "Input seconds: ";
  cin >> seconds;

  const int oneMinuteSec = 60;
  const int oneHourSec = 60 * oneMinuteSec; // 3600
  const int oneDaySec = 24 * oneHourSec; // 86400
  int monthPosition = 0;
  int year = 1970;

  int day = seconds / oneDaySec;
  seconds %= oneDaySec;

  while (day >= 365) {
    day = year % 4 == 0 ? day - 366 : day - 365;
    year++;
  }

  const int leapYear = year % 4 == 0;
  const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  for (int i = 0; day >= 30; i++) {
    day = leapYear && i == 1 ? day - 29 : day - monthDays[i];
    monthPosition++;
  }

  const int hour = seconds / oneHourSec;
  seconds %= oneHourSec;

  const int min = seconds / oneMinuteSec;
  seconds %= oneMinuteSec;

  const int sec = seconds % oneMinuteSec;

  const string convertedHour = hour < 10 ? "0" + to_string(hour) : to_string(hour);
  const string convertedMin = min < 10 ? "0" + to_string(min) : to_string(min);
  const string convertedSec = sec < 10 ? "0" + to_string(sec) : to_string(sec);

  cout << months[monthPosition] << " " << day + 1 << " " << year << " " << convertedHour << ":" << convertedMin << ":" << convertedSec;

  return 0;
}
