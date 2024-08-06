#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct employee 
{
    char name[30];
    int id;
    float salary;
};

void read (struct employee* eptr, int n);

void print (struct employee* eptr, int n);

int main()
{
    printf("Enter the numer of elements in the structure : ");
    int n;
    scanf("%d",&n);
    struct employee* eptr = (struct employee*) malloc(n * sizeof(struct employee));

    

    read(eptr, n);
    
    print(eptr,n);
    printf("\n");

    return 0;
}

void read (struct employee* eptr, int n)
{
    for(int i =0;i<n;i++)
    {
        scanf("%s",(eptr + i) ->name);
        scanf("%d",&((eptr + i) ->id));
        scanf("%f",&((eptr + i) ->salary));
    }
}

void print (struct employee* eptr, int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%s",(eptr + i) ->name);
        printf("%d",(eptr + i) ->id);
        printf("%f",(eptr + i) ->salary);
        printf("\n");

    }
}