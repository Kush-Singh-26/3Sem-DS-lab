#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

void create_dcll(struct node** start,int n);

void print_dcll(struct node* start);

void add_first(struct node** start,int n);

void delete_last(struct node** start);

int main()
{
    struct node* start = NULL;

    printf("1. Enter an element.\n");
    printf("2. Print the list.\n");
    printf("3. Add node at beginning.\n");
    printf("4. Delete last node\n");
    printf("0. EXIT\n");

    int choice,n;
    do
    {
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be entered: ");
            scanf("%d",&n);
            create_dcll(&start,n);
            break;
        
        case 2:
            print_dcll(start);
            printf("\n");
            break;
        
        case 3:
            printf("Enter data to be entered: ");
            scanf("%d",&n);
            add_first(&start,n);
            break;

        case 4:
            delete_last(&start);
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice\n");
            break;
        }
    }while(choice != 0);


    return 0;
}

void create_dcll(struct node** start, int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;

    if(*start == NULL)
    {
        *start = ptr;
        ptr->next = *start;
        ptr->prev = *start;
    }

    else
    {
        (*start)->prev->next = ptr;
        ptr->prev = (*start)->prev;
        ptr->next = *start;
        (*start)->prev = ptr;
    }
}

void print_dcll(struct node* start)
{
    if(start == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    else
    {
        struct node* temp = start;
        do
        {   
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp != start);
    }
}


void add_first(struct node** start,int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;

    if(*start == NULL)
    {
        *start = ptr;
        ptr->next = *start;
        ptr->prev = *start;
    }

    else
    {
        (*start)->prev->next = ptr;
        ptr->prev = (*start)->prev;
        ptr->next = *start;
        (*start)->prev = ptr;
        (*start) = ptr;
    }
}

void delete_last(struct node** start)
{
    if(*start == NULL)
    {
        printf("Empty list\n");
        return;
    }
    else if ((*start)->next == *start)  
    {
        free(*start);
        *start = NULL;  
    }
    else
    {
    struct node* temp = (*start)->prev;
    temp->prev->next = *start;
    (*start)->prev = temp->prev;
    free(temp);
    }
}
    