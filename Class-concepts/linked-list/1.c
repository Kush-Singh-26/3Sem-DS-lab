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
int main()
{
    int y = 1;
    int data, choice;
    do{
        printf("1. Add a node / Create a list\n");
        printf("2. Display all nodes\n");
        printf("3. Add node at start\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be entered : ");
            scanf("%d",&data);
            create_list(data);
            break;
        case 2:
            print_list();
            break;
        case 3:
            printf("Enter data to be entered : ");
            scanf("%d",&data);
            addbegining(data);
            break;
        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
        
        
    } while(choice != 0);
    
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
        struct node* temp = start;

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

void addbegining(int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = start;
    start = ptr;
}
