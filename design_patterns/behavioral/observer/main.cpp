#include "./observer.hpp"

int main() {
  Subject *subject = new Subject();
  Observer *obs1 = new Observer();
  Observer *obs2 = new Observer(58);

  subject->subscribe(obs1);
  subject->subscribe(obs2);

  subject->fire(INCREMENT);
  subject->fire(INCREMENT);
  subject->fire(DECREMENT);
  subject->fire(INCREMENT);

  cout << obs1->getState() << endl;
  cout << obs2->getState() << endl;

  cout << "===========================" << endl;

  subject->unsubscribe(obs1);

  subject->fire(INCREMENT);
  subject->fire(INCREMENT);
  subject->fire(DECREMENT);
  subject->fire(INCREMENT);

  cout << obs1->getState() << endl;
  cout << obs2->getState() << endl;

  return 0;
}
