#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
};

struct node* buildTree(int* preorder, int* inorder, int start, int end, int* preIndex);

void preorderT(struct node* root);
void inorderT(struct node* root);
void postorderT(struct node* root);

int main()
{
    int n;
    printf("Enter the number of elemnts in the BST : ");
    scanf("%d",&n);

    int preorder[n];
    int inorder[n];

    printf("Enter the preorder traversal : \n");
    for(int i = 0;i<n;i++)
        scanf("%d",&preorder[i]);

    printf("Enter the inorder traversal : \n");
    for(int i = 0;i<n;i++)
        scanf("%d",&inorder[i]);

    int preIndex = 0;
    struct node* root = buildTree(preorder, inorder, 0, n-1, &preIndex);

    printf("Preorder traversal of the constructed BST: ");
    preorderT(root);
    printf("\n");

    printf("Inorder traversal of the constructed BST: ");
    inorderT(root);
    printf("\n");

    printf("Postorder traversal of the constructed BST: ");
    postorderT(root);
    printf("\n");
    return 0;
}

struct node* buildTree(int* preorder, int* inorder, int start, int end, int* preorderIndex)
{
    if(start > end) return NULL;

    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data = preorder[*preorderIndex];
    new->lptr = new->rptr = NULL;
    (*preorderIndex)++;

    if(start == end)
        return new;
    
    int inorderIndex;
    for(inorderIndex = start;inorderIndex<=end;inorderIndex++)
        if(inorder[inorderIndex] == new->data) break;
    
    new->lptr = buildTree(preorder, inorder, start, inorderIndex-1,preorderIndex);
    new->rptr = buildTree(preorder, inorder, inorderIndex+1, end,preorderIndex);
    
    return new;
}

void preorderT(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorderT(root->lptr);
        preorderT(root->rptr);
    }
}

void inorderT(struct node* root)
{
    if(root != NULL)
    {
        inorderT(root->lptr);
        printf("%d ",root->data);
        inorderT(root->rptr);
    }
}

void postorderT(struct node* root)
{
    if(root != NULL)
    {
        postorderT(root->lptr);
        postorderT(root->rptr);
        printf("%d ",root->data);
    }
}
