#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <climits>
#include <limits>

using namespace std;

#define MINUS_INFINITY numeric_limits<int>::min()

class Graph {
  private:
    int** _adjMatrix;
    int _verticesCount;

    void printShortestPaths(int*, bool*);
    int findNodeLowestDistance(int*, bool*);

  public:
    Graph(int);
    void addEdge(int, int, int);
    void printMatrix();
    void getShortestPath(int);
};

Graph::Graph(int size) {
  _verticesCount = size;
  _adjMatrix = new int*[size];
  for (int i = 0; i < size; i++) {
    _adjMatrix[i] = new int[size];
    for (int j = 0; j < size; j++) {
      _adjMatrix[i][j] = INT_MAX;
    }
  }
}

void Graph::addEdge(int weight, int first, int second) {
  _adjMatrix[first][second] = weight;
  _adjMatrix[second][first] = weight;
}

void Graph::printMatrix() {
  cout << " ";
  for (int i = 0; i < _verticesCount; i++) {
      cout << " " << i;
  }
  cout << endl;

  for (int i = 0; i < _verticesCount; i++) {
    cout << i << " ";
    for (int j = 0; j < _verticesCount; j++) {
      if (_adjMatrix[i][j] == INT_MAX) {
        cout << "∞";
      } else {
        cout << _adjMatrix[i][j];
      }

      cout << " ";
    }
    cout << endl;
  }
}

void Graph::printShortestPaths(int* distances, bool* isVisited) {
  cout << endl << "Visited: ";
  for (int i = 0; i < _verticesCount; i++) {
    cout << isVisited[i] << " ";
  }

  cout << endl << "Distances: ";
  for (int i = 0; i < _verticesCount; i++) {
    if (distances[i] == INT_MAX) {
      cout << "∞";
    } else {
      cout << distances[i];
    }

    cout << " ";
  }
}

int Graph::findNodeLowestDistance(int* distances, bool* isVisited) {
  int lowestDistance = INT_MAX;
  int lowestIndex = MINUS_INFINITY;

  for (int i = 0; i < _verticesCount; i++) {
    if (!isVisited[i] && distances[i] < lowestDistance) {
      lowestDistance = distances[i];
      lowestIndex = i;
    }
  }

  return lowestIndex;
}

void Graph::getShortestPath(int start) {
  int distances[_verticesCount];
  bool isVisited[_verticesCount];

  for (int i = 0; i < _verticesCount; i++) {
    distances[i] = _adjMatrix[start][i];
    isVisited[i] = false;
  }

  int node = findNodeLowestDistance(distances, isVisited);
  while (node != MINUS_INFINITY) {
    for (int i = 0; i < _verticesCount; i++) {
      int neighbor = _adjMatrix[node][i];
      int newDistance = distances[node] + (neighbor == INT_MAX ? 0 : neighbor);
      if (neighbor != INT_MAX && newDistance < distances[i]) {
        distances[i] = newDistance;
      }
    }

    isVisited[node] = true;
    node = findNodeLowestDistance(distances, isVisited);
  }

  printShortestPaths(distances, isVisited);
}

#endif
