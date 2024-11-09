// Merge Sort
#include<stdio.h>

void swap(int* a, int* b);
int partition(int a[], int low, int high);
void quick_sort(int a[], int low, int high);


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
    
    quick_sort(a,0,n-1);

    printf("\nSorted array is : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\n");

        return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = a[low];
    while(i<j)
    {
        while(a[i] <= pivot && i <= high-1)
            i++;
        while(a[j] > pivot && j >= low+1)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[low],&a[j]);
    return j;  
        
}
void quick_sort(int a[], int low, int high)
{
    if(low < high)
    {
        int pIndex = partition(a,low,high);
        quick_sort(a, low, pIndex - 1);
        quick_sort(a, pIndex+1, high);
    }
}