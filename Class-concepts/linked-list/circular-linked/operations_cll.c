#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void create(struct node** start, int n);

void print(struct node*);

void delete_first(struct node**);

int main()
{
    struct node* start = NULL;
    int data, choice, given;

    printf("1. To create / add an element to a list.\n");
    printf("2. Display / traverse the list.\n");
    printf("3. To delete the forst node.\n");
    do
    {   
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be entered : ");
            scanf("%d",&data);
            create(&start,data);
            break;
        
        case 2:
            print(start);
            printf("\n");
            break;

        case 3:
            delete_first(&start);
            break;

        case 0:
            break;

        default:
            printf("Incorrect choice.\n");
            break;
        }
    } while (choice != 0);
    
    return 0;
}

void create(struct node** start, int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = *start;
    if(*start == NULL)
    {
        *start = ptr;
        ptr->next = ptr;
    }

    else
    {
        struct node* t = *start;
        while(t->next != *start)
            t = t->next;
        t->next = ptr;
    }
}

void print(struct node*start)
{
    if(start == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    struct node* temp = start;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != start);
}

void delete_first(struct node** start)
{
    struct node* t1 = *start, *t = *start;
    while(t->next != *start)
        t = t->next;
    *start = (*start)->next;
    t->next = *start;
    free(t1);
}