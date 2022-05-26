#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>

using namespace std;

enum ActionTypes {
  INCREMENT,
  DECREMENT
};

class Observer {
  private:
    int _state;
    int _initialState;

  public:
    Observer(int state = 1) {
      _state = state;
      _initialState = state;
    }

    int getState() {
      return _state;
    }

    void update(char action) {
      switch (action) {
        case INCREMENT:
          _state = ++_state;
          break;
        case DECREMENT:
          _state = --_state;
          break;
        default:
          _state = _initialState;
      }
    }
};

class Subject {
  private:
    vector<Observer*> observers;

  public:
    void subscribe(Observer *observer) {
      observers.push_back(observer);
    }

    void unsubscribe(Observer *observer) {
      int position = -1;

      for (int i = 0; i < observers.size(); i++) {
        if (observers[i] == observer) {
          position = i;
        }
      }

      observers.erase(observers.begin() + position);
    }

    void fire(char action) {
      for (int i = 0; i < observers.size(); i++) {
        observers[i]->update(action);
      }
    }
};

#endif
