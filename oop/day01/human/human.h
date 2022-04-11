#include <string>
#include "../date/date.h"
#include "../drink/drink.h"

#ifndef HUMAN_H
#define HUMAN_H

enum Gender {
  MALE = 0,
  FEMALE = 1
};

enum EyeColor {
  BLACK = 0,
  GREEN = 1,
  GRAY = 2
};

enum HairColor {
  WHITE = 0,
  RED = 1
};

class Human {
  private:
    Date _birthDate;
    Gender _gender;
    EyeColor _eyeColor;
    HairColor _hairColor;
    Human* _father;
    Human* _mother;
    int _healthLevel;

  public:
    Human(
      Date birthDate,
      Gender gender,
      EyeColor eyeColor,
      HairColor hairColor,
      Human* father,
      Human* mother
    );

    void drink(Drink drink);

    Date getBirthDate();
    void setBirthDate(Date birthDate);

    Gender getGender();

    EyeColor getEyeColor();
    void setEyeColor(EyeColor eyeColor);

    HairColor getHairColor();
    void setHairColor(HairColor hairColor);

    Human* getFather();
    void setFather(Human* father);

    Human* getMother();
    void setMother(Human* mother);

    int getHealthLevel();
    void setHealthLevel(int healthLevel);
};

#endif
