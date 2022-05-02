#ifndef TREE_H
#define TREE_H

class Tree {
  public:
    int _data;
    Tree* _left;
    Tree* _right;

    Tree(int data, Tree* left = NULL, Tree* right = NULL) {
      _data = data;
      _left = left;
      _right = right;
    }
};

#endif
