#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <string>
#include "../homo_sapience/homo_sapience.h"

enum WorkPlace {
  GOOGLE = 0,
  AMAZON = 1
};

enum ProgrammingLanguage {
  C = 0,
  CPP = 1,
  JAVA = 2
};

enum Level {
  INTERN = 0,
  JUNIOR = 1,
  MIDDLE = 2,
  SENIOR = 3
};

class Programmer : public HomoSapience {
  private:
    WorkPlace _workPlace;
    ProgrammingLanguage _language;
    Level _level;
    short _salary;

  public:
    Programmer(
      Date birthDate,
      Gender gender,
      EyeColor eyeColor,
      HairColor hairColor,
      Human* father,
      Human* mother,
      std::string firstName,
      std::string lastName,
      std::string fatherName,
      Nationality nationality,
      WorkPlace workPlace,
      ProgrammingLanguage language,
      Level level,
      short salary
    );

    void work() override;

    WorkPlace getWorkPlace();
    void setWorkPlace(WorkPlace workPlace);

    ProgrammingLanguage getLanguage();
    void setLanguage(ProgrammingLanguage language);

    Level getLevel();
    void setLevel(Level level);

    short getSalary();
    void setSalary(short salary);
};

#endif
