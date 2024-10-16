#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
} *root;

void create(int n);
int height(struct node* root);

int main()
{
    printf("1. To enter a value\n");
    printf("2. Total number of nodes\n");
    int choice, data;
    do
    {
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            create(data);
            break;
        
        case 2:
            printf("%d\n",height(root));
            break;

        case 0:
            break;            
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (choice != 0);
    
    
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

int height(struct node* root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lheight = height(root->lptr);
        int rheight = height(root->rptr);

        if(lheight > rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
}