#include<stdio.h>

#define max 10

struct stac
{
    int st[max];
    int top;
};

void push(struct stac* s1, int n);

void pop(struct stac* s1, int*n);

void initialize(struct stac* s1);

void display(struct stac* s1);

void add_ele(struct stac* s1, int n);

void sort(struct stac* s1);

int main()
{
    struct stac s1;
    initialize(&s1);
    int n, choice, b;

    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. EXIT\n");

    
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("ENter data to be entered : ");
                scanf("%d",&n);
                push(&s1,n);
                break;
            
            case 2:
                pop(&s1,&b);
                printf("%d\n",b);
                break;
            
            case 3:
                display(&s1);
                printf("\n");
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice.\n");
        }
    }while(choice != 0);

    sort(&s1);

    printf("Sorted Stack is : ");
    display(&s1);
    printf("\n");

    return 0;
}

void initialize(struct stac* s1)
{
    s1->top = -1;
}

void push(struct stac* s1,int n)
{
    if(s1->top == max -1)
    {
        printf("Stack Overflow\n");
        return;
    }

    else
    {
        s1->top ++;
        s1->st[s1->top] = n;
    }
}

void pop(struct stac* s1, int*n)
{
    if(s1->top == -1)
    {
        printf("Stack Underflow");
        return;
    }

    else
    {
        *n = s1->st[s1->top];
        s1->top--;
    }
}

void display(struct stac* s1)
{
    if(s1->top == -1)
        return;
    int b;
    pop(s1,&b);
    display(s1);
    printf("%d ",b);
    push(s1,b);
}

void add_ele(struct stac* s1, int n)
{
    if(s1->top == -1 || s1->st[s1->top] < n)
    {
        push(s1,n);
        return;
    }
    int b;
    pop(s1,&b);
    add_ele(s1,n);
    push(s1,b);
}

void sort(struct stac* s1)
{
    if(s1->top == -1)
        return;
    int b;
    pop(s1,&b);
    add_ele(s1,b);
}