#include<stdio.h>

int main()
{
    printf("Enter the no of row and col of the sparse matrix : ");
    int row, col;
    scanf("%d%d",&row,&col);
    int a[row][col];
    printf("Enter the elements of the matrix : \n");

    for(int i =0;i<row;i++)
        for(int j = 0;j<col;j++)
            scanf("%d",&a[i][j]);

    int s[100][3];

    int k = 0;
    for(int i = 0;i<row;i++)
    {
        for(int j =0;j<col;j++)
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

    s[0][0] = row;
    s[0][1] = col;
    s[0][2] = k;

    printf("Sparse Matrix in 3-triplet format : \n");

    for(int i =0;i<=k;i++)
    {
        for(int j =0;j<3;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }

    int st[k+1][3];

    st[0][0] = s[0][1];
    st[0][1] = s[0][0];
    st[0][2] = s[0][2];

    int str=1;
    for(int i = 0; i<col;i++)
    {
        for(int j =1;j<=k;j++)
        {
            if(s[j][1] == i)
            {
                st[str][0] = s[j][1];
                st[str][1] = s[j][0];
                st[str][2] = s[j][2];
                str++;
            }
        }
    }
    
    printf("Transpose of Sparse Matrix in 3-triplet format : \n");

    for(int i =0;i<=k;i++)
    {
        for(int j =0;j<3;j++)
        {
            printf("%d ",st[i][j]);
        }
        printf("\n");
    }
    return 0;
}