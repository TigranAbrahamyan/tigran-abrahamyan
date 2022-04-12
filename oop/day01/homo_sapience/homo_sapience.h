#ifndef HOMO_SAPIENCE_H
#define HOMO_SAPIENCE_H

#include <string>
#include "../human/human.h"

enum Nationality {
  ENGLISH = 0,
  GERMAN = 1
};

class HomoSapience : public Human {
  private:
    std::string _firstName;
    std::string _lastName;
    std::string _fatherName;
    Nationality _nationality;

  protected:
    virtual void work();

  public:
    HomoSapience(
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
    );

    std::string getFullName();
    Nationality getNationality();
};

#endif
