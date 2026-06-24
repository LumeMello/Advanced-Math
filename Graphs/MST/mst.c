#include <stdio.h>
#include "mst.h"




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
		printf("For no connection type 9999\n");
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

    if (edge_vector_size <= 0) {
        return;
    }	
    
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

void prims(graph *g, int start, int edge_weight_path[], graph *mst){
    int added[VERTEX_COUNT];
    int parent[VERTEX_COUNT];
    int smalest = INFINITY;
    int u;
    
    clear_graph(mst);
    
    for(int i =0; i < VERTEX_COUNT; i++){
        if(i==start){
            edge_weight_path[i] = 0;
        }else{
            edge_weight_path[i] = INFINITY;
        }
        added[i] = 0;
        parent[i] = -1;
    }

    
    for(int j = 0; j < VERTEX_COUNT; j++){
        u = -1;
        smalest = INFINITY;
        
        
        for(int v = 0; v < VERTEX_COUNT; v++){
            if(added[v] == 0 && edge_weight_path[v] < smalest){
                smalest = edge_weight_path[v];
                u = v;
            }
        }
        
        if(u == -1){
            break;
        }
        
        added[u] = 1;
        
        for(int v = 0; v < VERTEX_COUNT; v++){
            if(g->vertex_list[u].adjacence_list[v] != INFINITY && added[v] == 0 && g->vertex_list[u].adjacence_list[v] < edge_weight_path[v]){
                parent[v] = u;
                edge_weight_path[v] = g->vertex_list[u].adjacence_list[v];
            }
        }
    }
    
    for(int v = 0; v < VERTEX_COUNT; v++){
        if(parent[v] != -1){
            int p = parent[v];
            int peso = g->vertex_list[p].adjacence_list[v];
            mst->vertex_list[p].adjacence_list[v] = peso;
            mst->vertex_list[v].adjacence_list[p] = peso;
        }
    }

}