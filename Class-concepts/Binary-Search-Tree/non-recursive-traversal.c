#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
} *root = NULL;

struct stac
{
    struct node* ele;
    struct stac* next;
} *st1 = NULL , *st2 = NULL;

void create(int n);

void preorder_iterative(struct node* root);
void inorder_iterative(struct node* root);
void postorder_iterative(struct node* root);

void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);

void push(struct node* n, struct stac** st);
struct node* pop(struct stac** st);

int main()
{
    printf("1. Enter new data \n");
    printf("2. Preorder traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Preorder traversal recursive\n");
    printf("6. Inorder Traversal recursive\n");
    printf("7. Postorder Traversal recursive\n");
    printf("0. EXIT\n");
    int choice,n;
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to be entered : ");
                scanf("%d",&n);
                create(n);
                break;

            case 2:
                preorder_iterative(root);
                break;

            case 3:
                inorder_iterative(root);
                break;
            
            case 4:
                postorder_iterative(root);
                break;

            case 5:
                preorder(root);
                printf("\n");
                break;
            
            case 6:
                inorder(root);
                printf("\n");
                break;

            case 7:
                postorder(root);
                printf("\n");
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice\n");
                break;
        }
    }while(choice != 0);
};

void create(int n)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data = n;
    new->left = NULL;
    new->right = NULL;

    struct node* ptr = root;
    struct node* par = NULL;

    if(root == NULL)
        root = new;
    else
    {
        while(ptr != NULL)
            {
                par = ptr;
                if(ptr->data >n)
                    ptr = ptr->left;
                else    
                    ptr = ptr->right;
            }

            if(par->data > n)
                par->left = new;
            else    
                par->right = new;
    }
    
}


void preorder_iterative(struct node* root)
{
    if(root == NULL) return;
    struct node* current = root;
    while(current != NULL || st1 != NULL)
    {
        while(current != NULL)
        {
            printf("%d ",current->data);
            if(current->right != NULL)
                push(current->right,&st1);
            current = current->left;
        }

        if(st1 != NULL)
            current = pop(&st1);
    }
    printf("\n");
}

void inorder_iterative(struct node* root)
{
    if(root == NULL) return;
    struct node* current = root;
    while(current != NULL || st1 != NULL)
    {

        if(current != NULL)
        {
            push(current,&st1);
            current = current->left;
        }

        else
        {
            current = pop(&st1);
            printf("%d ",current->data);
            current = current->right;
        }
    }
    printf("\n");
}

void postorder_iterative(struct node* root)
{
    if(root == NULL) return;
    struct node* temp = NULL;
    push(root,&st1);
    while(st1 != NULL)
    {
        temp = pop(&st1);
        push(temp,&st2);

        if(temp->left) 
            push(temp->left,&st1);
        if(temp->right)
            push(temp->right,&st1);
    }

    while(st2 != NULL)
    {
        temp = pop(&st2);
        printf("%d ",temp->data);
    }
    printf("\n");
}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void push(struct node* n, struct stac** st)
{
    struct stac* ptr = (struct stac*)malloc(sizeof(struct stac));
    ptr->ele = n;
    ptr->next = *st;
    *st = ptr;
}

struct node* pop(struct stac** st)
{
    if(*st == NULL) return NULL;
    struct node* node = (*st)->ele;
    struct stac* temp = *st;
    *st = (*st)->next;
    free(temp);
    return node;
}
