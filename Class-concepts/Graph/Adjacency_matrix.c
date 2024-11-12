// directed graph

#include<stdio.h>
#include<stdlib.h>

#define max 5
void initialize(int graph[max][max]);
void add_edge(int graph[max][max], int a,int b);
void print_matrix(int graph[max][max]);


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
    for(int i =0;i<max;i++)
    {
        for(int j =0;j<max;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
