#include "./strategy.hpp"

int main() {
  Commute* commute = new Commute();
  cout << commute->travel(new Car()) << endl;
  cout << commute->travel(new Taxi()) << endl;
  cout << commute->travel(new Bus()) << endl;

  return 0;
}
