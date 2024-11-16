#include<stdio.h>
#include<stdlib.h>

#define size 20
#define no_dq 4
#define dq_size size/no_dq

struct queue
{
    int q[size];
    int front[no_dq];
    int rear[no_dq];
};

void initialize(struct queue* dq)
{
    for(int i =0;i<no_dq;i++)
    {
        dq->front[i] = -1;
        dq->rear[i] = -1;
    }
}

int isEmpty(struct queue* dq, int q_no)
{
    if(dq->front[q_no] == -1)   return 1;
    return 0;
}

int isFull(struct queue* dq, int q_no)
{
    int start = q_no * dq_size;
    int end = start + dq_size -1;
    return ((dq->rear[q_no] )+ 1 == dq->front[q_no]) || (dq->rear[q_no] == end && dq->front[q_no] == start);
}

void enqueue_front(struct queue* dq, int q_no, int data)
{
    int start = q_no * dq_size;
    int end = start + dq_size -1;

    if(isFull(dq,q_no))
    {
        printf("D-queue %d is full \n",q_no);
        return;
    }

    if(isEmpty(dq,q_no))
        dq->front[q_no] = dq->rear[q_no] = start;
    else
    {
        dq->front[q_no]--;
        if(dq->front[q_no] < start)
            dq->front[q_no] = end;
    }

    dq->q[dq->front[q_no]] = data;
}

void enqueue_rear(struct queue* dq, int q_no, int data)
{
    int start = q_no * dq_size;
    int end = start + dq_size -1;

    if(isFull(dq,q_no))
    {
        printf("D-queue %d is full \n",q_no);
        return;
    }

    if(isEmpty(dq,q_no))
        dq->front[q_no] = dq->rear[q_no] = start;
    else
    {
        dq->rear[q_no]++;
        if(dq->rear[q_no] > end)
            dq->rear[q_no] = start;
    }

    dq->q[dq->rear[q_no]] = data;
}

int dequeue_front(struct queue* dq, int q_no)
{
    if(isEmpty(dq,q_no))
    {
        printf("D-queue %d is empty \n",q_no);
        return -1;
    }

    int data = dq->q[dq->front[q_no]];
    if(dq->front[q_no] == dq->rear[q_no])   
        dq->front[q_no] = dq->rear[q_no] = -1;
    else
    {
        int start = q_no * dq_size;
        int end = start + dq_size -1;

        dq->front[q_no]++;
        if(dq->front[q_no] > end)
            dq->front[q_no] = start;
    }

    return data;
}

int dequeue_rear(struct queue* dq, int q_no)
{
    if(isEmpty(dq,q_no))
    {
        printf("D-queue %d is empty \n",q_no);
        return -1;
    }

    int data = dq->q[dq->rear[q_no]];
    if(dq->front[q_no] == dq->rear[q_no])   
        dq->front[q_no] = dq->rear[q_no] = -1;
    else
    {
        int start = q_no * dq_size;
        int end = start + dq_size -1;

        dq->rear[q_no]--;
        if(dq->rear[q_no] < start)
            dq->rear[q_no] = end;
    }
    return data;
}

void display(struct queue* dq, int q_no)
{
    if(isEmpty(dq,q_no))
    {
        printf("D-queue %d is empty \n",q_no);
        return;
    }
    int start = q_no * dq_size;
    int end = start + dq_size -1;
    int i = dq->front[q_no];

    printf("D-Queue %d : ",q_no);

    while(1)
    {
        printf("%d ",dq->q[i]);
        if(i == dq->rear[q_no])
            break;
        i++;
        if(i > end) i = start;
    }
    printf("\n");    
}

int main()
{
    struct queue* dq = (struct queue*) malloc(sizeof(struct queue));
    initialize(dq);

    int q_no, choice, data;
    char pos;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display all queue\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 :
                printf("Enter queue number (0-3) : ");
                scanf("%d",&q_no);
                printf("Enter value to be entered : ");
                scanf("%d",&data);
                printf("Enqueue from front (f) or rear (r) : ");
                scanf(" %c",&pos);
                if(pos == 'f')
                    enqueue_front(dq,q_no,data);
                else if(pos == 'r')
                    enqueue_rear(dq,q_no,data);
                else
                    printf("Enter choice correctly \n");
                break;
            
            case 2:
                 printf("Enter queue number (0-3) : ");
                scanf("%d", &q_no);
                printf("Dequeue from front or rear : ");
                scanf(" %c",&pos);
                if(pos == 'f')
                    printf("%d\n",dequeue_front(dq,q_no));
                else if(pos == 'r')
                    printf("%d\n",dequeue_rear(dq,q_no));
                else
                    printf("Enter choice correctly \n");
                break;
        
            case 3:
                for(int i =0;i<4;i++)
                {
                    display(dq,i);
                    printf("\n");
                }
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice\n");
            break;
        }

    }while(choice != 0);

    return 0;

}