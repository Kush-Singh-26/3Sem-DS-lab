#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data);

void create_list(struct node **start, int n);

void print_list(struct node **start);

int main()
{
    struct node *start = NULL;
    int choice, data;

    do
    {
        printf("1. Add a node\n");
        printf("2. Display all nodes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be entered : ");
            scanf("%d", &data);
            create_list(&start, data);
            break;

        case 2:
            print_list(&start);
            break;
        case 3:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
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
        printf("List is Empty.\n");
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

        printf("\n");
    }
}