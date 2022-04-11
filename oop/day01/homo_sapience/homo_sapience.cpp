#include <string>
#include "./homo_sapience.h"
`
HomoSapience::HomoSapience(std::string fullName, Nationality nationality) {
  _fullName = fullName;
  _nationality = nationality;
}

std::string HomoSapience::getFullName() {
  return _fullName;
}

void HomoSapience::setFullName(std::string fullName) {
  _fullName = fullName;
}

Nationality HomoSapience::getNationality() {
  return _nationality;
}
