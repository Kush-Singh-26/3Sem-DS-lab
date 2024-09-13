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

void display(struct stac*);

void display_temp_st(struct stac* S1);

int main()
{
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PRINT (RECURSIVE)\n");
    printf("4. PRINT (TEMP. STACK)");
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
            
            case 3:
                display(&S1);
                printf("\n");
                break;

            case 4:
                display_temp_st(&S1);
                printf("\n");
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

void display(struct stac* S1)
{
    if(S1->top == -1)
        return;
    int b;
    pop(S1,&b);
    display(S1);
    printf("%d ",b);
    push(S1,b);
}

void display_temp_st(struct stac* S1)
{
    struct stac S2;
    inititalize(&S2);

    while(S1->top != -1)
    {
        int b;
        pop(S1,&b);
        push(&S2,b);
    }

    while(S2.top != -1)
    {
        int b;
        pop(&S2,&b);
        printf("%d ",b);
        push(S1,b);
    }
}