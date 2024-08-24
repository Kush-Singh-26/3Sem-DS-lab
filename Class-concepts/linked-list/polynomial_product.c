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

void poly_prod(struct node **start1, struct node **start2, struct node **start3);

void delete_duplicate_expo(struct node **start3);

void sort(struct node **start3);

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

    printf("Product of polynomial 1 and polynomial 2 is : \n");
    poly_prod(&start1, &start2, &start3);
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

void poly_prod(struct node **start1, struct node **start2, struct node **start3)
{
    struct node *t1 = *start1;
    while (t1 != NULL)
    {
        struct node *t2 = *start2;
        while (t2 != NULL)
        {
            poly(start3, t1->coeff * t2->coeff, t1->expo + t2->expo);
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    delete_duplicate_expo(start3);
    sort(start3);
}

void delete_duplicate_expo(struct node **start3)
{
    struct node *t3 = *start3;
    struct node *temp, *q, *p;
    while (t3 != NULL)
    {
        q = t3;
        p = t3->next;

        while (p != NULL)
        {
            if (t3->expo == p->expo)
            {
                t3->coeff = t3->coeff + p->coeff;
                temp = p;
                q->next = p->next;
                p = p->next;
                free(temp);
            }
            else
            {
                q = p;
                p = p->next;
            }
        }

        t3 = t3->next;
    }
}

void sort(struct node **start3)
{
    struct node *t3 = NULL;
    while (t3 != NULL)
    {
        struct node *temptr = t3->next;
        while (temptr != NULL)
        {
            if (t3->expo < temptr->expo)
            {
                int tempcoeff = t3->coeff;
                t3->coeff = temptr->coeff;
                temptr->coeff = tempcoeff;

                int tempexpo = t3->expo;
                t3->expo = temptr->expo;
                temptr->expo = tempexpo;
            }

            temptr = temptr->next;
        }
        t3 = t3->next;
    }
}
