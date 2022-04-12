#include <string>
#include "./homo_sapience.h"

HomoSapience::HomoSapience(
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
  Nationality nationality
) : Human(birthDate, gender, eyeColor, hairColor, father, mother, weight) {
  _address = address;
  _firstName = firstName;
  _lastName = lastName;
  _fatherName = fatherName;
  _nationality = nationality;
}

std::string HomoSapience::getFullName() const {
  return _firstName + " " + _lastName + " " + _fatherName;
}

Nationality HomoSapience::getNationality() const {
  return _nationality;
}
