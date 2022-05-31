#ifndef ADAPTER_H
#define ADAPTER_h

class OldCalc {
  public:
    int operations(int t1, int t2, char operation) {
      switch (operation) {
        case '+':
          return t1 + t2;
        case '-':
          return t1 - t2;
        default:
          return -1;
      }
    }
};

class NewCalc {
  public:
    int add(int t1, int t2) {
      return t1 + t2;
    }

    int sub(int t1, int t2) {
      return t1 - t2;
    }
};

class CalcAdapter {
  private:
    NewCalc calc;

  public:
    int operations(int t1, int t2, char operation) {
      switch (operation) {
        case '+':
          return calc.add(t1, t2);
        case '-':
          return calc.sub(t1, t2);
        default:
          return -1;
      }
    }
};

#endif
