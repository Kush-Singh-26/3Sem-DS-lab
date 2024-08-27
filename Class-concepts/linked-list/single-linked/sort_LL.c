#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **start, int n);

void print_list(struct node **start);

void sort(struct node **start);

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

    printf("List is : \n");
    print_list(&start);

    sort(&start);

    printf("Sorted List :\n");
    print_list(&start);

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

void sort(struct node **start)
{
    if(*start == NULL)
    {
        printf("Empty list\n");
        return;
    }

    struct node* t1 = *start;
    while(t1 != NULL)
    {
        struct node* t2 = t1->next;
        while(t2 != NULL)
        {
            if(t1->data > t2->data)
            {
                int temp = t2->data;
                t2->data = t1->data;
                t1->data = temp;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    
}

