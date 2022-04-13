#ifndef HOMO_SAPIENCE_H
#define HOMO_SAPIENCE_H

#include <string>
#include "../human/human.h"
#include "../address/address.h"

enum Nationality {
  ENGLISH = 0,
  GERMAN = 1
};

class HomoSapience : public Human {
  private:
    Address* _address;
    std::string _firstName;
    std::string _lastName;
    std::string _fatherName;
    Nationality _nationality;

  protected:
    virtual void work();

  public:
    HomoSapience(
      const Human& human,
      Address* address,
      std::string firstName,
      std::string lastName,
      std::string fatherName,
      Nationality nationality
    );

    HomoSapience(const HomoSapience&) = default;

    std::string getFullName() const;
    Nationality getNationality() const;
};

#endif
