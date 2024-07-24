//display all even numbers first and then odd numbers
#include<stdio.h>
void sort(int a[], int n);

int main()
{
	printf("Enter the size of the array : ");
	int n;
	scanf("%d",&n);
	printf("Enter %d integers : ",n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	sort(a,n);

	printf("Sortd array is : \n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

void sort(int a[],int n)
{
	int i = 0;
	int j = 0;
	
	for(int i =0;i<n;i++)
	{
		if(a[i] %2 == 0)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			j++;
		}
	}
}
	
	
	
	
