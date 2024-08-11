//structure student having roll no, name, mark 1, mark 2 , mark 3. accept a record of student using pointer to structure and find the total marks of the student. display the info of student.
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

    printf("Enter roll no., name, mark 1, mark 2, mark 3 : \n");
    scanf("%d",&eptr->roll_no);
    scanf("%s",eptr->name);
    scanf("%d",&eptr->mark1);
    scanf("%d",&eptr->mark2);
    scanf("%d",&eptr->mark3);
   

    printf("Roll No. : %d  ",eptr->roll_no);
    printf("Name : %s  ",eptr->name);
    printf("Mark 1 : %d  ",eptr->mark1);
    printf("Mark 2 :  %d  ",eptr->mark2);
    printf("Mark 3 :  %d  ",eptr->mark3);
    printf("Total Marks : %d  ",(eptr->mark1) +(eptr->mark2) + (eptr->mark3));
    
    printf("\n");

    return 0;
}

