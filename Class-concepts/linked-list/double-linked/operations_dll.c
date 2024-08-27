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

void reverse_traverse(struct node* last);

void add_after(struct node** start, int n , int given);

void add_before(struct node** start, int n, int given);

void reverse_list(struct node* start, struct node* last);

int main()
{
    struct node* start = NULL;
    struct node* last = NULL;
    int choice, data, given;
    printf("Enter 1 to make / enter an element in list.\n");
    printf("Enter 2 to view the list.\n");
    printf("Enter 3 to traverse in reverse direction.\n");
    printf("Enter 4 to add a node after a given data value.\n");
    printf("Enter 5 to add a node before a given data value.\n");
    printf("Enter 6 to reverse the linked list.\n");
    printf("Enter 0 to exit.\n");

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
            break;

        case 3:
            reverse_traverse(last);
            printf("\n");
            break;

        case 4:
            printf("Enter data to be entered and the data value of the node after which data is to entered: ");
            scanf("%d%d",&data,&given);
            add_after(&start,data,given);
            break;

        case 5:
            printf("Enter data to be entered and the data value of the node before which data is to entered: ");
            scanf("%d%d",&data,&given);
            add_before(&start,data,given);
            break;

        case 6:
            reverse_list(start,last);
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice\n");
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

void reverse_traverse(struct node* last)
{
    struct node* t = last;
    while(t != NULL)
    {
        printf("%d ",t->data);
        t = t->prev;
    }
}

void add_after(struct node** start, int n , int given)
{
    struct node* t = *start;

    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;
    ptr->prev = NULL;

    while(t->data != given)
        t = t->next;
    
    ptr->next = t->next;
    ptr->prev = t;

    t->next->prev = ptr;
    t->next = ptr;    
}

void add_before(struct node** start, int n, int given)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;
    ptr->prev = NULL;

    struct node* temp = *start;
    while(temp->data != given)
    {
        temp = temp->next;
    }

    ptr->next = temp;
    ptr->prev = temp->prev;
    temp->prev->next = ptr;
    temp->prev = ptr;
}

void reverse_list(struct node* start, struct node* last)
{
    struct node* s = start, *l = last;

    while(l->next != s && l != s)
    {
        int t = l->data;
        l->data = s->data;
        s->data = t;
        l = l->prev;
        s = s->next;
    }
}