#include <iostream>
#include "./bs_tree.h"

using namespace std;

int main() {
  BSTree* root = new BSTree(3);

  for (int i = 0; i < 10; i++) {
    root->insert(i);
  }

  root->insert(19);
  root->insert(25);
  root->insert(22);
  root->insert(23);
  root->insert(24);
  root->insert(30);
  root->insert(18);
  root->insert(14);
  root->insert(13);
  root->insert(40);
  root->insert(38);
  root->insert(34);
  root->insert(36);
  root->insert(35);

  root->deleteNode(36);
  root->deleteNode(9);
  root->deleteNode(25);

  root->printSorted();

  return 0;
}
