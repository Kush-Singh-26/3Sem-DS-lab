#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* rptr;
    struct node* lptr;
} *root = NULL;

void create(int n);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);

int main()
{
    printf("1. To enter a value\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
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