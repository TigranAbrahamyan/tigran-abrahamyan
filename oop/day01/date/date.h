#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  private:
    short _year;
    short _month;
    short _day;

  public:
    Date(short year, short month, short day);

    short getYear() const;
    void setYear(short year);

    short getMonth() const;
    void setMonth(short month);

    short getDay() const;
    void setDay(short day);

    std::string getFullDate() const;
};

#endif
