#include <stdio.h>
#define VERTEX_COUNT 6
#define INFINITY 9999

typedef struct{
    int index;
    int adjacence_list[VERTEX_COUNT];
}vertex;

typedef struct{
    vertex vertex_list[VERTEX_COUNT];
}graph;

vertex create_vertex(int index){
    vertex v;
    v.index = index;
    int edge_weight = 0;
    for(int i = 0; i < VERTEX_COUNT;i++){
        printf("From %d to %d\n", index, i);
        scanf("%d", &edge_weight);
        if(edge_weight >= 9999){
            v.adjacence_list[i] = INFINITY;
        }else{
            v.adjacence_list[i] = edge_weight;
        }
    }
    return v;
}

graph create_graph(){
    graph g;
    for(int i = 0; i < VERTEX_COUNT; i++){
        printf("Adjacence list for vertex %d\n", i);
        printf("For no connection type 9999\n", i);
        g.vertex_list[i] = create_vertex(i);
    }
    return g;
}

void clear_graph(graph *g){
    for(int i = 0; i < VERTEX_COUNT; i++){
        g->vertex_list[i].index = i;
        for(int j = 0; j < VERTEX_COUNT; j++){
            g->vertex_list[i].adjacence_list[j] = INFINITY;
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
        
        int v;
        
        for(v = 0; v < VERTEX_COUNT; v++){
            if(added[v] == 0 && edge_weight_path[v] < smalest){
                smalest = edge_weight_path[v];
                u = v;
            }
        }
        
        if(u == -1){
            break;
        }
        
        added[u] = 1;
        
        for(v = 0; v < VERTEX_COUNT; v++){
            if(g->vertex_list[u].adjacence_list[v] != INFINITY && added[v] == 0 && g->vertex_list[u].adjacence_list[v] < edge_weight_path[v]){
                parent[v] = u;
                edge_weight_path[v] = g->vertex_list[u].adjacence_list[v];
            }
        }
    }
    
    for(v = 0; v < VERTEX_COUNT; v++){
        if(parent[v] != -1){
            mst->vertex_list[parent[v]].adjacence_list[v] = g->vertex_list[parent[v]].adjacence_list[v];
        }
    }

}

int main()
{
    printf("Hello World");

    return 0;
}