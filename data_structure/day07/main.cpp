#include <iostream>
#include "./bs_tree.h"

using namespace std;

int main() {
  BSTree* root = new BSTree(5);

  for (int i = 0; i < 15; i++) {
    root->insert(i);
  }

  root->printSorted();

  return 0;
}
