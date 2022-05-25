#include "./decorator.hpp"

int main() {
  AWS* aws = new AWS(*(new Server("12.34.56.78", 80)));
  cout << aws->awsInfo() << endl;
  cout << "is aws: " << (aws->isAWS() ? "true" : "false") << endl;

  Azure* azure = new Azure(*(new Server("00.98.41.70", 55)));
  cout << endl << azure->getUrl() << endl;
  cout << "is azure: " << (azure->isAzure() ? "true" : "false") << endl;

  return 0;
}
