#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void create(struct node** start, int n);

void print(struct node*);

void insert_first(struct node** start, int n);

int main()
{
    struct node* start = NULL;
    int data, choice, given;

    printf("1. To create / add an element to a list.\n");
    printf("2. Display / traverse the list.\n");
    printf("3. Insert at first.\n");
    do
    {   
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be entered : ");
            scanf("%d",&data);
            create(&start,data);
            break;
        
        case 2:
            print(start);
            printf("\n");
            break;

        case 3:
            printf("Enter data to be entered : ");
            scanf("%d",&data);
            insert_first(&start,data);
            break;
            
        case 0:
            break;

        default:
            printf("Incorrect choice.\n");
            break;
        }
    } while (choice != 0);
    
    return 0;
}

void create(struct node** start, int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = *start;
    if(*start == NULL)
    {
        *start = ptr;
        ptr->next = ptr;
    }

    else
    {
        struct node* t = *start;
        while(t->next != *start)
            t = t->next;
        t->next = ptr;
    }
}

void print(struct node*start)
{
    if(start == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    struct node* temp = start;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != start);
}

void insert_first(struct node** start, int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    if(*start == NULL)
    {
        *start = ptr;
        ptr->next = ptr;
    }
    else 
    {
        struct node* t = *start;
        while(t->next != *start)
            t = t->next;
        ptr->next = *start;
        t->next = ptr;
        *start = ptr;
    }
}