#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
  private:
    std::string _city;
    std::string _street;
    std::string _building;
    std::string _houseNumber;

  public:
    Address(std::string, std::string, std::string, std::string);

    void setCity(std::string);
    void setStreet(std::string);
    void setBuilding(std::string);
    void setHouseNumber(std::string);

    std::string getFullAddress() const;
};

#endif
