#include <string>
#include "./programmer.h"

Programmer::Programmer(
  Date* birthDate,
  Gender gender,
  EyeColor eyeColor,
  HairColor hairColor,
  Human* father,
  Human* mother,
  short weight,
  Address* address,
  std::string firstName,
  std::string lastName,
  std::string fatherName,
  Nationality nationality,
  WorkPlace workPlace,
  ProgrammingLanguage language,
  Level level,
  unsigned int salary
) : HomoSapience(birthDate, gender, eyeColor, hairColor, father, mother, weight, address, firstName, lastName, fatherName, nationality) {
  _workPlace = workPlace;
  _language = language;
  _level = level;
  _salary = salary;
}

void Programmer::work() {
  return;
}

WorkPlace Programmer::getWorkPlace() const {
  return _workPlace;
}

void Programmer::setWorkPlace(WorkPlace workPlace) {
  if (workPlace == INSTIGATE_MOBILE || workPlace == GOOGLE || workPlace == AMAZON) {
    _workPlace = workPlace;
  } else {
    _workPlace = INSTIGATE_MOBILE;
  }
}

ProgrammingLanguage Programmer::getLanguage() const {
  return _language;
}

void Programmer::setLanguage(ProgrammingLanguage language) {
  if (language == C || language == CPP || language == CSHARP || language == JAVA) {
    _language = language;
  } else {
    _language = C;
  }
}

Level Programmer::getLevel() const {
  return _level;
}

void Programmer::setLevel(Level level) {
  if (level == INTERN || level == JUNIOR || level == MIDDLE || level == SENIOR) {
    _level = level;
  } else {
    _level = INTERN;
  }
}

unsigned int Programmer::getSalary() const {
  return _level;
}

void Programmer::setSalary(unsigned int salary) {
  _salary = salary;
}
