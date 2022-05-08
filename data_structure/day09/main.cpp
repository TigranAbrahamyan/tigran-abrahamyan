#include "graph.hpp"

int main() {
  srand(time(0));

  int size;
  cout << "Size: ";
  cin >> size;

  Graph *graph = new Graph(size);

  graph->printMatrix();
  graph->addDirectionalEdge(1, 2);
  graph->addDirectionalEdge(3, 4);
  graph->addVertex();
  graph->addEdge(3, 0);
  graph->addEdge(2, 3);
  graph->addEdge(4, 2);
  graph->addEdge(1, 2);
  graph->addEdge(3, 2);
  graph->addEdge(0, 2);
  graph->addVertex();
  graph->printMatrix();
  graph->deleteEdge(4, 5);
  graph->deleteDirectionalEdge(1, 2);
  graph->deleteVertex(5);
  graph->printMatrix();
  graph->nodeNeighbours(3);
  graph->nodeConnections(2);

  return 0;
}
