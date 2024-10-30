#include<stdio.h>
#include<stdlib.h>

void heapify(int a[], int n, int i);
void build_heap(int a[], int n);
void swap(int *a, int *b);
void heap_sort(int a[], int n);

int main()
{
    printf("Enter the size of the array : ");
    int n; scanf("%d",&n);
    int a[n];
    
    printf("Enter the elements of the array : \n");
    for(int i =0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Entered array is : \n");
    for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
    
    build_heap(a,n);

    heap_sort(a,n);

    printf("\nSorted array : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}

void build_heap(int a[], int n)
{
    for(int i = (n/2)-1 ; i>= 0; i--)
    {
        heapify(a,n,i);
    }
}
void heapify(int a[], int n, int i)
{
    int left, right, max;
    left = (2*i) + 1;
    right = (2*i) + 2;
    max = i;
    if(left < n && a[max] < a[left])
        max = left;
    if(right < n && a[max] < a[right])
        max = right;
    
    if(max != i)
    {
        swap(&a[i], &a[max]);
        heapify(a, n, max);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(int a[], int n)
{
    while(n>1)
    {
        swap(&a[0], &a[n-1]);
        n--;
        heapify(a,n,0);
    }
}
