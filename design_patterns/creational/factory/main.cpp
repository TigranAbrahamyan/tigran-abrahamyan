#include "./factory.hpp"

int main() {
  MemberFactory factory;
  Membership* memberships[3] = {
    factory.create("John Wick", STANDARD),
    factory.create("John Smith", PREMIUM),
    factory.create("Yandex Alica", STANDARD),
  };

  for (int i = 0; i < 3; i++) {
    memberships[i]->displayInfo();
  }

  return 0;
}
