#include <string>
#include "./programmer.h"

Programmer::Programmer(
  Date birthDate,
  Gender gender,
  EyeColor eyeColor,
  HairColor hairColor,
  Human* father,
  Human* mother,
  std::string firstName,
  std::string lastName,
  std::string fatherName,
  Nationality nationality,
  WorkPlace workPlace,
  ProgrammingLanguage language,
  Level level,
  short salary
) : HomoSapience(birthDate, gender, eyeColor, hairColor, father, mother, firstName, lastName, fatherName, nationality) {
  _workPlace = workPlace;
  _language = language;
  _level = level;
  _salary = salary;
}

void Programmer::work() {
  return;
}

WorkPlace Programmer::getWorkPlace() {
  return _workPlace;
}

void Programmer::setWorkPlace(WorkPlace workPlace) {
  if (workPlace == GOOGLE || workPlace == AMAZON) {
    _workPlace = workPlace;
  } else {
    _workPlace = GOOGLE;
  }
}

ProgrammingLanguage Programmer::getLanguage() {
  return _language;
}

void Programmer::setLanguage(ProgrammingLanguage language) {
  if (language == C || language == CPP || language == JAVA) {
    _language = language;
  } else {
    _language = C;
  }
}

Level Programmer::getLevel() {
  return _level;
}

void Programmer::setLevel(Level level) {
  if (level == INTERN || level == JUNIOR || level == MIDDLE || level == SENIOR) {
    _level = level;
  } else {
    _level = INTERN;
  }
}

short Programmer::getSalary() {
  return _level;
}

void Programmer::setSalary(short salary) {
  _salary = salary;
}
