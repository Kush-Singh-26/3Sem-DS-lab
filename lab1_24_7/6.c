//create a menu driven program to calculate area of square, rectangle , triangle and circle
#include <stdio.h>

int rectangle(int *, int *);
int square(int *);
float circle(int *);
float triangle(int *, int *);

int main()
{
    int y = 1;
    while (y)
    {
        printf("Enter your choice : \n");
        printf("1 - Area of rectangle\n");
        printf("2 - Area of square\n");
        printf("3 - Area of circle\n");
        printf("4 - Area of triangle\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the 2 different sides of rectangle : ");
            int length, width;
            scanf("%d %d", &length, &width);
            printf("Area is : %d\n", rectangle(&length, &width));
            break;

        case 2:
            printf("Enter the side of square : ");
            int side;
            scanf("%d", &side);
            printf("Area is : %d\n", square(&side));
            break;

        case 3:
            printf("Enter the radius of circle : ");
            int radius;
            scanf("%d", &radius);
            printf("Area is : %f\n", circle(&radius));
            break;

        case 4:
            printf("Enter the base and height of triangle : ");
            int base, height;
            scanf("%d %d", &base, &height);
            printf("Area is : %f\n", triangle(&base, &height));
            break;

        default:
            printf("Wrong input. Try again!\n");
            break;
        }

        printf("Enter 1 to calculate different area. Otherwise enter 0\n");
        scanf("%d", &y);
    }

    return 0;
}

int rectangle(int *length, int *width)
{
    return *length * *width;
}

int square(int *side)
{
    return *side * *side;
}

float circle(int *radius)
{
    return (3.14 * (*radius) * (*radius)); 
}

float triangle(int *base, int *height)
{
    return (0.5 * (*base) * (*height)); 
}
