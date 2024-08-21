#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **start, int data);

void print_list(struct node **start);

void add_begining(struct node **start, int data);

void add_after(struct node **start, int data, int given);

void add_before(struct node **start, int data, int given);

void delete_begining(struct node **start);

void delete_last(struct node **start);

void delete_after(struct node **start, int given);

void reverse(struct node **start);

void sort(struct node **start);

void delete_duplicate(struct node **start);

int main()
{
    struct node *start = NULL;

    printf("1. Create the list\n");
    printf("2. Traverse (print) the list\n");
    printf("3. Add node at begining\n");
    printf("4. Add node after a given node\n");
    printf("5. Add a node before a given node\n");
    printf("6. Delete the node at begining\n");
    printf("7. Delete the last node\n");
    printf("8. Delete the node after a given node\n");
    printf("9. Reverse the linked list\n");
    printf("10. Sort the data elements of the linked list\n");
    printf("11. Delete the duplicate elements from the linked list\n");
    printf("0. To exit\n");

    int choice, data, given;
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be entered :");
            scanf("%d", &data);
            create(&start, data);
            break;

        case 2:
            printf("The list is : \n");
            print_list(&start);
            break;

        case 3:
            printf("Enter data to be entered : ");
            scanf("%d", &data);
            add_begining(&start, data);
            break;

        case 4:
            printf("Enter data to be entered and the data value of the node after which data is to entered: ");
            scanf("%d%d", &data, &given);
            add_after(&start, data, given);
            break;

        case 5:
            printf("Enter data to be entered and the data value of the node before which data is to entered: ");
            scanf("%d%d", &data, &given);
            add_before(&start, data, given);
            break;

        case 6:
            delete_begining(&start);
            printf("Node at begining deleted\n");
            break;

        case 7:
            delete_last(&start);
            printf("Last node deleted\n");
            break;

        case 8:
            printf("Enter the data value of the node whose next node is to deleted : ");
            scanf("%d",&given);
            delete_after(&start,given);
            break;

        case 9:
            //reverse(&start);
            printf("The list is reversed\n");
            break;

        case 10:
            //sort(&start);
            printf("The list is sorted\n");
            break;
        
        case 11:
            //delete_duplicate(&start);
            printf("Duplicate elements deleted\n");
            break;
        
        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

void create(struct node **start, int n)
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

void add_begining(struct node **start, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = *start;
    *start = ptr;
}

void add_after(struct node **start, int given, int n)
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

void add_before(struct node **start, int given, int n)
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

void delete_begining(struct node **start)
{
    struct node *temp = *start;
    *start = (*start)->next;
    free(temp);
}


void delete_after(struct node** start, int given)
{
    struct node* temp = *start;
    while(temp->data != given)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void delete_last(struct node** start)
{
    struct node* temp = *start;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;

}