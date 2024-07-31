//input and print an array using pointers
#include<stdio.h>
int main()
{
    int a[5];
    int *p = a;
    int n = 5;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",p+i);
    }

    for(int i =0;i<n;i++)
        printf("%d ",*(p+i));
    printf("\n");
}