#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "../date/date.h"

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

enum Drink {
  ALCOHOL = 0,
  JUICE = 1,
  MILK = 2,
  TEA = 3,
  COFFEE = 4
};

enum Food {
  BANAN = 0,
  FISH = 1,
  HAMBURGER = 2,
  HOT_DOG = 3
};

class Human {
  private:
    Date* _birthDate;
    Gender _gender;
    EyeColor _eyeColor;
    HairColor _hairColor;
    Human* _father;
    Human* _mother;
    short _healthLevel;
    short _weight;

  public:
    Human(
      Date* birthDate,
      Gender gender,
      EyeColor eyeColor,
      HairColor hairColor,
      Human* father,
      Human* mother,
      short weight
    );

    Human(const Human&) = default;

    std::string speak(std::string text);
    void walk();
    void digest();
    void goToGym();
    void drink(Drink drink);
    void eat(Food food);

    Date* getBirthDate() const;
    void setBirthDate(Date* birthDate);

    EyeColor getEyeColor() const;
    void setEyeColor(EyeColor eyeColor);

    HairColor getHairColor() const;
    void setHairColor(HairColor hairColor);

    Gender getGender() const;
    Human* getFather() const;
    Human* getMother() const;
    short getHealthLevel() const;
};

#endif
