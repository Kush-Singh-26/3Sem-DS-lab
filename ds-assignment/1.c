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
} *Student_head = NULL, *fail_student_head = NULL;

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

void create_student();
void create_University();
void create_Branch();

void capitalize(char * str);

int validate_Unique_rollno(int rollno);
int validate_Unique_univid(char * univid);
int validate_Unique_branchid(char * branchid);
int validate_existing_uni_id(char* univid);
int validate_existing_branchid(char * branchid);

int main()
{



    return 0;
}

void create_student()
{
    struct Student* ptr = (struct Student*) malloc(sizeof(struct Student));
    ptr->next = NULL;

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
    capitalize(ptr->name);

    printf("Enter Branch ID");
    scanf(" %[^\n]%*c",ptr->branch_id);
    if(!validate_existing_branchid(ptr->branch_id))
    {
        printf("This Branch ID does not exist. Student not added.\n");
        free(ptr);
        return;
    }

    printf("Enter CGPA : ");
    scanf("%f", &(ptr->cgpa));
    
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
    ptr->next = NULL;

    printf("Enter University ID");
    scanf(" %[^\n]%*c",ptr->univ_id);
    if(!validate_Unique_univid(ptr->univ_id))
    {
        printf("This University ID already exist. University not added.\n");
        free(ptr);
        return;
    }
    
    printf("Enter Name of the University : ");
    scanf(" %[^\n]%*c",ptr->univ_name);
    capitalize(ptr->univ_name);

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

void create_Branch()
{
    struct Branch* ptr = (struct Branch*) malloc(sizeof(struct Branch));
    ptr->next = NULL;

    printf("Enter Branch ID : ");
    scanf(" %[^\n]%*c",ptr->branch_id);
    if(!validate_Unique_branchid(ptr->branch_id))
    {
        printf("This Branch ID already exists. Branch not added.\n");
        free(ptr);
        return;
    }

    printf("Enter University ID : ");
    scanf(" %[^\n]%*c",ptr->univ_id);
    if(!validate_existing_uni_id(ptr->univ_id))
    {
        printf("This University ID does not exist. Branch not added.\n");
        free(ptr);
        return;
    }
    
    printf("Enter Name of the Branch : ");
    scanf(" %[^\n]%*c",ptr->branch_name);
    capitalize(ptr->branch_name);
       

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

void capitalize(char * str)
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
        temp = temp->next;
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
    struct Branch* temp = Branch_head;
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
    struct Branch* temp = Branch_head;
    while(temp != NULL)
    {
        if(strcmp(temp->branch_id,branchid) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void display_student()
{
    struct Student* temp = Student_head;
    while(temp != NULL)
    {
        printf("Roll number :  %d, Name : %s, Branch ID : %s, CGPA : %.2f\n", temp->roll_no, temp->name, temp->branch_id, temp->cgpa);
        temp = temp->next;
    }
}

void display_university()
{
    struct University* temp = University_head;
    while(temp != NULL)
    {
        printf("University ID : %s, University Name : %s, University Location : %s, Year of Start : %d\n",temp->univ_id, temp->univ_name, temp->univ_location, temp->start_year);
        temp = temp->next;
    }
}

void display_branch()
{
    struct Branch* temp = Branch_head;
    while(temp != NULL)
    {
        printf("Branch ID : %s, Unviersity ID : %s, Branch Name : %s\n",temp->branch_id, temp->univ_id, temp->branch_name);
        temp = temp->next;
    }
}

void delete_fail()
{
    struct Student* temp1 = Student_head;
    struct Student* prev = NULL;
    
    while(temp1 != NULL)
    {
        if(temp1->cgpa < 6.0)
        {
            if (fail_student_head == NULL)
            {
                fail_student_head = temp1;
                temp1 = temp1->next;
                fail_student_head->next = NULL;
            }
            else
            {
                struct Student* temp2 = fail_student_head;
                while (temp2->next != NULL)
                    temp2 = temp2->next;
                temp2->next = temp1;
                temp1 = temp1->next;
                temp2->next->next = NULL;
            }

            if (prev == NULL) 
            {
                Student_head = temp1;
            }
            else
            {
                prev->next = temp1;
            }
        }
        else
        {
            prev = temp1;
            temp1 = temp1->next;
        }
    }
}
