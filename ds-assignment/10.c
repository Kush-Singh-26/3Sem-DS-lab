#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct stac
{
    struct node* data;
    struct stac* next;
};

void preorder(struct node* root);
void push(struct stac **top, struct node *n);
struct node *pop(struct stac **top);
struct node* createnode(char c);
int isOperator(char c);
void post_to_pre(char* str);
void preorder(struct node* root);

int main()
{
    char str[100];
    printf("Enter the postfix expression: ");
    scanf("%s", str);  
    printf("Postorder Traversal: %s\n", str);
    printf("Preorder Traversal: ");
    post_to_pre(str);
    printf("\n");

    return 0;
}

void push(struct stac **top, struct node *n)
{
    struct stac *newNode = (struct stac *)malloc(sizeof(struct stac));
    newNode->data = n;
    newNode->next = *top;
    *top = newNode;
}

struct node *pop(struct stac **top)
{
    if (*top == NULL)
        return NULL;
    struct node *n = (*top)->data;
    *top = (*top)->next;
    return n;
}

struct node* createnode(char c)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = c;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int isOperator(char c)
{
    return (c == '/' || c == '+' || c == '-' || c == '*' || c == '^');
}

void post_to_pre(char* str)
{
    struct stac* st = NULL;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        char c = str[i];

        if(isalnum(c))
        {
            struct node* newnode = createnode(c);
            push(&st, newnode);
        }
        else if(isOperator(c))
        {
            struct node* opnode = createnode(c);
            struct node* rightchild = pop(&st);
            struct node* leftchild = pop(&st);
            opnode->left = leftchild;
            opnode->right = rightchild;

            push(&st, opnode); 
        }
    }

    struct node* root = pop(&st);

    preorder(root);
}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


