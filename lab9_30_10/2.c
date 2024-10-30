// Merge sort// Merge Sort
#include<stdio.h>

void merge_sort(int a[],int lb, int ub);
void merge(int a[], int lb, int mid, int ub);

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
    
    merge_sort(a,0,n-1);

    printf("\nSorted array is : \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\n");

        return 0;
}

void merge_sort(int a[],int lb, int ub)
{
    int mid;
    if(lb<ub)
    {
        mid = (lb+ub)/2;
        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void merge(int a[], int lb, int mid, int ub)
{
    int b[(ub - lb +1)];
    int left = lb;
    int right = mid+1;
    int i = 0;
    while(left <= mid && right <= ub)
    {
        if(a[left] < a[right])
        {
            b[i] = a[left];
            i++;
            left++;
        }
        else
        {
            b[i] = a[right];
            i++;
            right++;
        }
    }

    while(left <= mid)
    {
        b[i] = a[left];
        i++;
        left++;
    }

    while(right <= ub)
    {
        b[i] = a[right];
        i++;
        right++;
    }

    for(int j = lb; j<=ub; j++)
        a[j] = b[j-lb];

}