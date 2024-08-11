//structure employee having id, name , basic slary, phone number. display gross salary = BS + DA(20 % of of BS) + HRA(10%of BS) 
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
    printf("Enter the number of employees : ");
    int n; scanf("%d",&n);
    struct employee e[n];
    printf("Enter the id, name, basic salary and phone number of 5 employees \n");

    for(int i =0;i<n;i++)
    {
        scanf("%d",&e[i].emp_id);
        scanf("%s",e[i].emp_name);
        scanf("%d",&e[i].basic_salary);
        scanf("%d",&e[i].ph_no);
    }

    printf("Information of the employees : \n");
    for(int i =0;i<n;i++)
    {
        printf("Employee %d :  ",i+1);
        printf("Id : %d  ",e[i].emp_id);
        printf("Name : %s  ",e[i].emp_name);
        printf("Basic salary : %d  ",e[i].basic_salary);
        printf("Phone number : %d  ",e[i].ph_no);
        printf("Gross Salary =  %f\n\n",e[i].basic_salary+(e[i].basic_salary*0.3));

    }
    return 0;
}