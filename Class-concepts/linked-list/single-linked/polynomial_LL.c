#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node* next;
};

void poly(struct node** start,int coeff,int expo);

void poly_print(struct node* start);

int main()
{
    struct node* start = NULL;
    int expo, coeff, choice;
    printf("Enter 1 to enter exponent value followed by coefficient else enter 0\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter exponent value and coefficient value : ");
            scanf("%d%d",&expo,&coeff);
            poly(&start,coeff,expo);
            break;
        
        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (choice != 0);

    printf("Polynomial is : \n");
    poly_print(start);  
    printf("\n");  
}

void poly(struct node** start,int coeff,int expo)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));

    ptr->coeff = coeff;
    ptr->expo = expo;
    ptr->next = NULL;

    struct node* temp = *start;
    
    if(*start == NULL)
        *start = ptr;
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void poly_print(struct node*start)
{
    struct node* temp = start;

    while(temp != NULL)
    {
        if(temp != start && temp->coeff > 0)
            printf("+");

        if(temp->coeff == 0)
            temp = temp->next;

        else if(temp->expo == 1)
        {
            printf("%dx ",temp->coeff);
            temp = temp->next;
        }

        else if( temp->expo == 0)
        {
            printf("%d ",temp->coeff);
            temp = temp->next;
        } 
        else
        {
            printf("%dx^%d ",temp->coeff,temp->expo);
            temp = temp->next;
        }
    }
}