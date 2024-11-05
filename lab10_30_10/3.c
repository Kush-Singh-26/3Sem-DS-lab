#include<stdio.h>

void insertion_sort(int a[], int n);

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
    
    insertion_sort(a,n);

    printf("\nSorted array is : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\n");

    return 0;
}


void insertion_sort(int a[], int n)
{
    for(int i = 1;i<n;i++)
    {
        int key = a[i] , j = i-1;
        while(j > -1 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}