#include <iostream>
#include "./binary_tree.h"

using namespace std;

int main() {
  Tree* root = new Tree(1);

  for (int i = -5; i < 10; i++) {
    root->insert(i);
  }

  cout << "Min: " << root->treeMinValue() << endl;
  cout << "Sum: " << root->treeSum() << endl;

  cout << "DFS: ";
  root->dfs();

  cout << endl << "BFS: ";
  root->bfs();

  return 0;
}
