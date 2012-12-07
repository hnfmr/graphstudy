#ifndef GRAPH_STUDY_GRAPH_H_
#define GRAPH_STUDY_GRAPH_H_

#include <utility>
#include <vector>
#include <memory>

namespace gs {

struct Vertex {
  int id;
};

const Vertex Nil = {-1};

bool operator==(const Vertex& v1, const Vertex& v2) {
  return v1.id == v2.id;
}

struct Edge {
  std::pair<Vertex, Vertex> vertices;
  bool isDirected;
};

const Edge NilEdge = {std::make_pair(Nil, Nil), false};

bool operator==(const Edge& e1, const Edge& e2) {
  // Cannot compare edges from digraph and undirected graph.
  if (e1.isDirected != e2.isDirected) {
    return false;
  }

  bool e1EqualsE2 = (e1.vertices.first == e2.vertices.first)
      && (e1.vertices.second == e2.vertices.second);

  // For digraph, we compare both start vertices and end vertices.
  if (e1.isDirected) {
    return e1EqualsE2;
  }
  // For undirected graph, we compare either vertices of two edges.
  else {
    return e1EqualsE2 || (e1.vertices.first == e2.vertices.second
                          && e1.vertices.second == e2.vertices.first);
  }
}

struct Path {
  std::vector<const Edge> edges;
};

struct VertexTableRow {
  std::vector<const Edge> incidentEdges;
  Edge currentEdge;
};

struct EdgeTableRow {
  Vertex first;
  Vertex second;
  bool isUsed;
};

class Graph {
public:
  Graph(const std::vector<const Edge>& edges);
  ~Graph();

  void trace(Vertex startVertex, Path& path);

private:
  std::vector<Edge> edges_;
  class D;
  std::unique_ptr<D> d;
};


} // namespace gl {
#endif
