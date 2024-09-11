#include<stdio.h>
#include<string.h>

#define max 10

struct stac
{
    char st[max];
    int top;
};

void push(struct stac* s1,char n);

void pop(struct stac* s1, char*n);

void initialize(struct stac* s1);

void reverse(struct stac* s1, char* str);


int main()
{
    struct stac s1;
    initialize(&s1);
    char n[max];
    printf("Enter a String : ");
    scanf(" %s",n);

    printf("String entered : %s\n",n);

    reverse(&s1,n);

    printf("Reversed stirng is : %s\n",n);

    return 0;
}

void initialize(struct stac* s1)
{
    s1->top = -1;
}

void push(struct stac* s1,char n)
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

void pop(struct stac* s1, char*n)
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

void reverse(struct stac* s1, char* str)
{
    for(int i = 0;i< str[i] != '\0';i++)
    {
        push(s1,str[i]);
    }
    int i =0;
    while(s1->top != -1)
    {
        char c;
        pop(s1,&c);
        str[i++] = c;
    }
    str[i] = '\0';

}