#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

typedef struct{
    int items[SIZE], front, rear;
}queue;

queue* create_queue();
void enqueue(queue* q, int);
int dequeue(queue* q);
int is_empty(queue* q);
void print_queue(queue* q);

typedef struct _node{
    int vertex;
    struct _node* next;
} node;

node* createNode(int);

typedef struct {
    int vertex_count;
    node** node_adjacence_list;
    int* visited;
}graph;

void bfs(graph* g, int start_vertex) {
    queue* q = create_queue();

    g->visited[start_vertex] = 1;
    enqueue(q, start_vertex);

    while(!is_empty(q)) {
        print_queue(q);
        int current_vertex = dequeue(q);
        printf("Visited %d\n", current_vertex);

        node* temp = g->node_adjacence_list[current_vertex];
        while(temp) {
            int adjacent_vertex = temp->vertex;

            if(g->visited[adjacent_vertex] == 0) {
                g->visited[adjacent_vertex] = 1;
                enqueue(q, adjacent_vertex);
            }
            temp = temp->next;
        }
    }
}

node* create_node(int vertex) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

graph* create_graph(int vertex_count) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->vertex_count = vertex_count;
    g->node_adjacence_list = (node**)malloc(vertex_count * sizeof(node*));
    g->visited = (int*)malloc(vertex_count * sizeof(int));

    for (int i = 0; i < vertex_count; i++) {
        g->node_adjacence_list[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}

void add_edge(graph* g, int start_vertex, int end_vertex) {
    node* new_node = create_node(end_vertex);
    new_node->next = g->node_adjacence_list[start_vertex];
    g->node_adjacence_list[start_vertex] = new_node;

    new_node = create_node(start_vertex);
    new_node->next = g->node_adjacence_list[end_vertex];
    g->node_adjacence_list[end_vertex] = new_node;
}

queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty(queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(queue* q, int value) {
    if (q->rear == SIZE-1) {
        printf("Queue is full\n");
    }
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(queue* q) {
    int item;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        item = -1;
    }else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void print_queue(queue* q) {
    int i = q->front;

    if (is_empty(q)) {
        printf("Queue is empty\n");
    }else {
        printf("Queue contains\n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d \n", q->items[i]);
        }
    }
}

void dfs(graph* g, int start_vertex) {
    node* adjacence_list = g->node_adjacence_list[start_vertex];
    node* temp = adjacence_list;

    g->visited[start_vertex] = 1;
    printf("Visited %d \n", start_vertex);

    while(temp != NULL) {
        int connected_vertex = temp->vertex;

        if(g->visited[connected_vertex] == 0) {
            dfs(g, connected_vertex);
        }
        temp = temp->next;
    }
}

int main(void) {
    graph* g = create_graph(6);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    dfs(g, 0);

    return 0;
}
