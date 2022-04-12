#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <string>
#include "../homo_sapience/homo_sapience.h"

enum WorkPlace {
  INSTIGATE_MOBILE = 0,
  GOOGLE = 1,
  AMAZON = 2
};

enum ProgrammingLanguage {
  C = 0,
  CPP = 1,
  CSHARP = 2,
  JAVA = 3
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
    unsigned int _salary;

  public:
    Programmer(
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
      Nationality nationality,
      WorkPlace workPlace,
      ProgrammingLanguage language,
      Level level,
      unsigned int salary
    );

    void work() override;

    WorkPlace getWorkPlace() const;
    void setWorkPlace(WorkPlace workPlace);

    ProgrammingLanguage getLanguage() const;
    void setLanguage(ProgrammingLanguage language);

    Level getLevel() const;
    void setLevel(Level level);

    unsigned int getSalary() const;
    void setSalary(unsigned int salary);
};

#endif
