#include<stdio.h>

void bubble_sort(int a[], int n);

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
    
    bubble_sort(a,n);

    printf("\nSorted array is : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\n");

    return 0;
}

void bubble_sort(int a[], int n)
{
    for(int i =0;i<n-1;i++)
    {
        int swapped = 0;
        for(int j = 0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = 1;  
            }
        }
        if(swapped == 0)
            break;
    }
}