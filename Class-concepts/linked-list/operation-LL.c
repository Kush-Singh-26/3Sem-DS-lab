#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **start, int n);

void print_list(struct node **start);

void addbegining(struct node **start, int n);

void add_after_data(struct node **start, int given, int n);

void add_before_data(struct node **start, int given, int n);

void delete_first_node(struct node **start);

void delete_node_with_given_data(struct node **start, int given);

void delete_node_before_given_data(struct node **start, int given);

void delete_node_after_given_Data(struct node** start, int given);

int main()
{
    struct node *start = NULL;
    int y = 1;
    int data, choice, given;
    printf("1. Add a node / Create a list\n");
    printf("2. Display all nodes\n");
    printf("3. Add node at start\n");
    printf("4. Add a node after a given data value\n");
    printf("5. Add a node before a given data value\n");
    printf("6. Delete the first node\n");
    printf("7. Delete a node of a given data value\n");
    printf("8. Delete node before a given data value\n");
    printf("9. Delete node after a given data value\n");
    printf("0. Exit\n");
    do
    {
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
            printf("Enter data to be entered : ");
            scanf("%d", &data);
            addbegining(&start, data);
            break;

        case 4:
            printf("Enter the data to be entered and the data value after which the node has to be added: ");
            scanf("%d%d", &data, &given);
            add_after_data(&start, given, data);
            break;

        case 5:
            printf("Enter the data to be entered and the data value before which the node has to be added : ");
            scanf("%d%d", &data, &given);
            add_before_data(&start, given, data);
            break;

        case 6:
            delete_first_node(&start);
            break;

        case 7:
            printf("Enter the value of data of the node which is to be deleted : ");
            scanf("%d", &given);
            delete_node_with_given_data(&start, given);
            break;

        case 8:
            printf("Enter the value of data of the node whose previous node is to be deleted : ");
            scanf("%d", &given);
            delete_node_before_given_data(&start, given);
        
        case 9:
            printf("Enter the data value of the node whose next node is to deleted : ");
            scanf("%d",&given);
            delete_node_after_given_Data(&start, given);

        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }

    } while (choice != 0);
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

void addbegining(struct node **start, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = *start;
    *start = ptr;
}

void add_after_data(struct node **start, int given, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;

    if (*start == NULL)
    {
        printf("List is empty.\n");
        free(ptr);
        return;
    }

    struct node *temp = *start;

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

void add_before_data(struct node **start, int given, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;

    if (*start == NULL)
    {
        printf("List is empty.\n");
        free(ptr);
        return;
    }

    struct node *temp = *start;
    struct node *q = *start;

    while (temp->data != given && temp != NULL)
    {
        q = temp;
        temp = temp->next;
    }
    q->next = ptr;
    ptr->next = temp;
}

void delete_first_node(struct node **start)
{
    struct node *temp = *start;
    *start = (*start)->next;
    free(temp);
}

void delete_node_with_given_data(struct node **start, int given)
{
    struct node *temp = *start;
    while (temp->next->data != given)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void delete_node_before_given_data(struct node **start, int given)
{
    struct node *temp = *start;
    while (temp->next->next->data != given)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void delete_node_after_given_Data(struct node** start, int given)
{
    struct node* temp = *start;
    while(temp->data != given)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}