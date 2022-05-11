#include "./graph.hpp"

int main() {
  int size;
  cout << "Size: ";
  cin >> size;

  Graph *graph = new Graph(size);
  graph->addEdge(7, 1, 2);
  graph->addEdge(9, 1, 3);
  graph->addEdge(14, 1, 6);
  graph->addEdge(10, 2, 3);
  graph->addEdge(15, 2, 4);
  graph->addEdge(11, 3, 4);
  graph->addEdge(2, 3, 6);
  graph->addEdge(6, 4, 5);
  graph->addEdge(9, 5, 6);
  graph->printMatrix();
  graph->getShortestPath(1);

  return 0;
}
