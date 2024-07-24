#include<stdio.h>

int average(int a[]);

int main()
{
	printf("Enter 10 integers : ");
	int a[10];
	for(int i =0;i<10;i++)
		scanf("%d",&a[i]);
	
	printf("Average is : %d\n",average(a));
	
	return 0;
}

int average(int a[])
{
	int sum =0;
	for(int i =0;i<10;i++)
		sum += a[i];
	return sum/10;
}
