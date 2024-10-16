#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
} (*root) = NULL;

struct q
{
    struct node* item;
    struct q* next;
} *f = NULL, *r = NULL;


struct node* createNode(int n);
void insert(struct node** current, int n);
void create(struct node** root);
void level_order_traversal(struct node* root);

void insert_q(struct node* ele);
struct node* delete();


int main()
{
    create(&root);
    level_order_traversal(root);
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
        tree creates looks like :
        
                            10
                    20              30
                40      50      60      70                          
    */

void level_order_traversal(struct node* root)
{
    if(root == NULL) return;

    insert_q(root);

    while(f != NULL)
    {
        struct node* current = delete();

        printf("%d ",current->data);
        
        if(current->lptr != NULL)
            insert_q(current->lptr);
        if(current->rptr != NULL)
            insert_q(current->rptr);
    }

}

void insert_q(struct node* ele)
{
    struct q* ptr = (struct q*) malloc(sizeof(struct q));
    ptr->next = NULL;
    ptr->item = ele;

    if(f == NULL && r == NULL)
    {
        f = ptr;
        r = ptr;
    }
    else
    {
        r->next = ptr;
        r = r->next;
    }
}

struct node* delete()
{
    if(f == NULL)
        return NULL;
    
    struct q* temp = f;
    struct node* item = f->item;
    f = f->next;

    if(f == NULL)
        r = NULL;
    
    free(temp);
    return item;
}