#include <stdio.h>

int main()
{
    int r, c, k = 0;
    printf("Enter the number of rows and columns of sparse matrix 1: ");
    scanf("%d%d", &r, &c);
    int a[r][c];
    printf("Enter the values of the sparse matrix 1\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    int s[100][3];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
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

    int m, n, l = 0;
    printf("Enter the number of rows and columns of sparse matrix 2: ");
    scanf("%d%d", &m, &n);
    int b[m][n];
    printf("Enter the values of the sparse matrix 2\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    int t[100][3];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] != 0)
            {
                l++;
                t[l][0] = i;
                t[l][1] = j;
                t[l][2] = b[i][j];
            }
        }
    }

    t[0][0] = m;
    t[0][1] = n;
    t[0][2] = l;

    printf("\nSparse Matrix 1: \n");

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    printf("\nSparse Matrix 2: \n");

    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    int ans[100][3];

    int i = 1, j = 1;
    k = 1;
    if (s[0][0] != t[0][0] || s[0][1] != t[0][1])
    {
        printf("Addition is not possible !\n");
        return 0;
    }

    while (i <= s[0][2] && j <= t[0][2])
    {
        if (s[i][0] == t[j][0])
        {
            if (s[i][1] == t[j][1])
            {
                ans[k][0] = s[i][0];
                ans[k][1] = s[i][1];
                ans[k][2] = s[i][2] + t[j][2];
                i++;
                j++;
                k++;
            }

            else
            {
                if (s[i][1] < t[j][1])
                {
                    ans[k][0] = s[i][0];
                    ans[k][1] = s[i][1];
                    ans[k][2] = s[i][2];
                    k++;
                    i++;
                }

                else
                {
                    ans[k][0] = t[j][0];
                    ans[k][1] = t[j][1];
                    ans[k][2] = t[j][2];
                    k++;
                    j++;
                }
            }
        }

        else
        {
            if (s[i][0] < t[j][0])
            {
                ans[k][0] = s[i][0];
                ans[k][1] = s[i][1];
                ans[k][2] = s[i][2];
                k++;
                i++;
            }

            else
            {
                ans[k][0] = t[j][0];
                ans[k][1] = t[j][1];
                ans[k][2] = t[j][2];
                k++;
                j++;
            }
        }
    }

    while (i <= s[0][2])
    {
        ans[k][0] = s[i][0];
        ans[k][1] = s[i][1];
        ans[k][2] = s[i][2];
        k++;
        i++;
    }

    while (j <= t[0][2])
    {
        ans[k][0] = t[j][0];
        ans[k][1] = t[j][1];
        ans[k][2] = t[j][2];
        k++;
        j++;
    }

    ans[0][0] = s[0][0];
    ans[0][1] = s[0][1];
    ans[0][2] = k;
    printf("\n Added matrix is : \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}