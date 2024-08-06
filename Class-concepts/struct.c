#include<stdio.h>
#include<string.h>

struct employee 
{
    char name[30];
    int id;
    float salary;
};

int main()
{
    struct employee e1;
    strcpy(e1.name,"kush");
    e1.id = 26;
    e1.salary = 2000000;

    printf("%s ",e1.name);
    printf("%d ",e1.id);
    printf("%f", e1.salary);
    printf("\n");
    return 0;
}