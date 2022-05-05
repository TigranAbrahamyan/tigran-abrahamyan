#include "./binary_tree.h"

int main() {
  int size;
  cout << "Size: ";
  cin >> size;

  Tree* tree = new Tree();
  vector<int> nodes;
  int** matrix = new int*[size];

  cout << " ";
  for (int i = 0; i < size; i++) {
    cout << " " << i;
  }
  cout << endl;

  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
    cout << i << " ";
    for (int j = 0; j < size; j++) {
      cin >> matrix[i][j];
    }
  }

  if (tree->isMatrixBinaryTree(matrix, size, nodes)) {
    cout << "Is binary tree" << endl;
    cout << "Root: " << tree->root->_data << endl;

    for (int i = 0; i < nodes.size(); i++) {
      tree->insert(nodes[i]);
    }

    tree->bfs();
  } else {
    cout << "Is NOT binary tree" << endl;
  }

  return 0;
}
