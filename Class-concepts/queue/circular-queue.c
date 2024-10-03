#include<stdio.h>
#include<stdlib.h>

#define max 10

struct queue
{
    int q[max];
    int f, r;
};

void initialize(struct queue* q1);
void insert (struct queue* q1, int n);
void delete (struct queue* q1, int* n);

int main()
{
    printf("1. INSERT\n");
    printf("2. DELETE\n");
    printf("0. EXIT\n");

    struct queue q1;
    initialize(&q1);

    int n, choice, b;
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to be entered: ");
                scanf("%d", &n);
                insert(&q1, n);
                break;
            
            case 2:
                delete(&q1, &b);
                if (q1.f != -1) 
                {
                    printf("Deleted: %d\n", b);
                }
                break;
            
            case 0:
                break;
            
            default:
                printf("Incorrect choice.\n");
        }
    } while(choice != 0);

    return 0;
}

void initialize(struct queue* q1)
{
    q1->f = -1;
    q1->r = -1;
}

void insert(struct queue* q1, int n)
{
    if ((q1->r + 1) % max == q1->f)
    {
        printf("Overflow\n");
        return;
    }

    if (q1->r == -1) 
    {
        q1->f = 0;
    }

    q1->r = (q1->r + 1) % max;
    q1->q[q1->r] = n;
}

void delete(struct queue* q1, int* n)
{
    if (q1->f == -1) 
    {
        printf("Underflow\n");
        return;
    }

    *n = q1->q[q1->f];

    if (q1->f == q1->r)  
    {
        q1->f = -1;
        q1->r = -1;
    }
    else
    {
        q1->f = (q1->f + 1) % max;  
    }
}
