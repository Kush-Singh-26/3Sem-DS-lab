#include<stdio.h>
struct employee
{
    int emp_id;
    char emp_name[30];
    int basic_salary;
    int ph_no;
};

int main()
{
    struct employee e[5];

    int n =5;
    printf("Enter the id, name, basic salary and phone number of 5 employees \n");

    for(int i =0;i<5;i++)
    {
        scanf("%d",&e[i].emp_id);
        scanf("%s",e[i].emp_name);
        scanf("%d",&e[i].basic_salary);
        scanf("%d",&e[i].ph_no);
    }

    printf("Information of the employees : \n");
    for(int i =0;i<n;i++)
    {
        printf("Id of employee %d : %d\n",i+1,e[i].emp_id);
        printf("Name of employee %d : %s\n",i+1,e[i].emp_name);
        printf("Basic salary of employee %d : %d\n",i+1,e[i].basic_salary);
        printf("Phone number of employee %d : %d\n",i+1,e[i].ph_no);
        printf("Gross Salary =  %f\n",e[i].basic_salary+(e[i].basic_salary*0.3));

    }
    return 0;
}