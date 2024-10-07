#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
} (*root) = NULL;

struct stack
{
    struct node* data;
    struct stack* next;
};

void push(struct stack** start, struct node* n);
void pop(struct stack** start, struct node** n);

struct node* createNode(int n);
void insert(struct node** current, int n);
void create(struct node** root);
void preorder_traversal(struct node* root);
void preorder_traversal_iterative(struct node* root);

int main()
{
    create(&root);
    printf("Iterative Preorder Traversal:\n");
    preorder_traversal_iterative(root);
    printf("\n");

    return 0;   
}

struct node* createNode(int n)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = n;
    ptr->lptr = NULL;
    ptr->rptr = NULL;
    return ptr;
}

void insert(struct node** current, int n)
{
    if (*current == NULL)  
    {
        *current = createNode(n);
    }
}

void create(struct node** root)
{
    insert(root, 10);                         
    insert(&((*root)->lptr), 20);             
    insert(&((*root)->lptr->lptr), 40);       
    insert(&((*root)->lptr->rptr), 50);       
    insert(&((*root)->rptr), 30);             
    insert(&((*root)->rptr->lptr), 60);       
    insert(&((*root)->rptr->rptr), 70);       
}
/*
        Tree created looks like :
        
                            10
                    20              30
                40      50      60      70                          
    */


void preorder_traversal_iterative(struct node* root)
{
    struct stack* s = NULL; 
    struct node* current = root;

    while(current != NULL || s!= NULL)
    {
        while(current != NULL)
        {
            printf("%d ",current->data);

            if(current->rptr != NULL)
            {
                push(&s,current->rptr);
            }
            current = current->lptr;
        }

        if(s != NULL)
        pop(&s,&current);
    }
}

void push(struct stack** start, struct node* n)
{
    struct stack* ptr = (struct stack*) malloc(sizeof(struct stack));
    ptr->data = n;
    ptr->next = (*start);
    *start = ptr;
}

void pop(struct stack** start, struct node** n)
{
    
        *n = (*start)->data;
        struct stack* t = *start;
        *start = (*start)->next;
        free(t);
    
}
