#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct _node_ Node;
typedef struct _graph_ Graph;

struct _node_ {
    int     node_id;
    Node    *next;
};

struct _graph_ {
    int     size;
    Node    **neighbours;
};

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

int visited[MAX_SIZE];


Graph   graph_new(int size);
Graph*  graph_adjacencylist(Graph *g);
Graph*  graph_dfs(Graph *g, int node_id);
Graph*  graph_bfs(Graph *g, int node_id);

#endif // GRAPH_H_INCLUDED
