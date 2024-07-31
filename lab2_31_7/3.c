//create a 4 by 4 array with main diagonal elements 1 and other 0.
#include<stdio.h>
int main()
{
    int a[4][4];
    for(int i =0;i<4;i++)
        {
        for(int j =0;j<4;j++)
        {
            if( i == j) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for(int i =0;i<4;i++)
        {
        for(int j =0;j<4;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}