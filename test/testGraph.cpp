#include <gtest/gtest.h>
#include <include/graph.h>

/**
 * Tests Vertex, Edge and other related data structures.
 */

TEST(GraphTest, Equalities) {
  gs::Vertex v1 = {1};
  gs::Vertex v2 = {2};

  ASSERT_FALSE(v1 == v2);

  ASSERT_FALSE(gs::Nil == v1);

  gs::Vertex v3 = {3};
  gs::Vertex v4 = {3};

  ASSERT_TRUE(v3 == v4);

  gs::Edge e1 = {std::make_pair(v1, v2), true};
  gs::Edge e2 = {std::make_pair(v3, v4), true};

  ASSERT_FALSE(e1 == e2);

  gs::Edge e3 = {std::make_pair(v1, v2), false};
  gs::Edge e4 = {std::make_pair(v2, v1), false};

  ASSERT_TRUE(e3 == e4);

  e3.isDirected = true;
  e4.isDirected = true;

  ASSERT_FALSE(e3 == e4);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int rc = RUN_ALL_TESTS();
  return rc;
}
