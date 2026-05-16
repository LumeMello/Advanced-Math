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
        if(edge_weight < 0){
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
        printf("For no connection type -1\n", i);
        g.vertex_list[i] = create_vertex(i);
    }
    return g;
}

void dijkstra(graph *g, int start, int edge_weight_path[]){
    int visited[VERTEX_COUNT];
    int smalest = INFINITY;
    
    for(int i =0; i < VERTEX_COUNT; i++){
        if(i==start){
            edge_weight_path[i] = 0;
        }else{
            edge_weight_path[i] = INFINITY;
        }
        visited[i] = 0;
    }
    
    for(int w =0; w < VERTEX_COUNT; w++){
        visited[start] = 1;
        smalest = INFINITY;
        
        for(int j = 0; j < VERTEX_COUNT; j++){
            if((edge_weight_path[j] > (g->vertex_list[start].adjacence_list[j] + edge_weight_path[start] )) && (visited[j] != 1) && (g->vertex_list[start].adjacence_list[j] != INFINITY)){
                edge_weight_path[j] = g->vertex_list[start].adjacence_list[j] + edge_weight_path[start];
            }
        }
        
        for(int k = 0; k < VERTEX_COUNT;k++){
            if((edge_weight_path[k] < smalest) && (visited[k] != 1)){
                smalest = edge_weight_path[k];
                start = k;
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
    dijkstra(&g, start,result);
    
    for(int i = 0; i < VERTEX_COUNT;i++){
        printf(" %d ", result[i]);
    }
    
    return 0;
}