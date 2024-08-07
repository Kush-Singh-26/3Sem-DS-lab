#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll_no;
    char name[30];
    int mark1;
    int mark2;
    int mark3;
};

int main()
{
    struct student *eptr =(struct student *)malloc(sizeof(struct student));

    scanf("%d",&eptr->roll_no);
    scanf("%s",eptr->name);
    scanf("%d",&eptr->mark1);
    scanf("%d",&eptr->mark2);
    scanf("%d",&eptr->mark3);
   

    printf("%d ",eptr->roll_no);
    printf("%s ",eptr->name);
    printf("%d ",eptr->mark1);
    printf("%d ",eptr->mark2);
    printf("%d ",eptr->mark3);
    printf("%d ",(eptr->mark1) +(eptr->mark2) + (eptr->mark3));
    
    printf("\n");

    return 0;
}

