#include <include/graph.h>

#include <algorithm>
#include <map>

namespace gs {

struct VertexComp {
  bool operator()(const Vertex& a, const Vertex& b) const {
    return a.id < b.id;
  }
};

struct EdgeComp {
  bool operator()(const Edge& a, const Edge& b) const {
    if (a.isDirected != b.isDirected) {
      return false;
    }

    return a.vertices.first.id < b.vertices.first.id;
  }
};

class Graph::D {
public:
  D() : vertexTables(),
        edgeTables(),
        isTablesInitialized(false) {}
  ~D() {}



  std::map<Vertex, VertexTableRow, VertexComp> vertexTables;

  std::map<Edge, EdgeTableRow, EdgeComp> edgeTables;

  bool isTablesInitialized;

  void initializeTables() {

  }

  bool isEdgeUsed(const Edge& edge) {
    return edgeTables[edge].isUsed;
  }

  void setEdgeUsed(const Edge& edge) {
    edgeTables[edge].isUsed = true;
  }

  Vertex secondEndpoint(const Edge& e) {
    return e.vertices.second;
  }
};

Graph::Graph(const std::vector<const Edge>& edges) : d(new D()) {
  std::copy(edges.begin(), edges.end(), edges_.begin());
}

void Graph::trace(Vertex startVertex, Path& path) {
  if (!d->isTablesInitialized) {
    d->initializeTables();
  }

  Vertex currentVertex = startVertex;

  while (d->vertexTables[currentVertex].currentEdge != NilEdge) {

    auto currentVertexTableRow = d->vertexTables[currentVertex];

    Edge e = currentVertexTableRow.currentEdge;

    if (d->isEdgeUsed(e)) {
      auto currentEdgeIterator = std::find(currentVertexTableRow.incidentEdges.begin(),
                                           currentVertexTableRow.incidentEdges.end(),
                                           e);
      Edge nextEdge = *(currentEdgeIterator++);

    }
    else {
      currentVertexTableRow.currentEdge = e;
      d->setEdgeUsed(e);
      path.edges.push_back(e);
    }
  }
}

Graph::~Graph() {}

} // namespace gs {
