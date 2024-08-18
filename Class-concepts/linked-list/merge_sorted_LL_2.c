#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **start, int n);

void print_list(struct node **start);

void merge(struct node **l1, struct node **l2, struct node **l3);

int main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;

    int data, choice;

    printf("Enter list 1 : \n");
    do
    {
        printf("Enter 1 to enter a new element in current list or else enter 0 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            create_list(&start1, data);
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice \n");
            break;
        }
    } while (choice != 0);

    printf("Enter list 2 : \n");

    do
    {
        printf("Enter 1 to enter a new element in current list or else enter 0 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            create_list(&start2, data);
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice \n");
            break;
        }
    } while (choice != 0);

    printf("List 1 is : \n");
    print_list(&start1);

    printf("List 2 is : \n");
    print_list(&start2);

    merge(&start1, &start2, &start3);

    printf("Merges list is :\n");
    print_list(&start3);
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

void merge(struct node **l1, struct node **l2, struct node **l3)
{
    while ((*l1) != NULL && (*l2) != NULL)
    {
        if ((*l1)->data <= (*l2)->data)
        {
            create_list(l3, (*l1)->data);
            (*l1) = (*l1)->next;
        }
        else
        {
            create_list(l3, (*l2)->data);
            (*l2) = (*l2)->next;
        }
    }

    while ((*l1) != NULL)
    {
        create_list(l3, (*l1)->data);
        (*l1) = (*l1)->next;
    }

    while ((*l2) != NULL)
    {
        create_list(l3, (*l2)->data);
        (*l2) = (*l2)->next;
    }
}
