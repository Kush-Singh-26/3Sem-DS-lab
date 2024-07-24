#include<stdio.h>

int simpleInterest(int *,int *,int *);

int main()
{
	printf("Enter Principal, Time and Rate : ");
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	
	
	printf("Simple Interest is : %d\n",simpleInterest(&x,&y,&z));

	return 0;
}

int simpleInterest(int *p,int *t,int *r)
{
	return (*p * *t * *r)/100;
}


