#include <string>
#include "./address.h"

Address::Address(std::string city, std::string street, std::string building, std::string houseNumber) {
  _city = city;
  _street = street;
  _building = building;
  _houseNumber = houseNumber;
}

void Address::setCity(std::string city) {
  _city = city;
}

void Address::setStreet(std::string street) {
  _street = street;
}

void Address::setBuilding(std::string building) {
  _building = building;
}

void Address::setHouseNumber(std::string houseNumber) {
  _houseNumber = houseNumber;
}

std::string Address::getFullAddress() const {
  return _city + " " + _street + " " + _building + " " + _houseNumber;
}
