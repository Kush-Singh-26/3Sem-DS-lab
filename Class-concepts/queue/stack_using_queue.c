#include<stdio.h>
#include<stdlib.h>

#define max 5

struct queue
{
    int q[max];    
    int f,r;
}*q1 = NULL, *q2 = NULL;

void initialize(struct queue* qu)
{
    qu->f = qu->r = -1;
}

void enqueue(struct queue* qu, int data)
{
    if(qu->r == max-1)
    {
        printf("Overflow\n");
        return;
    }
    if(qu->f == -1)
    {
        qu->f = 0;
    }
    qu->r++;
    qu->q[qu->r] = data;
}

void dequeue(struct queue* qu, int* data)
{
    if(qu->f == -1)
    {
        printf("Underflow\n");
        return;
    }

    *data = qu->q[qu->f];
    if(qu->f == qu->r)
    {
        qu->f = -1;
        qu->r = -1;
    }
    else   
        qu->f++;
}

void push(int data)
{
    enqueue(q1,data);
}

void pop(int* data)
{
    int temp;
    while(q1->f != q1->r)
    {
        dequeue(q1,&temp);
        enqueue(q2,temp);
    }

    dequeue(q1,data);

    struct queue* tempq = q1;
    q1 = q2;
    q2 = tempq;

}

int main()
{
    q1 = (struct queue*) malloc(sizeof(struct queue));
    q2 = (struct queue*) malloc(sizeof(struct queue));
    
    initialize(q1);
    initialize(q2);

     int data;
    push(10);
    push(20);
    push(30);
    pop(&data);
    printf("Popped: %d\n", data);  
    pop(&data);
    printf("Popped: %d\n", data);  
    pop(&data);
    printf("Popped: %d\n", data); 

    free(q1);
    free(q2);

    return 0;
}