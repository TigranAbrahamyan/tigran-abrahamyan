#include <iostream>
#include <queue>
#include "./tree.h"

using namespace std;

void insert(Tree*, int);
int treeMinValue(Tree*);
int treeSum(Tree*);

int main() {
  Tree* root = new Tree(1);
  insert(root, 2);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  insert(root, 6);
  insert(root, 7);

  cout << "Min: " << treeMinValue(root) << endl;
  cout << "Sum: " << treeSum(root) << endl;

  insert(root, 8);
  insert(root, -10);

  cout << endl << root->_left->_left->_left->_data << endl;
  cout << root->_left->_left->_right->_data << endl;

  cout << endl << "Min: " << treeMinValue(root) << endl;
  cout << "Sum: " << treeSum(root) << endl;

  return 0;
}

/*
                 1
                / \
               /   \
              2     3
             / \   / \
            4   5  6  7
           / \
          8  -10
*/

void insert(Tree* root, int value) {
  if (!root) {
    return;
  }

  queue<Tree*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Tree* current = queue.front();
    queue.pop();

    if (current->_left) {
      queue.push(current->_left);
    } else {
      current->_left = new Tree(value);
      break;
    }

    if (current->_right) {
      queue.push(current->_right);
    } else {
      current->_right = new Tree(value);
      break;
    }
  }
}

int treeMinValue(Tree* root) {
  if (!root) {
    return 0;
  }

  int min = root->_data;
  queue<Tree*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Tree* current = queue.front();
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

int treeSum(Tree* root) {
  if (!root) {
    return 0;
  }

  int sum = 0;
  queue<Tree*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Tree* current = queue.front();
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
