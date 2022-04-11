#include <string>
#include "../human/human.h"

#ifndef HOMO_SAPIENCE_H
#define HOMO_SAPIENCE_H

enum Nationality {
  ENGLISH = 0,
  GERMAN = 1
};

class HomoSapience : public Human {
  private:
    std::string _fullName;
    Nationality _nationality;

  public:
    HomoSapience(std::string fullName, Nationality nationality);

    std::string getFullName();
    void setFullName(std::string fullName);

    Nationality getNationality();
};

#endif
