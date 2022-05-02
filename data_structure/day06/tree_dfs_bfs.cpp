#include <iostream>
#include <stack>
#include <queue>
#include "./tree.h"

using namespace std;

void dfs(Tree*);
void bfs(Tree*);

int main() {
  Tree* root = new Tree(1);
  root->_left = new Tree(2);
  root->_right = new Tree(3);
  root->_left->_left = new Tree(4);
  root->_left->_right = new Tree(5);
  root->_right->_left = new Tree(6);
  root->_right->_right = new Tree(7);

  cout << "DFS: ";
  dfs(root);

  cout << endl << "BFS: ";
  bfs(root);

  return 0;
}

/*
                 1
                / \
               /   \
              2     3
             / \   / \
            4   5  6  7
*/

void dfs(Tree* root) {
  if (!root) {
    return;
  }

  stack<Tree*> out;
  stack<Tree*> stack;
  stack.push(root);

  while (!stack.empty()) {
    Tree* current = stack.top();
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

void bfs(Tree* root) {
  if (!root) {
    return;
  }

  queue<Tree*> out;
  queue<Tree*> queue;
  queue.push(root);

  while (!queue.empty()) {
    Tree* current = queue.front();
    queue.pop();
    out.push(current);

    if (current->_left) {
      queue.push(current->_left);
    }

    if (current->_right) {
      queue.push(current->_right);
    }
  }

  while (!out.empty()) {
    cout << out.front()->_data << " ";
    out.pop();
  }
}
