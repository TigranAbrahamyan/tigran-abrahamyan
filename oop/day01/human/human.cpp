#include "./human.h"

Human::Human(
  Date* birthDate,
  Gender gender,
  EyeColor eyeColor,
  HairColor hairColor,
  Human* father,
  Human* mother,
  short weight
) {
  _birthDate = birthDate;
  _gender = gender;
  _eyeColor = eyeColor;
  _hairColor = hairColor;
  _father = father;
  _mother = mother;
  _weight = weight;
  _healthLevel = 100;
}

std::string Human::speak(std::string text) {
  return text;
}

void Human::walk() {
  if (_healthLevel < 100) {
    _healthLevel++;
  }

  _weight--;
}

void Human::digest() {
  if (_healthLevel < 100) {
    _healthLevel++;
  }
}

void Human::goToGym() {
  if (_healthLevel < 100) {
    _healthLevel++;
  }

  _weight--;
}

void Human::eat(Food food) {
  if ((food == BANAN || food == FISH) && _healthLevel < 100) {
    _healthLevel++;
  }

  if ((food == HAMBURGER || food == HOT_DOG) && _healthLevel < 100) {
    _healthLevel--;
  }

  _weight++;
}

void Human::drink(Drink drink) {
  if (drink == ALCOHOL) {
    _healthLevel = _healthLevel - 5;
  }

  if (drink == MILK || drink == TEA) {
    _healthLevel = (_healthLevel >= 95 && _healthLevel <= 100) ? 100 : _healthLevel + 5;
  }
}

Date* Human::getBirthDate() const {
  return _birthDate;
}

void Human::setBirthDate(Date* birthDate) {
  _birthDate = birthDate;
}

EyeColor Human::getEyeColor() const {
  return _eyeColor;
}

void Human::setEyeColor(EyeColor eyeColor) {
  if (eyeColor == BLACK || eyeColor == GREEN || eyeColor == GRAY) {
    _eyeColor = eyeColor;
  } else {
    _eyeColor = BLACK;
  }
}

HairColor Human::getHairColor() const {
  return _hairColor;
}

void Human::setHairColor(HairColor hairColor) {
  if (hairColor == WHITE || hairColor == RED) {
    _hairColor = hairColor;
  } else {
    _hairColor = WHITE;
  }
}

Gender Human::getGender() const {
  return _gender;
}

Human* Human::getFather() const {
  return _father;
}

Human* Human::getMother() const {
  return _mother;
}

short Human::getHealthLevel() const {
  return _healthLevel;
}
