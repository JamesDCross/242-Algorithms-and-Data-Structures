#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct graphrec *graph;
typedef struct vertex *vertex;
typedef enum { UNVISITED , VISITED_SELF , VISITED_DESCENDANTS } state_t;


extern void graph_free(graph g);
extern void graph_directional_edge(graph g, int u, int v);
extern void graph_bidirectional_edges(graph g, int u, int v);
extern graph graph_new(int vertices);
extern void graph_print(graph g);
extern void graph_dfs(graph g);

#endif
