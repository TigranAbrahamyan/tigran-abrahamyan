#include "./bs_tree.h"

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
  root->insertRecursive(14);
  root->insertRecursive(13);
  root->insertRecursive(40);
  root->insertRecursive(38);
  root->insertRecursive(34);
  root->insertRecursive(36);
  root->insertRecursive(35);

  root->deleteNode(36);
  root->deleteNode(9);
  root->deleteNode(25);
  root->deleteNodeRecursive(35);
  root->deleteNodeRecursive(14);
  root->deleteNodeRecursive(30);
  root->deleteNodeRecursive(18);

  root->printSorted();

  return 0;
}
