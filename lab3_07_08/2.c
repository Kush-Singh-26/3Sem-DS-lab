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
    printf("Enter the numer of students : ");
    int n;
    scanf("%d", &n);
    struct student *eptr = (struct student *)malloc(n * sizeof(struct student));

    printf("Enter the roll no, name, mark 1, mark 2 and mark 3\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &((eptr + i)->roll_no));
        scanf("%s", (eptr + i)->name);
        scanf("%d", &((eptr + i)->mark1));
        scanf("%d", &((eptr + i)->mark2));
        scanf("%d", &((eptr + i)->mark3));
    }

    for (int i = 0; i < n; i++)
    {
        printf("Student %d\n",i+1);
        printf("%d\n", (eptr + i)->roll_no);
        printf("%s\n", (eptr + i)->name);
        printf("%d\n", (eptr + i)->mark1);
        printf("%d\n", (eptr + i)->mark2);
        printf("%d\n", (eptr + i)->mark3);
        printf("Total marks : %d",(eptr+i)->mark1 + (eptr+i)->mark2 + (eptr+i)->mark3);
    }

    printf("\n");

    return 0;
}

