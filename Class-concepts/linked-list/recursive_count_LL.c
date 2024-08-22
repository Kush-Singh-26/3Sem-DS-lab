#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **start, int n);

void print_list(struct node **start);

int count(struct node* start);

int main()
{
    struct node *start = NULL;
   

    int data, choice;

    printf("Enter list : \n");
    do
    {
        printf("Enter 1 to enter a new element or else enter 0 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            create_list(&start, data);
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice \n");
            break;
        }
    } while (choice != 0);

    printf("List 1 is : \n");
    print_list(&start);

    printf("Number of elements in the lst is : %d\n",count(start));

}

void create_list(struct node **start, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = n;
    ptr->next = NULL;
    if (*start == NULL)
        *start = ptr;
    else
    {
        struct node *temp = *start;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void print_list(struct node **start)
{
    if (*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        struct node *temp = *start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    printf("\n");
}


int count(struct node* start)
{
    if(start == NULL)
    {
        return 0;
    }
    else
    {
        return(1 + count(start->next));
    }
}