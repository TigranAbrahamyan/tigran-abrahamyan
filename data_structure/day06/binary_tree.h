#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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

class Tree {
  private:
    Node* root;

  public:
    Tree(int);
    void insert(int);
    int treeMinValue();
    int treeSum();
    void dfs();
    void bfs();
};

Tree::Tree(int value) {
  root = new Node(value);
}

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

int Tree::treeMinValue() {
  if (!root) {
    return 0;
  }

  int min = root->_data;
  queue<Node*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Node* current = queue.front();
    queue.pop();

    if (current->_data < min) {
      min = current->_data;
    }

    if (current->_left) {
      queue.push(current->_left);
    }

    if (current->_right) {
      queue.push(current->_right);
    }
  }

  return min;
}

int Tree::treeSum() {
  if (!root) {
    return 0;
  }

  int sum = 0;
  queue<Node*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Node* current = queue.front();
    queue.pop();
    sum += current->_data;

    if (current->_left) {
      queue.push(current->_left);
    }

    if (current->_right) {
      queue.push(current->_right);
    }
  }

  return sum;
}

void Tree::dfs() {
  if (!root) {
    return;
  }

  stack<Node*> out;
  stack<Node*> stack;
  stack.push(root);

  while (!stack.empty()) {
    Node* current = stack.top();
    stack.pop();
    out.push(current);

    if (current->_left) {
      stack.push(current->_left);
    }

    if (current->_right) {
      stack.push(current->_right);
    }
  }

  while (!out.empty()) {
    cout << out.top()->_data << " ";
    out.pop();
  }
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
