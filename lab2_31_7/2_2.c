#include<stdio.h>
#include<stdlib.h>
int main(){
int n =5;
int *p= (int *) malloc(n * sizeof(int));

for(int i =0;i<n;i++)
	scanf("%d",p+i);

for(int i =0;i<n;i++)
	printf("%d ",*(p+i));

printf("\n");
}

