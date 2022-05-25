#include <iostream>
#include "./adapter.hpp"

int main() {
  OldCalc oldCalc;
  std::cout << oldCalc.operations(10, 15, '+') << std::endl;

  NewCalc newCalc;
  std::cout << newCalc.add(15, 15) << std::endl;
  std::cout << newCalc.sub(35, 20) << std::endl;

  CalcAdapter adapter;
  std::cout << adapter.operations(20, 15, '-') << std::endl;

  return 0;
}
