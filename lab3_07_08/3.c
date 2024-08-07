#include<stdio.h>

int main()
{
    int r,c,k=0;
    printf("Enter the number of rows and columns : ");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("Enter the values of the sparse matrix\n");
    for(int i =0;i<r;i++)
        for(int j =0;j<c;j++)
            scanf("%d",&a[i][j]);
    
    int s[100][3];

    for(int i =0;i<r;i++)
    {
        for(int j =0;j<c;j++)
        {
            if(a[i][j] != 0)
            {
                k++;
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
            }
        }
    }

    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = k;

    printf("%d",k);
    printf("\nSparse Matrix : \n");

    for(int i =0;i<=k;i++)
    {
        for(int j =0;j<3;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }

    return 0;

}