#include<stdio.h>
#include<stdlib.h>
#define max 5
int top = -1;

struct node
{
    int data;
    struct node* next;
};


void push(struct node** start, int n);

void pop(struct node** start, int*n);

int main()
{
    struct node* start = NULL;

    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("0. EXIT\n");

    int n, choice;
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to be entered : ");
                scanf("%d",&n);
                push(&start,n);
                break;
            
            case 2:
                int b;
                pop(&start,&b);
                printf("%d\n",b);
                break;
            
            case 0:
                break;
            
            default:
                printf("Incorrect choice.\n");
        }
    }while(choice != 0);

    return 0;
}

void push(struct node** start, int n)
{
    if(top == max-1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        struct node* ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = n;
        ptr->next = (*start);
        *start = ptr;
        top++;
    } 
}

void pop(struct node** start, int*n)
{
    if(*start == NULL)
    {
        printf("Stack Underflow.\n");
        return;
    }
    else
    {
        *n = (*start)->data;
        struct node* t = *start;
        *start = (*start)->next;
        top--;
        free(t);
    }
}