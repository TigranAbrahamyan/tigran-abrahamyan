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
    void insertRecursivePrivate(Node*, int);
    Node* deleteNodeRecursivePrivate(Node*, int);

  public:
    BSTree(int);
    void insert(int);
    void insertRecursive(int);
    void deleteNode(int);
    Node* deleteNodeRecursive(int);
    void printSorted();
};

BSTree::BSTree(int value) {
  root = new Node(value);
}

void BSTree::insert(int value) {
  if (!root) {
    root = new Node(value);
    return;
  }

  Node *current = root;

  while (current) {
    if (!current->_right && value >= current->_data) {
      current->_right = new Node(value);
      break;
    }

    if (!current->_left && value < current->_data) {
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

void BSTree::insertRecursive(int value) {
  if (root) {
    insertRecursivePrivate(root, value);
  } else {
    root = new Node(value);
  }
}

void BSTree::insertRecursivePrivate(Node* tree, int value) {
  if (value >= tree->_data && tree->_right) {
    insertRecursivePrivate(tree->_right, value);
  } else if (value >= tree->_data) {
    tree->_right = new Node(value);
  } else if (value < tree->_data && tree->_left) {
    insertRecursivePrivate(tree->_left, value);
  } else if (value < tree->_data) {
    tree->_left = new Node(value);
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

Node* BSTree::deleteNodeRecursive(int value) {
  if (root) {
    return deleteNodeRecursivePrivate(root, value);
  } else {
    return NULL;
  }
}

Node* BSTree::deleteNodeRecursivePrivate(Node* tree, int value) {
  if (value > tree->_data) {
    tree->_right = deleteNodeRecursivePrivate(tree->_right, value);
  } else if (value < tree->_data) {
    tree->_left = deleteNodeRecursivePrivate(tree->_left, value);
  } else {
    if (!tree->_left && !tree->_right) {
      tree = NULL;
    } else if (!tree->_right) {
      tree = tree->_left;
    } else {
      Node *min = tree->_right;
      while (min->_left) {
        min = min->_left;
      }

      tree->_data = min->_data;
      tree->_right = deleteNodeRecursivePrivate(tree->_right, min->_data);
    }
  }

  return tree;
}

void BSTree::printSorted() {
  printSorted(root);
}

void BSTree::printSorted(Node* tree) {
  if (tree) {
    printSorted(tree->_left);
    cout << tree->_data << " ";
    printSorted(tree->_right);
  }
}

#endif
