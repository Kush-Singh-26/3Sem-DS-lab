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

void poly_sum(struct node**start1, struct node** start2, struct node** start3);
int main()
{
    struct node* start1 = NULL;
    struct node* start2 = NULL;
    struct node* start3 = NULL;
    int expo, coeff, choice;
    printf("Enter 1 to enter exponent value followed by coefficient else enter 0\n");
    printf("Enter polynomial 1 :\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter exponent value and coefficient value : ");
            scanf("%d%d",&expo,&coeff);
            poly(&start1,coeff,expo);
            break;
        
        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (choice != 0);

    printf("Enter polynomial 1 :\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter exponent value and coefficient value : ");
            scanf("%d%d",&expo,&coeff);
            poly(&start2,coeff,expo);
            break;
        
        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (choice != 0);

    printf("Polynomial 1 is : \n");
    poly_print(start1);  
    printf("\n");  
    printf("Polynomial 2 is :\n");
    poly_print(start2);
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