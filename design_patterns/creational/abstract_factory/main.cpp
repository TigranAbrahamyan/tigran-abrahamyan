#include "./abstract_factory.hpp"

int main() {
  Client* client = new Client();
  client->draw();

  return 0;
}
