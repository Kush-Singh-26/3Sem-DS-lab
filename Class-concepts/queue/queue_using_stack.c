#include<stdio.h>
#include<stdlib.h>

#define max 10
struct stac
{
    int st[max];
    int top;
} *s1 = NULL, *s2 = NULL;

void initialize(struct stac* s)
{
    s->top = -1;
}

void push(struct stac* s, int data)
{
    if(s->top == max-1)
    {
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->st[s->top] = data;
}

void pop(struct stac* s, int* data)
{
    if(s->top == -1)
    {
        printf("Under flow\n");
        return;
    }

    *data = s->st[s->top];
    s->top--;
}

void enqueue(int data)
{
    push(s1,data);
}

void dequeue(int* data)
{
    int temp;
    while(s1->top != -1)
    {
        pop(s1,&temp);
        push(s2,temp);
    }
    pop(s2,data);
    while(s2->top != -1)
    {
        pop(s2,&temp);
        push(s1,temp);
    }
}

int main() {
    s1 = (struct stac*)malloc(sizeof(struct stac));
    s2 = (struct stac*)malloc(sizeof(struct stac));

    initialize(s1);
    initialize(s2);

    enqueue(10);
    enqueue(20);
    enqueue(30);

    int data;
    dequeue(&data);
    printf("Dequeued: %d\n", data);

    dequeue(&data);
    printf("Dequeued: %d\n", data);

    free(s1);
    free(s2);

    return 0;
}