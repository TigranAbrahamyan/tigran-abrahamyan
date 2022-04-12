#include <string>
#include "./homo_sapience.h"

HomoSapience::HomoSapience(
  Date birthDate,
  Gender gender,
  EyeColor eyeColor,
  HairColor hairColor,
  Human* father,
  Human* mother,
  std::string firstName,
  std::string lastName,
  std::string fatherName,
  Nationality nationality
) : Human(birthDate, gender, eyeColor, hairColor, father, mother) {
  _firstName = firstName;
  _lastName = lastName;
  _fatherName = fatherName;
  _nationality = nationality;
}

std::string HomoSapience::getFullName() {
  return _firstName + " " + _lastName + " " + _fatherName;
}

Nationality HomoSapience::getNationality() {
  return _nationality;
}
