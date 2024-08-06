#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n;
    printf("Enter the size of the  A array m x n : ");
    scanf("%d%d",&m,&n);

    int **ptr = (int**) malloc(m * sizeof(int*));

    for(int i =0;i<n;i++)
        *(ptr+i) = (int*) malloc(n * sizeof(int));


    printf("Enter the elements of the matrix A : ");

    for(int i =0;i<m;i++)
        for(int j =0;j<n;j++)
            scanf("%d",& *(*(ptr + i) + j));


    int** ptrb = (int**) malloc(m * sizeof(int*));
    for(int i = 0;i<n;i++)
        *(ptrb + i) = (int*) malloc(n * sizeof(int)); 

    printf("Enter the elemnts of the matrix B : ");
    for(int i = 0;i<m;i++)
        for(int j =0;j<n;j++)
            scanf("%d",& *(*(ptrb+i)+j));

    int** ptrc = (int**) malloc(m * sizeof(int*));
    for(int i = 0;i<n;i++)
        *(ptrc+i) = (int*) malloc(n * sizeof(int));

    for(int i =0;i<m; i++)
        for(int j =0;j<n;j++)
            *(*(ptrc + i)+j) = *(*(ptr + i)+j) + *(*(ptrb + i)+j);

    
    printf("Sum of Matrix A and B is : ");
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
            printf("%d ",*(*(ptrc + i) + j));
        printf("\n");
    }
    return 0;

}


