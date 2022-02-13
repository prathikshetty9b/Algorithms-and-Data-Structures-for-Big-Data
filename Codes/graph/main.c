#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"



void test_graph() {
    Graph g1 = graph_new(6);
    Graph *g = &g1;
    g = graph_adjacencylist(g);

    //g = graph_dfs(g, 0);
    g = graph_bfs(g, 0);

}
int main()
{
    test_graph();
    return 0;
}
