#include "./graph.hpp"

int main() {
  Graph graph;
  graph.addNode();
  graph.addNode();
  graph.addNode();
  graph.addNode();
  graph.addNode();
  graph.addNode();
  graph.addEdge(0, 1);
  graph.addEdge(0, 3);
  graph.addEdge(1, 0);
  graph.addEdge(1, 3);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(2, 1);
  graph.addEdge(3, 0);
  graph.addEdge(3, 1);
  graph.addEdge(3, 2);
  graph.addEdge(4, 5);
  graph.addEdge(5, 4);
  graph.removeNode(3);
  graph.removeNode(0);
  graph.removeEdge(3, 0);
  graph.findNeighbours(0);
  graph.findConnections(0);
  cout << endl << "isEdgeExist(1, 2): " << graph.isEdgeExist(1, 2) << endl;
  graph.addEdge(2, 1);
  graph.addEdge(1, 2);
  cout << endl << "isEdgeExist(1, 2): " << graph.isEdgeExist(1, 2) << endl;
  graph.printList();

  return 0;
}
