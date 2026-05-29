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

void bellman_ford(graph *g, int start, int edge_weight_path[]){
    
    for(int i =0; i < VERTEX_COUNT; i++){
        if(i==start){
            edge_weight_path[i] = 0;
        }else{
            edge_weight_path[i] = INFINITY;
        }
    }
    
    for(int w =0; w < VERTEX_COUNT; w++){
        for(int u = 0; u < VERTEX_COUNT; u++){
            for(int v = 0; v < VERTEX_COUNT; v++){
                if(w < VERTEX_COUNT - 1){
                    if(g->vertex_list[u].adjacence_list[v] != INFINITY && edge_weight_path[u] != INFINITY){
                        if(edge_weight_path[u] + g->vertex_list[u].adjacence_list[v] < edge_weight_path[v]){
                            edge_weight_path[v] = edge_weight_path[u] + g->vertex_list[u].adjacence_list[v];
                        }
                    }
                }
                
                if(w == VERTEX_COUNT - 1){
                    if(g->vertex_list[u].adjacence_list[v] != INFINITY && edge_weight_path[u] != INFINITY){
                        if(edge_weight_path[u] + g->vertex_list[u].adjacence_list[v] < edge_weight_path[v]){
                            printf("Negative cycle");
                            return;
                        }
                    }
                }
                
            }
        }
    }
}

int main(){
    int start = 0;
    printf("From which vertex do you want to start?\n");
    do{
        if(start < 0 || start > VERTEX_COUNT){
            printf("Value not supported\n");
        }
        scanf("%d", &start);
    }while(start < 0 || start >= VERTEX_COUNT);
    
    graph g = create_graph();
    
    int result[VERTEX_COUNT];
    
    bellman_ford(&g, start,result);

    for(int i = 0; i < VERTEX_COUNT;i++){
        printf(" %d ", result[i]);
    }
    
    return 0;
}
