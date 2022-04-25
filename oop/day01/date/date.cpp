#include <string>
#include "./date.h"

Date::Date(short year, short month, short day) {
  _year = year;
  _month = month;
  _day = day;
}

short Date::getYear() const {
  return _year;
}

void Date::setYear(short year) {
  _year = year;
}

short Date::getMonth() const {
  return _month;
}

void Date::setMonth(short month) {
  _month = month;
}

short Date::getDay() const {
  return _day;
}

void Date::setDay(short day) {
  _day = day;
}

std::string Date::getFullDate() const {
  return std::to_string(_year) + " " + std::to_string(_month) + " " + std::to_string(_day);
}
