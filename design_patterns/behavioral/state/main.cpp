#include "./state.hpp"

int main() {
  AlertStateContext* stateContext = new AlertStateContext(new Vibration());
  stateContext->alert();
  stateContext->alert();
  stateContext->setState(new Silent());
  stateContext->alert();
  stateContext->alert();
  stateContext->alert();

  return 0;
}
