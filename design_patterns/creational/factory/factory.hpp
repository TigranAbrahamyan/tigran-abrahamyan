#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>

using namespace std;

enum MembershipTypes {
  STANDARD = 1,
  PREMIUM = 2
};

class Membership {
  protected:
    MembershipTypes _type;

  public:
    virtual void displayInfo() = 0;
    virtual void setType(MembershipTypes) = 0;
};

class StandardMembership : public Membership {
  private:
    string _name;
    unsigned int _cost;

  public:
    StandardMembership(string name) {
      _name = name;
      _cost = 100;
    }

    void displayInfo() override {
      cout << _name << " (Standard): " << _cost << endl;
    }

    void setType(MembershipTypes type) override {
      if (type == STANDARD) {
        _type = type;
      }
    }
};

class PremiumMembership : public Membership {
  private:
    string _name;
    unsigned int _cost;

  public:
    PremiumMembership(string name) {
      _name = name;
      _cost = 500;
    }

    void displayInfo() override {
      cout << _name << " (Premium): " << _cost << endl;
    }

    void setType(MembershipTypes type) override {
      if (type == PREMIUM) {
        _type = type;
      }
    }
};

class MemberFactory {
  public:
    Membership* create(string name, MembershipTypes type = STANDARD) {
      Membership* membership;

      if (type == STANDARD) {
        membership = new StandardMembership(name);
      } else if (type == PREMIUM) {
        membership = new PremiumMembership(name);
      }

      membership->setType(type);

      return membership;
    }
};

#endif
