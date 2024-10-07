#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
} (*root) = NULL;

struct node* createNode(int n);
void insert(struct node** current, int n);
void create(struct node** root);

int main()
{
    create(&root);
    return 0;

    /*
        tree creates looks like :
        
                            10
                    20              30
                40      50      60      70                          
    */
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