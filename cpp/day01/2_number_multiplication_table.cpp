#include <iostream>
using namespace std;

int myNum(
  string message = "Write a number between 1-9: \n"
) {
  int num;
  cout << message;
  cin >> num;

  if (num > 0 && num < 10) {
    cout << "=================\n";
    return num;
  } else {
    return myNum("Write again: \n");
  }
}

int main() {
  int num = myNum();
  int index = 1;

  while (index != 10) {
    cout << num << " * " << index << " = " << (num * index) << endl;
    index++;
  }
}
