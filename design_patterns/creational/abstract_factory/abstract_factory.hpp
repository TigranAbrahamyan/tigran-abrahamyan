#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <iostream>
#include <string>

#define LINUX

using namespace std;

class Widget {
  public:
    virtual void draw() = 0;
};

// Concrete product family 1
class LinuxButton : public Widget {
  public:
    void draw() override {
      cout << "LinuxButton" << endl;
    }
};

class LinuxMenu : public Widget {
  public:
    void draw() override {
      cout << "LinuxMenu" << endl;
    }
};
// Concrete product family 1

// Concrete product family 2
class WindowsButton : public Widget {
  public:
    void draw() override {
      cout << "WindowsButton" << endl;
    }
};

class WindowsMenu : public Widget {
  public:
    void draw() override {
      cout << "WindowsMenu" << endl;
    }
};
// Concrete product family 2

class Client {
  public:
    void draw() {
      Widget* button;
      Widget* menu;

      #ifdef LINUX
        button = new LinuxButton();
        menu = new LinuxMenu();
      #else
        button = new WindowsButton();
        menu = new WindowsMenu();
      #endif
        button->draw();
        menu->draw();
    }
};

#endif
