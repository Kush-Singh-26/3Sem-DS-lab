#include<stdio.h>
#define max 10
int st[max];
int top = -1;

void push(int n);

void pop(int*n);

int main()
{
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
                printf("ENter data to be entered : ");
                scanf("%d",&n);
                push(n);
                break;
            
            case 2:
                int b;
                pop(&b);
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

void push(int n)
{
    if(top == max-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        st[top] = n;
    } 
}

void pop(int*n)
{
    if(top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }
    else
    {
        *n = st[top];
        top--;
    }
}