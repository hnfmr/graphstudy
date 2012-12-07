#ifndef GRAPH_STUDY_GRAPH_H_
#define GRAPH_STUDY_GRAPH_H_

#include <utility>
#include <vector>
#include <memory>

namespace gs {

struct Vertex {
  int id;
};

constexpr Vertex Nil = {-1};

bool operator==(const Vertex& v1, const Vertex& v2) {
  return v1.id == v2.id;
}

struct Edge {
  std::pair<Vertex, Vertex> vertices;
  bool isDirected;
};

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

class Graph {
public:
  Graph() {}
  ~Graph() {}

  std::vector<std::unique_ptr<Vertex> > vertices_;
  std::vector<Edge> edges_;
};

struct VertexTableRow {
  std::vector<std::shared_ptr<Edge> > incidentEdges_;
  std::shared_ptr<Edge> currentEdge_;
};

struct EdgeTableRow {
  Vertex first;
  Vertex second;
  bool isUsed;
};
} // namespace gl {
#endif
