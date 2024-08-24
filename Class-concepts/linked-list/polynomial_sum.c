#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

void poly(struct node **start, int coeff, int expo);

void poly_print(struct node *start);

void poly_sum(struct node **start1, struct node **start2, struct node **start3);

int main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    int expo, coeff, choice;
    printf("Enter 1 to enter exponent value followed by coefficient else enter 0\n");

    printf("Enter polynomial 1 :\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter exponent value and coefficient value : ");
            scanf("%d%d", &expo, &coeff);
            poly(&start1, coeff, expo);
            break;

        case 0:
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    } while (choice != 0);

    printf("Enter polynomial 2 :\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter exponent value and coefficient value : ");
            scanf("%d%d", &expo, &coeff);
            poly(&start2, coeff, expo);
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

    printf("Sum of polynomial 1 and polynomial 2 is : \n");
    poly_sum(&start1, &start2, &start3);
    poly_print(start3);
    printf("\n");
}

void poly(struct node **start, int coeff, int expo)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->coeff = coeff;
    ptr->expo = expo;
    ptr->next = NULL;

    struct node *temp = *start;

    if (*start == NULL)
        *start = ptr;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void poly_print(struct node *start)
{
    struct node *temp = start;

    while (temp != NULL)
    {
        if (temp != start && temp->coeff > 0)
            printf("+");

        if (temp->coeff == 0)
            temp = temp->next;

        else if (temp->expo == 1)
        {
            printf("%dx ", temp->coeff);
            temp = temp->next;
        }

        else if (temp->expo == 0)
        {
            printf("%d ", temp->coeff);
            temp = temp->next;
        }
        else
        {
            printf("%dx^%d ", temp->coeff, temp->expo);
            temp = temp->next;
        }
    }
}

void poly_sum(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *t1 = *start1;
    struct node *t2 = *start2;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->expo > t2->expo)
        {
            poly(start3, t1->coeff, t1->expo);
            t1 = t1->next;
        }

        else if (t1->expo < t2->expo)
        {
            poly(start3, t2->coeff, t2->expo);
            t2 = t2->next;
        }

        else
        {
            if (t1->coeff + t2->coeff != 0)
            {
                poly(start3, t1->coeff + t2->coeff, t1->expo);
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL)
    {
        poly(start3, t1->coeff, t1->expo);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        poly(start3, t2->coeff, t2->expo);
        t2 = t2->next;
    }
}