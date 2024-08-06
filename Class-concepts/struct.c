#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct employee 
{
    char name[30];
    int id;
    float salary;
};

int main()
{
    printf("Enter the numer of elements in the structure : ");
    int n;
    scanf("%d",&n);
    struct employee* eptr = (struct employee*) malloc(n * sizeof(struct employee));

    for(int i =0;i<n;i++)
    {
        scanf("%s",(eptr + i) ->name);
        scanf("%d",&((eptr + i) ->id));
        scanf("%f",&((eptr + i) ->salary));
    }

    for(int i =0;i<n;i++)
    {
        printf("%s",(eptr + i) ->name);
        printf("%d",(eptr + i) ->id);
        printf("%f",(eptr + i) ->salary);
        printf("\n");

    }

    printf("\n");

    return 0;
}