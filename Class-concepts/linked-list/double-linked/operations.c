#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

void create_list(struct node** start, struct node** last, int n);

void print_list(struct node* start);


int main()
{
    struct node* start = NULL;
    struct node* last = NULL;
    int choice, data, given;
    printf("Enter 1 to make / enter an element in list :\n");
    printf("Enter 2 to view the list:\n");
    printf("Enter 0 to exit\n");

    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be entered : ");
            scanf("%d",&data);
            create_list(&start,&last,data);
            break;

        case 2:
            print_list(start);
            printf("\n");     
        default:
            break;
        }
    } while (choice != 0);
    
}

void create_list(struct node** start, struct node** last, int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;
    ptr->prev = NULL;

    if(*start == NULL)
    {
        *start = ptr;
        *last = ptr;
    }

    else
    {
        (*last)->next = ptr;
        ptr->prev = *last;
        *last = ptr;
    }
}

void print_list(struct node* start)
{
    if(start == NULL)
    {
        printf("Empty list\n");
        return;
    }
    else
    {
        struct node* temp = start;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}