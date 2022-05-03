#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
  public:
    int _data;
    Node* _left;
    Node* _right;

    Node(int data, Node* left = NULL, Node* right = NULL) {
      _data = data;
      _left = left;
      _right = right;
    }
};

class BSTree {
  private:
    Node* root;

    void printSorted(Node*);

  public:
    BSTree(int);
    void insert(int);
    void printSorted();
};

BSTree::BSTree(int value) {
  root = new Node(value);
}

void BSTree::insert(int value) {
  if (root == NULL) {
    return;
  }

  Node *current = root;

  while (current) {
    if (current->_right == NULL && value >= current->_data) {
      current->_right = new Node(value);
      break;
    }

    if (current->_left == NULL && value < current->_data) {
      current->_left = new Node(value);
      break;
    }

    if (value >= current->_data) {
      current = current->_right;
    }

    if (value < current->_data) {
      current = current->_left;
    }
  }
}

void BSTree::printSorted() {
  printSorted(root);
}

// DFS
void BSTree::printSorted(Node* tree) {
  if (!tree) {
    return;
  }

  printSorted(tree->_left);
  cout << tree->_data << " ";
  printSorted(tree->_right);
}

#endif
