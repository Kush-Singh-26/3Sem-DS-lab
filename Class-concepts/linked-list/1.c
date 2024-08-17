#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void create_list(int n);

void print_list();

void addbegining(int n);

void add_after_data(int given, int n);

void add_before_data(int given, int n);

int main()
{
    int y = 1;
    int data, choice, given;
    do
    {
        printf("1. Add a node / Create a list\n");
        printf("2. Display all nodes\n");
        printf("3. Add node at start\n");
        printf("4. Add a node after a given data value\n");
        printf("5. Add a node before a given data value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be entered : ");
            scanf("%d", &data);
            create_list(data);
            break;

        case 2:
            print_list();
            break;

        case 3:
            printf("Enter data to be entered : ");
            scanf("%d", &data);
            addbegining(data);
            break;

        case 4:
            printf("Enter the data to be entered and the data value after which the node has to be added: ");
            scanf("%d%d", &data, &given); 
            add_after_data(given, data);  
            break;
        
        case 5:
            printf("Enter the data to be entered and the data value before which the node has to be added : ");
            scanf("%d%d",&data, &given);
            add_before_data(given,data);
            break;
            
        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }

    } while (choice != 0);
}

void create_list(int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = n;
    ptr->next = NULL;
    if (start == NULL)
        start = ptr;
    else
    {
        struct node *temp = start;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void print_list()
{
    if (start == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    else
    {
        struct node *temp = start;

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

void addbegining(int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = start;
    start = ptr;
}

void add_after_data(int given, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;

    if (start == NULL)
    {
        printf("List is empty.\n");
        free(ptr);
        return;
    }

    struct node *temp = start;

    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        ptr->next = temp->next;
        temp->next = ptr;
    }
    else
    {
        printf("Data value %d not found in the list.\n", given);
        free(ptr);
    }
}

void add_before_data(int given, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;

    if (start == NULL)
    {
        printf("List is empty.\n");
        free(ptr);
        return;
    }

    struct node* temp = start;
    struct node* q = start;

    while(temp->data != given && temp != NULL)
        {
            q = temp;
            temp = temp->next;
        }
        q->next = ptr;
        ptr->next = temp;
}