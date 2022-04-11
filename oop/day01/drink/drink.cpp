#include "./drink.h"

Drink::Drink(DrinkType type, std::string name) {
  _type = type;
  _name = name;
}

DrinkType Drink::getType() {
  return _type;
}

void Drink::setType(DrinkType type) {
  _type = type;
}

std::string Drink::getName() {
  return _name;
}

void Drink::setName(std::string name) {
  _name = name;
}
