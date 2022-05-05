#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <vector>

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

class Tree {
  public:
    Node* root;

    void insert(int);
    int getRootInMatrix(int**, int);
    bool isMatrixBinaryTree(int**, int, vector<int>&);
    void bfs();
};

void Tree::insert(int value) {
  if (!root) {
    root = new Node(value);
    return;
  }

  queue<Node*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Node* current = queue.front();
    queue.pop();

    if (current->_left) {
      queue.push(current->_left);
    } else {
      current->_left = new Node(value);
      break;
    }

    if (current->_right) {
      queue.push(current->_right);
    } else {
      current->_right = new Node(value);
      break;
    }
  }
}

int Tree::getRootInMatrix(int** arr, int size) {
  int rootsCount = 0;
  int rootIndex = -1;

  for (int i = 0; i < size; i++) {
    int count = 0;

    for (int j = 0; j < size; j++) {
      if (arr[j][i] == 0) {
        count++;
      }

      if (count == size) {
        rootsCount++;
        rootIndex = rootsCount > 1 ? -1 : i;
      }
    }
  }

  return rootIndex;
}

bool Tree::isMatrixBinaryTree(int** arr, int size, vector<int>& nodes) {
  int rootIndex = getRootInMatrix(arr, size);

  for (int i = 0; i < size; i++) {
    int count = 0;

    for (int j = 0; j < size; j++) {
      if ((arr[i][j] == 1 && arr[j][i] == 1) || rootIndex == -1 || count > 2) {
        return false;
      }

      if (arr[i][j] == 1) {
        count++;
        nodes.push_back(j);
      }
    }
  }

  root = new Node(rootIndex);

  return true;
}

void Tree::bfs() {
  if (!root) {
    return;
  }

  queue<Node*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Node* current = queue.front();
    queue.pop();
    cout << current->_data << " ";

    if (current->_left) {
      queue.push(current->_left);
    }

    if (current->_right) {
      queue.push(current->_right);
    }
  }
}

#endif
