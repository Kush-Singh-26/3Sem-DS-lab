#include<stdio.h>
#define max 10
struct stac
{
    int st[max];
    int top;
};

void inititalize(struct stac*);

void push(struct stac*, int n);

void pop(struct stac*, int*n);

int main()
{
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("0. EXIT\n");

    struct stac S1;
    inititalize(&S1);


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
            
            case 0:
                break;
            
            default:
                printf("Incorrect choice.\n");
        }
    }while(choice != 0);

    return 0;
}

void inititalize(struct stac*S1)
{
    S1->top = -1;
}

void push(struct stac*S1, int n)
{
    if(S1->top == max-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        (S1->top)++;
        S1->st[S1->top] = n;
    } 
}

void pop(struct stac*S1, int*n)
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