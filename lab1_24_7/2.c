#include<stdio.h>
int largest(int a[]);
int secondLargest(int a[]);

int main()
{
	int a[10];
	printf("Enter 10 integers : ");
	for(int i =0;i<10;i++)
		scanf("%d",&a[i]);
	
	printf("Largest integer is : %d\n",largest(a));
	printf("Second largest integer is : %d\n", secondLargest(a));
	
	return 0;
}

int largest(int a[])
{
	int largest = a[0];
	
	for(int i = 1;i<10;i++)
		if(a[i] > largest)
			largest = a[i];
	return largest;
}
	
int secondLargest(int a[])
{
	int largest = a[0];
	int secondL = a[0];
	for(int i =1;i<10;i++)
	{
		if(a[i]> largest )
			{
				secondL = largest;
				largest = a[i];
			}
		else if(a[i] <largest && a[i] > secondL)
			secondL = a[i];
	}
	return secondL;
}
