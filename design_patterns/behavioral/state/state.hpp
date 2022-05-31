#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;

class AlertStateContext;

class MobileAlertState {
  public:
    virtual void alert(AlertStateContext*) = 0;
};

class AlertStateContext {
  private:
    MobileAlertState* currentState;

  public:
    AlertStateContext(MobileAlertState* state) {
      currentState = state;
    }

    void setState(MobileAlertState* state) {
      currentState = state;
    }

    void alert() {
      currentState->alert(this);
    }
};

class Vibration : public MobileAlertState {
  public:
    void alert(AlertStateContext* ctx) {
      cout << "vibration..." << endl;
    }
};

class Silent : public MobileAlertState {
  public:
    void alert(AlertStateContext* ctx) {
      cout << "silent..." << endl;
    }
};

#endif
