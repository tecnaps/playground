//! header file for the graph implementation using an adjency matrix 

#ifndef GRAPH_ADJ_MAT_H_
#define GRAPH_ADJ_MAT_H_
#include <stdbool.h>

typedef struct mygraph graph;

//! create a new graph
graph *create_graph(int numnodes);
//! destroy a graph
void destroy_graph(graph* g);
//!print a graph
void print_graph(graph *g);
//! add an edge
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node);
//! check whether an edge exists
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node);

#endif