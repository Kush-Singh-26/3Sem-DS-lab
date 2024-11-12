#include<stdio.h>
#include<stdlib.h>

#define max 5
void initialize(int graph[max][max]);
void add_edge(int graph[max][max], int a,int b);
void print_matrix(int graph[max][max]);

struct queue
{
    int item[max];
    int front,rear;
};

void initialize_queue(struct queue* q);
void enqueue(struct queue* q, int data);
int dequeue(struct queue* q);

void BFS(int graph[max][max], int start_index);

int main()
{
    int graph[max][max];
    initialize(graph);

    printf("Enter number of edges : ");
    int edge; scanf("%d",&edge);

    printf("Enter the edges in the format (v1,v2) [v1 -> v2] \n");
    int a,b;
    for(int i =0;i<edge;i++)
    {
        scanf("%d%d",&a,&b);
        add_edge(graph,a,b);
    }

    printf("Adjacenct matrix :\n");
    print_matrix(graph);

    printf("Enter starting index for BFS : ");
    int start; scanf("%d",&start);

    BFS(graph,start-1);

    return 0;
}

void initialize(int graph[max][max])
{
    for(int i =0;i<max;i++)
        for(int j =0;j<max;j++)
            graph[i][j] = 0;
}

void add_edge(int graph[max][max], int a,int b)
{
    graph[a-1][b-1] = 1;
}

void print_matrix(int graph[max][max])
{
    printf(" ");
    for(int i = 1;i<=max;i++) printf(" %d",i);
    printf("\n");

    for(int i =0;i<max;i++)
    {
        printf("%d ",i+1);
        for(int j =0;j<max;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void initialize_queue(struct queue* q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct queue* q, int data)
{
    if(q->rear == max-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if(q->front == -1)
        q->front = 0;
    
    q->rear++;
    q->item[q->rear] = data;
}

int dequeue(struct queue* q)
{
    if(q->front == -1)
    {
        printf("Under flow\n");
        return -1;
    }

    int data = q->item[q->front];
    if(q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
        q->front++;
    return data;
}

void BFS(int graph[max][max], int start_index)
{
    int visited[max] = {0};
    struct queue q;
    initialize_queue(&q);

    visited[start_index] = 1;
    enqueue(&q,start_index);

    while (q.front != -1)
    {
        int current = dequeue(&q);
        printf("%d ",current+1);

        for(int i =0;i<max;i++)
        {
            if((graph[current][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1;
                enqueue(&q,i);
            }
        }   
    }
    printf("\n");
}