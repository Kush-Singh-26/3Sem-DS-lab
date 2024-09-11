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

int reverse(struct stac* s1, int n);


int main()
{
    struct stac s1;
    initialize(&s1);
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    printf("Number entered : %d\n",n);

    printf("Reversed number is : %d\n",reverse(&s1,n));

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

int reverse(struct stac* s1, int n)
{
    while(n != 0)
    {
        int digit = n%10;
        push(s1,digit);
        n/=10;
    }

    int revnum = 0, multiplier = 1,d;
    while(s1->top != -1)
    {
        pop(s1,&d);
        revnum += d * multiplier;
        multiplier *= 10;
    }

    return revnum;
}