#ifndef DATE_H
#define DATE_H

class Date {
  private:
    int _year;
    int _month;
    int _day;

  public:
    Drink(int year, int month, int day);

    int getYear();
    void setYear(int year);

    int getMonth();
    void setMonth(int month);

    int getDay();
    void setDay(int day);
};

#endif
