/*
Creating a binary search tree (BST) where each node contains information about a product. The fields for each node are:

Product name
Product ID (used as the key for BST insertion)
Product type
Product price
Product company
The program should support the following menu-driven operations:

Display all products belonging to the company "HP" with a price less than 10,000.
Calculate the total price of products available from each company.
Check if the BST is height-balanced. (Height-balanced means the difference in height between the left and right subtrees for every node is at most 1.)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 50

struct node
{
    char pname[size];
    int pid;
    char ptype[size];
    int price;
    char cname[size];
    struct node* left;
    struct node* right;
} *root = NULL;

struct Company
{
    char cname[size];
    int total_price;
    struct Company* next;
} *companyList = NULL;

void create()
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    printf("Enter product name : ");
    scanf(" %[^\n]%*c",ptr->pname);
    printf("Enter product ID : ");
    scanf("%d", &(ptr->pid));
    printf("Enter product type : ");
    scanf(" %[^\n]%*c",ptr->ptype);
    printf("Enter product price : ");
    scanf("%d", &(ptr->price));
    printf("Enter company name : ");
    scanf(" %[^\n]%*c",ptr->cname);
    ptr->left = NULL;
    ptr->right = NULL;

    if (root == NULL)
    {
        root = ptr;
    }
    else
    {
        struct node* par = NULL;
        struct node* temp = root;

        while (temp != NULL)
        {
            par = temp;
            if (temp->pid > ptr->pid)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (par->pid > ptr->pid)
            par->left = ptr;
        else
            par->right = ptr;
    }
}

void product_from_HP(struct node* root)
{
    if (root != NULL)
    {
        if (!(strcmp(root->cname, "HP")) && root->price < 10000)
        {
            printf("Product name : %s, Product type : %s, Product Id : %d, Product Company : %s, Product Price : %d\n",
                   root->pname, root->ptype, root->pid, root->cname, root->price);
        }
        product_from_HP(root->left);
        product_from_HP(root->right);
    }
}

void add_to_company_list(const char* cname, int price)
{
    struct Company* temp = companyList;

    while (temp != NULL)
    {
        if (strcmp(temp->cname, cname) == 0)
        {
            temp->total_price += price;
            return;
        }
        temp = temp->next;
    }

    struct Company* new_company = (struct Company*) malloc(sizeof(struct Company));
    strcpy(new_company->cname, cname);
    new_company->total_price = price;
    new_company->next = companyList;
    companyList = new_company;
}

void calculate_total_price(struct node* root)
{
    if (root != NULL)
    {
        add_to_company_list(root->cname, root->price);
        calculate_total_price(root->left);
        calculate_total_price(root->right);
    }
}

void display_company_totals()
{
    struct Company* temp = companyList;
    printf("Total price of products for each company:\n");
    while (temp != NULL)
    {
        printf("Company: %s, Total Price: %d\n", temp->cname, temp->total_price);
        temp = temp->next;
    }
}

int check_height_balance(struct node* root, int* height)
{
    if (root == NULL)
    {
        *height = 0;
        return 1;
    }

    int left_height = 0, right_height = 0;
    int left_balanced = check_height_balance(root->left, &left_height);
    int right_balanced = check_height_balance(root->right, &right_height);

    *height = (left_height > right_height ? left_height : right_height) + 1;

    if (abs(left_height - right_height) > 1)
        return 0;

    return left_balanced && right_balanced;
}

void is_balanced()
{
    int height = 0;
    if (check_height_balance(root, &height))
        printf("The BST is height balanced.\n");
    else
        printf("The BST is not height balanced.\n");
}


int main()
{
    int choice;
    printf("1. Create\n");
    printf("2. Product from HP\n");
    printf("3. Calculate total price for each company\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                product_from_HP(root);
                break;
            case 3:
                calculate_total_price(root);
                display_company_totals();
                break;
            
            case 4:
                is_balanced();
                break;
                
            default:
                printf("Incorrect choice:\n");
        }

    } while (choice != 0);

    return 0;
}
