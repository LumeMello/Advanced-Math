#include <stdio.h>
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

int hoares_int(edge vector[], int low, int high) {
	int pivot = vector[low].weight;
	int i = low - 1;
	int j = high + 1;

	while(1) {
		do {
			i++;
		} while(vector[i].weight<pivot);

		do {
			j--;
		} while(vector[j].weight>pivot);

		if(i>=j) {
			return j;
		}

		edge aux = vector[i];
		vector[i] = vector[j];
		vector[j] = aux;
	}

}

void quick_sort_int(edge vector[], int low, int high) {
	if(low < high) {
		int pi = hoares_int(vector,low,high);

		quick_sort_int(vector, low, pi);
		quick_sort_int(vector,pi + 1, high);
	}
}



vertex create_vertex(int index) {
	vertex v;
	v.index = index;
	int edge_weight = 0;
	for(int i = 0; i < VERTEX_COUNT; i++) {
		printf("From %d to %d\n", index, i);
		scanf("%d", &edge_weight);
		if(edge_weight >= 9999) {
			v.adjacence_list[i] = INFINITY;
		} else {
			v.adjacence_list[i] = edge_weight;
		}
	}
	return v;
}

graph create_graph() {
	graph g;
	for(int i = 0; i < VERTEX_COUNT; i++) {
		printf("Adjacence list for vertex %d\n", i);
		printf("For no connection type 9999\n", i);
		g.vertex_list[i] = create_vertex(i);
	}
	return g;
}

void clear_graph(graph *g) {
	for(int i = 0; i < VERTEX_COUNT; i++) {
		g->vertex_list[i].index = i;
		for(int j = 0; j < VERTEX_COUNT; j++) {
			g->vertex_list[i].adjacence_list[j] = INFINITY;
		}
	}
}

int get_edges_size(graph *g) {
	int qt = 0;
	for(int i = 0; i < VERTEX_COUNT; i++) {
		for(int j = i + 1; j < VERTEX_COUNT; j++) {
			if(g->vertex_list[i].adjacence_list[j] != INFINITY) {
				qt++;
			}
		}
	}

	return qt;
}

void get_edges(graph *g, edge vector[]){
    int index = 0;
    for(int i = 0; i < VERTEX_COUNT; i++) {
		for(int j = i + 1; j < VERTEX_COUNT; j++) {
			if(g->vertex_list[i].adjacence_list[j] != INFINITY){
			    vector[index].beg = &(g->vertex_list[i]);
			    vector[index].end = &(g->vertex_list[j]);
			    vector[index].weight = g->vertex_list[i].adjacence_list[j];
			    index++;
			}
		}
	}
}

int find_set(int i, int parent[]){
    if (parent[i] == -1){
        return i;
    }
    return parent[i] = find_set(parent[i], parent);
}

void union_set(int i, int j, int parent[]){
    int root_i = find_set(i,parent);
    int root_j = find_set(j,parent);
    if(root_i != root_j){
        parent[root_i] = root_j;
    }
}

void kruskal(graph *g, edge vector[], graph *mst){
    int edge_vector_size = get_edges_size(g);
    quick_sort_int(vector,0,edge_vector_size - 1);
    
    clear_graph(mst);
    
    int parent[VERTEX_COUNT];
    for(int i = 0; i < VERTEX_COUNT; i++) {
        parent[i] = -1;
    }
    
    int edges_count =0;
    for(int j = 0; j < edge_vector_size; j++){
        int u = vector[j].beg->index;
        int v = vector[j].end->index;
        
        if(find_set(u, parent) != find_set(v,parent)){
            
            mst->vertex_list[u].adjacence_list[v] = vector[j].weight;
            mst->vertex_list[v].adjacence_list[u] = vector[j].weight;
            
            union_set(u, v, parent);
            
            edges_count++;
            if(edges_count == VERTEX_COUNT - 1){
                break;
            }
        }
    }
    
}

int main()
{
	printf("Hello World");

	return 0;
}