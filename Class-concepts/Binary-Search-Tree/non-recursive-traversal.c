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
} *st = NULL;

void create(int n);

void preorder_iterative(struct node* root);
void inorder_iterative(struct node* root);

void preorder(struct node* root);
void inorder(struct node* root);

void push(struct node* n);
struct node* pop();

int main()
{
    printf("1. Enter new data \n");
    printf("2. Preorder traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Preorder traversal recursive\n");
    printf("5. Inorder Traversal recursive\n");
    printf("0. EXIT\n");
    int choice,n;
    do
    {
        printf("Enter your choice :");
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
                preorder(root);
                printf("\n");
                break;
            
            case 5:
                inorder(root);
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
    struct node* current = root;
    while(current != NULL || st != NULL)
    {
        while(current != NULL)
        {
            printf("%d ",current->data);
            if(current->right != NULL)
                push(current->right);
            current = current->left;
        }

        if(st != NULL)
            current = pop();
    }
    printf("\n");
}

void inorder_iterative(struct node* root)
{
    struct node* current = root;
    while(current != NULL || st != NULL)
    {

        if(current != NULL)
        {
            push(current);
            current = current->left;
        }

        else
        {
            current = pop();
            printf("%d ",current->data);
            current = current->right;
        }
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

void push(struct node* n)
{
    struct stac* ptr = (struct stac*)malloc(sizeof(struct stac));
    ptr->ele = n;
    ptr->next = st;
    st = ptr;
}

struct node* pop()
{
    if(st == NULL) return NULL;
    struct node* node = st->ele;
    struct stac* temp = st;
    st = st->next;
    free(temp);
    return node;
}
