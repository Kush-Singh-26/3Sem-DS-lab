#include<stdio.h>
#define max 10

struct stac
{
    int st[max];
    int top;
};

void initialize(struct stac*);

void push(struct stac*, int n);

void pop(struct stac*, int* n);

void display(struct stac* S);

void copy(struct stac* S1, struct stac* S2);

int main()
{
    struct stac S1;
    struct stac S2;
    initialize(&S1);
    initialize(&S2);

    int n, choice, b;
    
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("ENter data to be entered : ");
                scanf("%d",&n);
                push(&S1,n);
                break;
            
            case 2:
                pop(&S1,&b);
                printf("%d\n",b);
                break;
            
            case 3:
                display(&S1);
                printf("\n");
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice.\n");
        }
    }while(choice != 0);

    printf("Stack 1 : ");
    display(&S1);

    printf("\nStack 2 before copying : ");
    display(&S2);

    copy(&S1,&S2);

    printf("\nStack 2 after copying : ");
    display(&S2);
    printf("\n");

    return 0;
}

void initialize(struct stac* S)
{
    S->top = -1;
}

void push(struct stac* S1,int n)
{
    if(S1->top == max-1)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        (S1->top)++;
        S1->st[S1->top] = n;
    }
}

void pop(struct stac* S1, int* n)
{
    if(S1->top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }
    else
    {
        *n = S1->st[S1->top];
        (S1->top)--;
    }
}

void display(struct stac* S)
{
    if(S->top == -1)
        return;
    int b;
    pop(S,&b);
    display(S);
    printf("%d ",b);
    push(S,b);
}

void copy(struct stac* S1, struct stac* S2)
{
    if(S1->top == -1)
        return;
    int b;
    pop(S1,&b);
    copy(S1,S2);
    push(S1,b);
    push(S2,b);
}
