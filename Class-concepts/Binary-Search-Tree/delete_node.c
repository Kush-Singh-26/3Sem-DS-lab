#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* rptr;
    struct node* lptr;
} *root = NULL;

struct q
{
    struct node* item;
    struct q* next;
} *f = NULL, *r = NULL;


void create(int n);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);
void level_order_traversal(struct node* root);

void insert_q(struct node* ele);
struct node* delete();

void delete_node(struct node* root,int n);
void delete_degree_0(struct node* ptr,struct node* par,int n);
void delete_degree_1(struct node* ptr,struct node* par,int n);
void delete_degree_2(struct node* ptr,int n);



int main()
{
    printf("1. To enter a value\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Level order Traversal\n");
    printf("6. Delete a node\n");
    printf("0. EXIT\n");

    int choice,data;
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            create(data);
            break;
        
        case 2:
            preorder(root);
            printf("\n");
            break;

        case 3:
            inorder(root);
            printf("\n");
            break;

        case 4:
            postorder(root);
            printf("\n");
            break;
        
        case 5:
            level_order_traversal(root);
            printf("\n");
            break;
        
        case 6:
            printf("Enter value to be deleted : ");
            scanf("%d",&data);
            delete_node(root,data);
            break;

        case 0:
            break;
        default:
            printf("Incorrect Choice\n");
            break;
        }
    } while (choice != 0);
    
    return 0;
}

void create(int n)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = n;
    new->lptr = NULL;
    new->rptr = NULL;
    struct node* ptr = root;
    struct node* par = NULL;

    if(root == NULL)
        root = new;
    else
    {
        while(ptr != NULL)
        {
            par = ptr;
            if(n<ptr->data)
                ptr = ptr->lptr;
            else
                ptr = ptr->rptr;
        }
        if(n < par->data)
            par->lptr = new;
        else
            par->rptr = new;
    }

}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->lptr);
        printf("%d ",root->data);
        inorder(root->rptr);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf("%d ",root->data);
    }
}

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


void delete_node(struct node* root,int n)
{
    struct node* par = NULL;
    struct node* ptr = root;

    while(ptr != NULL && ptr->data != n)
    {
        par = ptr;
        if(n<ptr->data)
            ptr = ptr->lptr;
        else
            ptr = ptr->rptr;
    }

    if(ptr == NULL)
    {
        printf("Value not found\n");
        return;
    }

    if(ptr->lptr == NULL && ptr->rptr == NULL)
        delete_degree_0(ptr,par,n);

    else if(ptr->lptr == NULL || ptr->rptr == NULL)
        delete_degree_1(ptr,par,n);

    else
        delete_degree_2(ptr,n);
        
}
void delete_degree_0(struct node* ptr,struct node* par,int n)
{
    if(par == NULL) root = NULL;

    else if(par->lptr->data == n)
        par->lptr = NULL;
    else
        par->rptr = NULL;
    free(ptr);
}

void delete_degree_1(struct node* ptr,struct node* par, int n)
{
    struct node* temp = (ptr->lptr != NULL) ? ptr->lptr : ptr->rptr;

    if(par == NULL)
        root = NULL;

    else if(par->lptr->data == n)
        par->lptr = temp;
    else
        par->rptr = temp;
    free(ptr);
}

void delete_degree_2(struct node* ptr, int n)
{
    struct node* min = ptr->rptr;
    struct node* par = ptr;

    while(min->lptr != NULL)
    {
        par = min;
        min = min->lptr;
    }

    ptr->data = min->data;

    if (par->lptr == min)
        par->lptr = min->rptr;  
    else
        par->rptr = min->rptr;      

    free(min);
}
