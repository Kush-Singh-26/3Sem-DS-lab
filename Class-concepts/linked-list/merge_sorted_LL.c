#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **start);

void print_list(struct node **start);

void merge(struct node **l1, struct node **l2, struct node **l3);

int main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    printf("Enter sorted list 1 :\n");
    create_list(&start1);
    printf("Enter sorted list 2 :\n");
    create_list(&start2);

    printf("List 1 is : \n");
    print_list(&start1);

    printf("List 2 is : \n");
    print_list(&start2);

    merge(&start1, &start2, &start3);

    printf("Merges list is :\n");
    print_list(&start3);
}

void create_list(struct node **start)
{
    int y = 1;
    int data, choice;
    do
    {
        printf("Enter 1 to enter a new element else enter 0 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d", &data);
            ptr->data = data;
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
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice \n");
            break;
        }
    } while (choice != 0);
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
    struct node **last_pointer = l3;
    struct node *temp = NULL;
    while ((*l1) != NULL && (*l2) != NULL)
    {
        if ((*l1)->data <= (*l2)->data)
        {
            temp = (*l1);
            (*l1) = (*l1)->next;
        }
        else
        {
            temp = (*l2);
            (*l2) = (*l2)->next;
        }

        *last_pointer = temp;
        last_pointer = &temp->next;
    }

    while ((*l1) != NULL)
    {
        temp = (*l1);
        (*l1) = (*l1)->next;
        *last_pointer = temp;
        last_pointer = &temp->next;
    }

    while ((*l2) != NULL)
    {
        temp = (*l2);
        (*l2) = (*l2)->next;
        *last_pointer = temp;
        last_pointer = &temp->next;
    }
}
