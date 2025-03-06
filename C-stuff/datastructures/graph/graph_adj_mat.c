//! creates a graph using an adjency matrix

//! headers
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph_adj_mat.h"

//! defines the graph structure
struct mygraph{
    int numnodes;
    bool **edges; // double pointer (= 2D array)
};
//! create a new graph
graph *create_graph(int numnodes){
    graph *g = malloc(sizeof(*g));
    //! checks if there is a valid pointer to a graphj (memory allocated)
    if (g == NULL)
        return NULL;
    g->numnodes = numnodes;
    //! allocate memory for the adjacency matrix

    //! numnodes specifies the number of boolean pointers memory must be allocated for 
    //! A boolean pointer is used b/c the memory is for an array of booleans
    //! No initialization is needet b/c calloc initializes everything to 0

    g->edges = calloc(sizeof(bool*), g->numnodes); 

    //! cleanup if the allocation for the edges fails
    if (g->edges==NULL){
        free(g);
        return NULL;
    }

    //! creates (allocates memory for) the rows
    for (int i = 0; i < g->numnodes; i++){
        g->edges[i] = calloc(sizeof(bool), g->numnodes); 
        //! cleanup if the allocation for the row fails

        if(g->edges[i] == NULL){
            destroy_graph(g);
            return NULL;
        }
    }
    return g;

}

//! destroy a graph
void destroy_graph(graph* g){
    if (g->edges == NULL) {
        free(g);
        return;
    }

    //! cleans all the rows that have (already) been created (see above)

    for (int i = 0; i< g->numnodes; i++){
        if(g->edges[i]!= NULL)
            free(g->edges[i]);
    }

    free(g->edges);
    free(g);
}

//! prints the graph in dot format
void print_graph(graph *g){
    printf("digraph{\n");

    for(int from = 0; from < g->numnodes; from++){
        for(int to = 0; to < g ->numnodes; to++){
            if(g->edges[from][to]){
                printf("%d->%d;\n", from, to);
            }
        }
    }

    printf("}\n");
}

//! add an edge
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node){
    
    //! assertions to check for bugs
    assert(g != NULL);
    assert(from_node < g->numnodes);
    assert(to_node < g->numnodes);

    //! checks if the edge already exists; if so: returns false (no addition)

    if(has_edge(g, from_node, to_node)){
        return false;
    }

    g->edges[from_node][to_node] = true;
    return true;
}

//! check whether an edge exists
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node){

    //! assertions to check for bugs
    assert(g != NULL);
    assert(from_node < g->numnodes);
    assert(to_node < g->numnodes);

    return g->edges[from_node][to_node];
}