#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include "../day01/linked_list.hpp"

using namespace std;

class Graph {
  private:
    LinkedList<int>* _adjList;
    int _size;

    void outOfRangeException(int);
    void dfs(bool*, int);

  public:
    Graph();
    ~Graph();
    int getSize() const;
    void printList();
    void addNode();
    void addEdge(int, int);
    void removeNode(int);
    void removeEdge(int, int);
    bool isEdgeExist(int, int);
    void findNeighbours(int);
    void findConnections(int data);
};

Graph::Graph() {
  _size = 0;
  _adjList = new LinkedList<int>[_size];
}

Graph::~Graph() {
  _size = 0;
  delete[] _adjList;
}

void Graph::outOfRangeException(int index) {
  if (index > getSize() || index < 0) {
    throw invalid_argument("Argument is out of range.");
  }
}

void Graph::dfs(bool *isVisited, int node) {
  isVisited[node] = true;
  for (int i = 0; i < _adjList[node].getSize(); i++) {
    if (!isVisited[_adjList[node].getDataByIndex(i)]) {
      dfs(isVisited, _adjList[node].getDataByIndex(i));
    }
  }
}

int Graph::getSize() const {
  return _size;
}

void Graph::printList() {
  for (int i = 0; i < getSize(); i++) {
    cout << "[" << i << "] -> " << _adjList[i];
  }
}

void Graph::addNode() {
  LinkedList<int>* temp = new LinkedList<int>[getSize() + 1];
  for (int i = 0; i < getSize(); i++) {
    temp[i] = _adjList[i];
  }

  _adjList = temp;
  _size++;
}

void Graph::addEdge(int index, int node) {
  outOfRangeException(index);
  outOfRangeException(node);
  _adjList[index].add(node);
}

void Graph::removeNode(int node) {
  outOfRangeException(node);

  for (int i = 0; i < getSize(); i++) {
    if (_adjList[i].findNode(node)) {
      _adjList[i].remove(node);
    }
  }

  for (int i = node; i < getSize(); i++) {
    _adjList[i] = _adjList[i + 1];
  }

  _size--;
}

void Graph::removeEdge(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);

  if (_adjList[first].findNode(second)) {
    _adjList[first].remove(second);
  }

  if (_adjList[second].findNode(first)) {
    _adjList[second].remove(first);
  }
}

bool Graph::isEdgeExist(int first, int second) {
  outOfRangeException(first);
  outOfRangeException(second);

  Node<int>* firstEdge = _adjList[first].findNode(second);
  Node<int>* secondEdge = _adjList[second].findNode(first);

  return (firstEdge && secondEdge) && (firstEdge->_data == second && secondEdge->_data == first);
}

void Graph::findNeighbours(int node) {
  outOfRangeException(node);
  cout << "Neigbourds of " << node << ": " << _adjList[node];
}

void Graph::findConnections(int node) {
  outOfRangeException(node);

  cout << "Connections of " << node << ": ";
  bool* isVisited = new bool[getSize()];
  for (int i = 0; i < getSize(); i++) {
    isVisited[i] = false;
  }

  dfs(isVisited, node);

  for (int i = 0; i < getSize(); i++) {
    if (isVisited[i]) {
      cout << i << " ";
    }
  }
}

#endif
