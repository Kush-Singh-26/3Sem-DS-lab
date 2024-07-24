//swpa contents of 2 variables using call by value and call by reference
#include<stdio.h>

void passByValue(int,int);
void passByReference(int *,int *);

int main()
{
	printf("Enter 2 integers : ");
	int x,y;
	scanf("%d%d",&x,&y);
	
	passByValue(x,y);
	passByReference(&x,&y);

	return 0;
}

void passByValue(int a, int b)
{
	a = a+b;
	b = a-b;
	a = a-b;
	
	printf("Values after swaping pass by value are : %d and %d\n",a,b);
}

void passByReference(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	
	printf("Values after swaping pass by refernece are : %d and %d\n",*a,*b);

}
