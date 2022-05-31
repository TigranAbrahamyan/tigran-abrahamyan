#include "./composite.hpp"

int main() {
  const int rows = 4;
  const int cols = 3;
  Composite containers[rows];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      containers[i].add(new Leaf(i * cols + j));
    }
  }

  for (int i = 1; i < rows; i++) {
    containers[0].add(&containers[i]);
  }

  for (int i = 0; i < rows; i++) {
    containers[i].traverse();
    cout << endl;
  }

  return 0;
}
