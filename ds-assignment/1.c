#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 50

struct Student
{
    int roll_no;
    char name[size];
    char branch_id[10];
    float cgpa;
    struct Student* next;
} *Student_head = NULL;

struct University
{
    char univ_id[10];
    char univ_name[size];
    char univ_location[size];
    int start_year;
    struct University* next;
} *University_head = NULL;

struct Branch
{
    char branch_id[5];
    char univ_id[10];
    char branch_name[size];
    struct Branch* next;
} *Branch_head = NULL;


int main()
{



    return 0;
}

void create_student()
{
    struct Student* ptr = (struct Student*) malloc(sizeof(struct Student));

    printf("Enter the roll number : ");
    scanf("%d",&ptr->roll_no);
    if(!(validate_Unique_rollno(ptr->roll_no)))
    {
        printf("This Roll number already exists. Student not added. \n");
        free(ptr);
        return;
    }

    printf("Enter Name of the student : ");
    scanf(" %[^\n]%*c",ptr->name);
    capatalize(ptr->name);

    printf("Enter Branch ID");
    scanf(" %[^\n]%*c",ptr->branch_id);
    if(!validate_existing_branchid(ptr->branch_id))
    {
        printf("This Branch ID does not exist. Student not added.\n");
        free(ptr);
        return;
    }

    printf("Enter CGPA : ");
    scanf("%f",ptr->cgpa);
    
    ptr->next = NULL;

    if(Student_head == NULL)
        Student_head = ptr;
    
    else
    {
        struct Student* temp = Student_head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void create_University()
{
    struct University* ptr = (struct University*) malloc(sizeof(struct University));

    printf("Enter University ID");
    scanf(" %[^\n]%*c",ptr->univ_id);
    if(!validate_Unique_univid(ptr->univ_id))
    {
        printf("This University ID does not exist. University not added.\n");
        free(ptr);
        return;
    }
    
    printf("Enter Name of the University : ");
    scanf(" %[^\n]%*c",ptr->univ_name);
    capatalize(ptr->univ_name);

    printf("Enter Location of the University : ");
    scanf(" %[^\n]%*c",ptr->univ_location);

    printf("Enter the Year of Start : ");
    scanf("%d",&ptr->start_year);
       

    if(University_head == NULL)
        University_head = ptr;
    
    else
    {
        struct University* temp = University_head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void create_Branch(char branch_id[5], char univ_id[5], char branch_name[10])
{
    struct Branch* ptr = (struct Branch*) malloc(sizeof(struct Branch));
    
    printf("Enter Branch ID");
    scanf(" %[^\n]%*c",ptr->branch_id);
    if(!validate_Unique_branchid(ptr->branch_id))
    {
        printf("This Branch ID alreadt exists. Branch not added.\n");
        free(ptr);
        return;
    }

    printf("Enter University ID");
    scanf(" %[^\n]%*c",ptr->univ_id);
    if(!validate_existing_uni_id(ptr->univ_id))
    {
        printf("This University ID does not exist. Branch not added.\n");
        free(ptr);
        return;
    }
    
    printf("Enter Name of the Branh : ");
    scanf(" %[^\n]%*c",ptr->branch_name);
    capatalize(ptr->branch_name);
       

    if(Branch_head == NULL)
        Branch_head = ptr;
    
    else
    {
        struct Branch* temp = Branch_head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void capatalize(char * str)
{
    for(int i =0;str[i];i++)
    {
        str[i] = toupper(str[i]);
    }
}

int validate_Unique_rollno(int rollno)
{
    struct Student* temp = Student_head;
    while(temp != NULL)
    {
        if(temp->roll_no == rollno)
            return 0; 
        temp = temp->name;
    }
    return 1;
}

int validate_Unique_univid(char * univid)
{
    struct University* temp = University_head;
    while(temp != NULL)
    {
        if(strcmp(temp->univ_id,univid) == 0)
            return 0;
        temp = temp->next;
    }
    return 1;
}

int validate_Unique_branchid(char * branchid)
{
    struct Branch* temp = University_head;
    while(temp != NULL)
    {
        if(strcmp(temp->branch_id,branchid) == 0)
            return 0;
        temp = temp->next;
    }
    return 1;
}

int validate_existing_uni_id(char* univid)
{
    struct University* temp = University_head;
    while(temp != NULL)
    {
        if(strcmp(temp->univ_id,univid) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int validate_existing_branchid(char * branchid)
{
    struct Branch* temp = University_head;
    while(temp != NULL)
    {
        if(strcmp(temp->branch_id,branchid) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}