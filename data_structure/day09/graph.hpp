#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
  private:
    vector<vector<int>> adjMatrix;

    void outOfRangeException(int);

  public:
    Graph(int);
    void printMatrix();
    void addVertex();
    void addEdge(int, int);
    void addDirectionalEdge(int, int);
    void deleteVertex(int);
    void deleteEdge(int, int);
    void deleteDirectionalEdge(int, int);
    bool isConnected(int, int);
    void nodeNeighbours(int);
    void nodeConnections(int);
};

Graph::Graph(int size) {
  for (int i = 0; i < size; i++) {
    adjMatrix.push_back(vector<int>());
    for (int j = 0; j < size; j++) {
      adjMatrix[i].push_back(0);
    }
  }
}

void Graph::outOfRangeException(int index) {
  if (index > adjMatrix.size() || index < 0) {
    throw invalid_argument("Argument is out of range.");
  }
}

void Graph::printMatrix() {
  cout << " ";
  for (int i = 0; i < adjMatrix.size(); i++) {
    cout << " " << i;
  }
  cout << endl;

  for (int i = 0; i < adjMatrix.size(); i++) {
    cout << i << " ";
    for (int j = 0; j < adjMatrix.size(); j++) {
      cout << adjMatrix[i][j] << " ";
    }
    cout << endl;
  }
}

void Graph::addVertex() {
  adjMatrix.resize(adjMatrix.size() + 1);
  for (int i = 0; i < adjMatrix.size(); i++) {
    adjMatrix[i].resize(adjMatrix.size() + 1, 0);
  }
}

void Graph::addEdge(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);
  adjMatrix[first][second] = 1;
}

void Graph::addDirectionalEdge(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);
  adjMatrix[first][second] = 1;
  adjMatrix[second][first] = 1;
}

void Graph::deleteEdge(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);
  adjMatrix[first][second] = 0;
}

void Graph::deleteDirectionalEdge(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);
  adjMatrix[first][second] = 0;
  adjMatrix[second][first] = 0;
}

void Graph::deleteVertex(int vertex) {
  outOfRangeException(vertex);
  adjMatrix.erase(adjMatrix.begin() + vertex);
  for (int i = 0; i < adjMatrix.size(); i++) {
    adjMatrix[i].erase(adjMatrix[i].begin() + vertex);
  }
}

bool Graph::isConnected(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);

  return adjMatrix[first][second] == 1 && adjMatrix[second][first] == 1;
}

void Graph::nodeNeighbours(int vertex) {
  outOfRangeException(vertex);
  cout << "Neighbours of " << vertex << ": ";
  for (int i = 0; i < adjMatrix.size(); i++) {
    if (adjMatrix[vertex][i] == 1) {
      cout << i << " ";
    }
  }
  cout << endl;
}

void Graph::nodeConnections(int vertex) {
  outOfRangeException(vertex);
  cout << "Connections of " << vertex << ": ";
  for (int i = 0; i < adjMatrix.size(); i++) {
    if (adjMatrix[i][vertex] == 1) {
      cout << i << " ";
    }
  }
  cout << endl;
}

#endif
