#include "./date.h"

Date::Date(int year, int month, int day) {
  _year = year;
  _month = month;
  _day = day;
}

int Date::getYear() {
  return _year;
}

void Date::setYear(int year) {
  _year = year;
}

int Date::getMonth() {
  return _month;
}

void Date::setMonth(int month) {
  _month = month;
}

int Date::getDay() {
  return _day;
}

void Date::setDay(int day) {
  _day = day;
}
