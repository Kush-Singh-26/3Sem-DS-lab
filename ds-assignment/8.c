#include <stdio.h>
#include <stdlib.h>

struct edge_node;

struct vertex_node {
    int data;
    struct vertex_node* vertex_next;
    struct edge_node* edge_next;
};

struct edge_node {
    struct edge_node* edge_next;
    struct vertex_node* vertex_next;
};

struct vertex_node* create_vertex(int data);
struct edge_node* create_edge(struct vertex_node* dest);
void add_vertex(struct vertex_node** head, int data);
void add_edge(struct vertex_node* head, int src, int dest);
struct vertex_node* find_vertex(struct vertex_node* head, int data);
void bfs(struct vertex_node* head, int start);
void dfs(struct vertex_node* head, int start);
void dfs_util(struct vertex_node* vertex, int* visited);
void input_graph(struct vertex_node** graph);

int main() {
    struct vertex_node* graph = NULL;

    input_graph(&graph);

    int start;
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &start);

    printf("BFS from node %d:\n", start);
    bfs(graph, start);

    printf("\nDFS from node %d:\n", start);
    dfs(graph, start);
    printf("\n");

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

    new_edge = create_edge(src_vertex);
    new_edge->edge_next = dest_vertex->edge_next;
    dest_vertex->edge_next = new_edge;
}

void bfs(struct vertex_node* head, int start) {
    struct vertex_node* start_vertex = find_vertex(head, start);
    if (start_vertex == NULL) {
        printf("Start vertex not found.\n");
        return;
    }

    int visited[100] = {0};
    struct vertex_node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = start_vertex;
    visited[start_vertex->data] = 1;

    while (front < rear) {
        struct vertex_node* current = queue[front++];
        printf("%d ", current->data);

        struct edge_node* edge = current->edge_next;
        while (edge) {
            if (!visited[edge->vertex_next->data]) {
                visited[edge->vertex_next->data] = 1;
                queue[rear++] = edge->vertex_next;
            }
            edge = edge->edge_next;
        }
    }
}

void dfs(struct vertex_node* head, int start) {
    struct vertex_node* start_vertex = find_vertex(head, start);
    if (start_vertex == NULL) {
        printf("Start vertex not found.\n");
        return;
    }

    int visited[100] = {0};
    dfs_util(start_vertex, visited);
}

void dfs_util(struct vertex_node* vertex, int* visited) {
    visited[vertex->data] = 1;
    printf("%d ", vertex->data);

    struct edge_node* edge = vertex->edge_next;
    while (edge) {
        if (!visited[edge->vertex_next->data]) {
            dfs_util(edge->vertex_next, visited);
        }
        edge = edge->edge_next;
    }
}

void input_graph(struct vertex_node** graph) {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        int data;
        printf("Enter vertex %d: ", i + 1);
        scanf("%d", &data);
        add_vertex(graph, data);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        add_edge(*graph, src, dest);
    }
}
