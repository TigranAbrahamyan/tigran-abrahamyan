#include "./human.h"
#include "../date/date.h"
#include "../drink/drink.h"

Human::Human(
  Date birthDate,
  Gender gender,
  EyeColor eyeColor,
  HairColor hairColor,
  Human* father,
  Human* mother
) {
  _birthDate = birthDate;
  _gender = gender;
  _eyeColor = eyeColor;
  _hairColor = hairColor;
  _father = father;
  _mother = mother;
  _healthLevel = 100;
}

void Human::drink(Drink drink) {
  int healthLevel;

  if (drink.getType() == ALCOHOL) {
    healthLevel = _healthLevel - 5;
  }

  if (drink.getType() == MILK || drink.getType() == TEA) {
    healthLevel = (_healthLevel >= 95 && _healthLevel <= 100) ? 100 : _healthLevel + 5;
  }

  Human::setHealthLevel(healthLevel);
}

Date Human::getBirthDate() {
  return _birthDate;
}

void Human::setBirthDate(Date birthDate) {
  _birthDate = birthDate;
}

Gender Human::getGender() {
  return _gender;
}

EyeColor Human::getEyeColor() {
  return _eyeColor;
}

void Human::setEyeColor(EyeColor eyeColor) {
  if (eyeColor == BLACK || eyeColor == GREEN || eyeColor == GRAY) {
    _eyeColor = eyeColor;
  } else {
    _eyeColor = BLACK;
  }
}

HairColor Human::getHairColor() {
  return _hairColor;
}

void Human::setHairColor(HairColor hairColor) {
  if (hairColor == WHITE || hairColor == RED) {
    _hairColor = hairColor;
  } else {
    _hairColor = WHITE;
  }
}

Human* Human::getFather() {
  return _father;
}

void Human::setFather(Human* father) {
  _father = father;
}

Human* Human::getMother() {
  return _mother;
}

void Human::setMother(Human* mother) {
  _mother = mother;
}

int Human::getHealthLevel() {
  return _healthLevel;
}

void Human::setHealthLevel(int healthLevel) {
  if (healthLevel >= 1 && healthLevel <= 100) {
    _healthLevel = healthLevel;
  } else {
    _healthLevel = 1;
  }
}
