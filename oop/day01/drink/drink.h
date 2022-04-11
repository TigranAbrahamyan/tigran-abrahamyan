#include <string>

#ifndef DRINK_H
#define DRINK_H

enum DrinkType {
  ALCOHOL = 0,
  JUICE = 1,
  MILK = 2,
  TEA = 3,
  COFFEE = 4
};

class Drink {
  private:
    DrinkType _type;
    std::string _name;

  public:
    Drink(DrinkType type, std::string name);

    DrinkType getType();
    void setType(DrinkType type);

    std::string getName();
    void setName(std::string name);
};

#endif