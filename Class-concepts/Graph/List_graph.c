//list representation of graph

#include<stdio.h>
#include<stdlib.h>

struct edge_node;

struct vertex_node
{
    int data;
    struct vertex_node* vertex_next;
    struct edge_node* edge_next;
};

struct edge_node
{
    struct edge_node* edge_next;
    struct vertex_node* vertex_next;
};


struct vertex_node* create_vertex(int data);
struct edge_node* create_edge(struct vertex_node* dest);
void add_vertex(struct vertex_node** head, int data);
void add_edge(struct vertex_node* head, int src, int dest);
struct vertex_node* find_vertex(struct vertex_node* head, int data);

int main() {
    struct vertex_node* graph = NULL;

    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_vertex(&graph, 3);
    add_vertex(&graph, 4);

    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    return 0;
}

struct vertex_node* create_vertex(int data) {
    struct vertex_node* new_vertex = (struct vertex_node*)malloc(sizeof(struct vertex_node));
    new_vertex->data = data;
    new_vertex->vertex_next = NULL;
    new_vertex->edge_next = NULL;
    return new_vertex;
}

struct edge_node* create_edge(struct vertex_node* dest) {
    struct edge_node* new_edge = (struct edge_node*)malloc(sizeof(struct edge_node));
    new_edge->vertex_next = dest;
    new_edge->edge_next = NULL;
    return new_edge;
}

void add_vertex(struct vertex_node** head, int data) {
    struct vertex_node* new_vertex = create_vertex(data);
    new_vertex->vertex_next = *head;
    *head = new_vertex;
}

struct vertex_node* find_vertex(struct vertex_node* head, int data) {
    struct vertex_node* temp = head;
    while (temp) {
        if (temp->data == data)
            return temp;
        temp = temp->vertex_next;
    }
    return NULL;
}

void add_edge(struct vertex_node* head, int src, int dest) {
    struct vertex_node* src_vertex = find_vertex(head, src);
    struct vertex_node* dest_vertex = find_vertex(head, dest);

    if (src_vertex == NULL || dest_vertex == NULL) {
        printf("Vertex not found.\n");
        return;
    }

    struct edge_node* new_edge = create_edge(dest_vertex);
    new_edge->edge_next = src_vertex->edge_next;
    src_vertex->edge_next = new_edge;
}

