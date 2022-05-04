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
    void deleteNode(int);
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
    } else {
      current = current->_left;
    }
  }
}

void BSTree::deleteNode(int value) {
  if (!root) {
    return;
  }

  Node* current = root;
  Node* prev = NULL;

  while (current && current->_data != value) {
    prev = current;

    if (value > current->_data) {
      current = current->_right;
    } else {
      current = current->_left;
    }
  }

  if (!current->_left || !current->_right) {
    Node *newCurrent = current->_left ? current->_left : current->_right;

    if (prev->_left == current) {
      prev->_left = newCurrent;
    } else {
      prev->_right = newCurrent;
    }
  } else {
    Node* temp = current->_right;
    Node* min = NULL;

    while (temp->_left) {
      min = temp;
      temp = temp->_left;
    }

    if (!min) {
      current->_right = temp->_right;
    } else {
      min->_left = temp->_right;
    }

    current->_data = temp->_data;
  }
}

void BSTree::printSorted() {
  printSorted(root);
}

void BSTree::printSorted(Node* tree) {
  if (!tree) {
    return;
  }

  printSorted(tree->_left);
  cout << tree->_data << " ";
  printSorted(tree->_right);
}

#endif
