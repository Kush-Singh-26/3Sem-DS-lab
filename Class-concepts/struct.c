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
    struct employee e[4];
    for(int i =0;i<4;i++)
    {
        scanf("%s",e[i].name);
        scanf("%d",&e[i].id);
        scanf("%f",&e[i].salary);
    }

    for(int i =0;i<4;i++)
    {
        printf("%s ",e[i].name);
        printf("%d ",e[i].id);
        printf("%f ",e[i].salary);
        printf("\n");
    }
    printf("\n");
    return 0;
}