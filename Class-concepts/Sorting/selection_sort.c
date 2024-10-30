#include<stdio.h>
#include<stdlib.h>

void selection_sort(int a[], int n);
void swap(int* a, int* b);
int smallest(int a[], int k, int n);

int main()
{
    printf("Enter the size of the array : ");
    int n; scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array : \n");
    for(int i =0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("Entered arary is : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    
    selection_sort(a,n);

    printf("\nSorted array is : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\n");

    return 0;
}

int smallest(int a[], int k, int n)
{
    int pos = k;
    for(int i = k ;i<n;i++)
    {
        if(a[i] < a[pos])
        {
            pos = i;
        }
    }
    return pos;
}

void selection_sort(int a[], int n)
{
    for(int i =0;i<n;i++)
    {
        int p = smallest(a,i,n);
        swap(&a[i],&a[p]);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}