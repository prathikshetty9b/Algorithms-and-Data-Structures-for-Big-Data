#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include <stdio.h>
#include "../genericQueue/genericqueue.h"

Graph   graph_new(int size){
    Graph g;
    g.size = size;
    g.neighbours = (Node**)malloc(g.size * sizeof(Node*));

    for(int i = 0; i <g.size; ++i){
        g.neighbours[i] = NULL;
        visited[i] = FALSE;
    }

    return g;
}

static Node*    _create_new_node_(int id){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->node_id = id;
    newnode->next = NULL;

    return newnode;
}

static int _get_neighbour_(int id){
    int neighbour_id;
    printf("Enter neighbour of node %d, if no further neighbours enter 9999\n", id);
    scanf("%d",&neighbour_id);

    return neighbour_id;
}

static int 	_get_neighbour_cost_(int node) {
	int edge_cost;
	printf("Enter the edge cost %d.\n",node );
	scanf ("%d",&edge_cost);

	return edge_cost;
}

Graph*  graph_adjacencylist(Graph *g){
    assert(g != NULL);
    int neighbour_id;
    int edge_cost;
    Node *vertex, *lastvertex;

    for(int i=0; i < g->size; ++i){
        g->neighbours[i] = _create_new_node_(i);
        neighbour_id = _get_neighbour_(i);

        while(neighbour_id != 9999){
            vertex = _create_new_node_(neighbour_id);
            edge_cost = _get_neighbour_cost_(neighbour_id);
			vertex->cost = edge_cost;

            if(g->neighbours[i]->next == NULL){
                g->neighbours[i]->next = vertex;
            } else{
                lastvertex->next = vertex;
            }
            lastvertex = vertex;
            neighbour_id = _get_neighbour_(i);
        }
    }
    return g;
}

static void _dfs_(Graph *g, int id){
    printf ("%d\t", id);
    visited[id] = TRUE;

    for (Node* vertex = g->neighbours[id]; vertex!=NULL; vertex = vertex->next){
        if (!visited[vertex->node_id]){
            _dfs_(g, vertex->node_id);
        }
    }

}

Graph* graph_dfs(Graph *g, int id){
    assert (g != NULL);
    for (int i = 0; i < g->size; ++i){
        visited[i] = FALSE;
    }
    _dfs_(g, id);

    return g;
}


Graph*  graph_bfs(Graph *g, int id){
    assert(g!=NULL);
    for(int i = 0; i<g->size;++i){
        visited[i] = FALSE;
    }

    Queue q1 = queue_new(g->size);
    Queue *q = &q1;
    QueueResult res;

    queue_add(q, &res, g->neighbours[id]);
    printf("\n");
    printf("%d\t", id);
    visited[id] = TRUE;
    while(!queue_empty(q)){
        queue_delete(q, &res);
        Node *node = (Node*)res.data;

        for(Node *vertex = g->neighbours[node->node_id]; vertex!= NULL; vertex = vertex->next){
            if (!visited[vertex->node_id]){
                printf("%d\t", vertex->node_id);
                visited[vertex->node_id] = TRUE;
                queue_add(q, &res, vertex);
            }
        }
    }

    return g;
}


