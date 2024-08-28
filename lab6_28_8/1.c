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

void add_node_beginning(struct node** start, int n);

void add_after(struct node** start, int n , int given);

void add_before(struct node** start, int n, int given);

void delete_first(struct node** start);

void delete_last(struct node** last);

void delete_after(struct node** start, int given);

void reverse_list(struct node* start, struct node* last);

int main()
{
    struct node* start = NULL;
    struct node* last = NULL;
    int choice, data, given;
    printf("1. Create the list\n");
    printf("2. Traverse (print) the list\n");
    printf("3. Add node at begining\n");
    printf("4. Add node after a given node\n");
    printf("5. Add a node before a given node\n");
    printf("6. Delete the node at begining\n");
    printf("7. Delete the last node\n");
    printf("8. Delete the node after a given node\n");
    printf("9. Reverse the linked list\n");
    printf("0. To exit\n");
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
            printf("Enter data to be entered : ");
            scanf("%d", &data);
            add_node_beginning(&start, data);
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
            delete_first(&start);
            break;

        case 7:
            delete_last(&last);
            break;

        case 8:
            printf("Enter the data value of the node whose next node is to deleted : ");
            scanf("%d", &given);
            delete_after(&start, given);
            break;

        case 9:
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

void add_node_beginning(struct node** start, int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->prev = NULL;
    ptr->next = *start;
    *start = ptr;
}

void delete_first(struct node** start)
{
    struct node* t = *start;
    *start = (*start)->next;
    free(t);
}

void delete_last(struct node** last)
{
    struct node*t = *last;
    *last = (*last)->prev;
    (*last)->next = NULL;
    free(t);
}

void delete_after(struct node** start, int given)
{
    struct node *temp = *start;
    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }
    struct node* t = temp->next;
    temp->next = temp->next->next;
    free(t);    
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