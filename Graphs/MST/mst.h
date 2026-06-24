#ifndef MST_H
#define MST_H

#define VERTEX_COUNT 6
#define INFINITY 9999

typedef struct {
	int index;
	int adjacence_list[VERTEX_COUNT];
} vertex;

typedef struct {
	vertex vertex_list[VERTEX_COUNT];
} graph;

typedef struct {
	vertex *beg;
	int weight;
	vertex *end;
} edge;

int hoares_int(edge vector[], int low, int high);

void quick_sort_int(edge vector[], int low, int high);

vertex create_vertex(int index);

graph create_graph();

void clear_graph(graph *g);

int get_edges_size(graph *g);

void get_edges(graph *g, edge vector[]);

int find_set(int i, int parent[]);

void union_set(int i, int j, int parent[]);

void kruskal(graph *g, edge vector[], graph *mst);

void prims(graph *g, int start, int edge_weight_path[], graph *mst);

#endif