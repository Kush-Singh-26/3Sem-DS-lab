#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data_node
{
    char name[10];
    int rollno;
    char gender;
    float cgpa;
    struct data_node* next;
};

struct head_node
{
    int nboys, ngirls;
    struct data_node* next;
};

void create_list(struct head_node** start_head,struct data_node** start_data, char name[10], int rollno, char gender, float cgpa);

void print_list(struct head_node** start_head,struct data_node** start_data);

int main()
{
    struct head_node* start_head = NULL;
    struct data_node* start_data = NULL;
    
    printf("1. To enter data.\n");
    printf("2. To view data.\n");
    printf("0. To EXIT");

    int choice;
    int rollno;
    char gender;
    float cgpa;
    char name[10];

    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter name : ");
            scanf("%s",name);
            printf("Enter roll number : ");
            scanf("%d",&rollno);
            printf("Enter gender : ");
            scanf(" %c",&gender);
            printf("Enter CGPA : ");
            scanf("%f",&cgpa);
            create_list(&start_head,&start_data,name,rollno,gender,cgpa);
            break;
        
        case 2:
            print_list(&start_head,&start_data);
            break;
        case 0:
            break;

        default:
            printf("Incorrect choice.\n");
            break;
        }
    }while(choice != 0);
}

void create_list(struct head_node** start_head,struct data_node** start_data, char name[10], int rollno, char gender, float cgpa)
{
    if(*start_head == NULL)
    {
        struct head_node* ptrh = (struct head_node*) malloc(sizeof(struct head_node));
        *start_head = ptrh;
        ptrh->nboys = 0;
        ptrh->ngirls = 0;
        ptrh->next = *start_data;
    }

    struct data_node* ptr = (struct data_node*) malloc(sizeof(struct data_node));
    strcpy(ptr->name,name);
    ptr->cgpa = cgpa;
    ptr->rollno = rollno;
    ptr->gender = gender;
    ptr->next = NULL;


    if(ptr->gender == 'm') 
        (*start_head)->nboys++;
    else if(ptr->gender == 'f')
        (*start_head)->ngirls++;

    if(*start_data == NULL)
    {
        *start_data = ptr;
    }

    else
    {
        struct data_node* temp = *start_data;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    
}

void print_list(struct head_node** start_head,struct data_node** start_data)
{
    struct data_node* temp = *start_data;
    printf("Number of boys = %d and Number of girls = %d.\n",(*start_head)->nboys,(*start_head)->ngirls);
    while(temp != NULL)
    {
        printf("Name : %s\n",temp->name);
        printf("Roll NO. : %d\n",temp->rollno);
        printf("Gender : %c\n",temp->gender);
        printf("CGPA : %f\n\n",temp->cgpa);
        temp = temp->next;
    }
}