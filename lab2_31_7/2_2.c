//input and print an array using dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>
int main(){
printf("Enter the size of the array : ");
int n;
scanf("%d",&n);
int *p= (int *) malloc(n * sizeof(int));

for(int i =0;i<n;i++)
	scanf("%d",p+i);

for(int i =0;i<n;i++)
	printf("%d ",*(p+i));

printf("\n");
}

