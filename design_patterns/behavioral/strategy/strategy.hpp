#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
using namespace std;

class Vehicle {
  public:
    virtual int travelTime() = 0;
};

class Car : public Vehicle {
  private:
    int _minuteTaken;

  public:
    Car() {
      _minuteTaken = 5;
    }

    int travelTime() override {
      return _minuteTaken;
    }
};

class Taxi : public Vehicle {
  private:
    int _minuteTaken;

  public:
    Taxi() {
      _minuteTaken = 10;
    }

    int travelTime() override {
      return _minuteTaken;
    }
};

class Bus : public Vehicle {
  private:
    int _minuteTaken;

  public:
    Bus() {
      _minuteTaken = 15;
    }

    int travelTime() override {
      return _minuteTaken;
    }
};

class Commute {
  public:
    travel(Vehicle* transport) {
      return transport->travelTime();
    }
};

#endif
