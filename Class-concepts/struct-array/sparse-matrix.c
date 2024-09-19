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
    printf("%d %d %d\n",m,n,k-1);
    for (i = 1; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void convert(int a[][3], int m, int n, int* l, int st[][3]) {
    *l = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                (*l)++;  
                st[*l][0] = i;
                st[*l][1] = j;
                st[*l][2] = a[i][j];
            }
        }
    }
    st[0][0] = m;  
    st[0][1] = n;  
    st[0][2] = *l; 
}

void add(int* r, int st1[][3], int st2[][3], int st3[][3]) {
    if (st1[0][0] != st2[0][0] || st1[0][1] != st2[0][1]) {
        printf("Addition not possible \n");
        return;
    }

    int i = 1, j = 1;
    *r = 0;  

    while (i <= st1[0][2] && j <= st2[0][2]) {
        if (st1[i][0] == st2[j][0]) {
            if (st1[i][1] == st2[j][1]) {
                (*r)++;
                st3[*r][0] = st1[i][0];
                st3[*r][1] = st1[i][1];
                st3[*r][2] = st1[i][2] + st2[j][2];
                i++;
                j++;
            } else if (st1[i][1] < st2[j][1]) {
                (*r)++;
                st3[*r][0] = st1[i][0];
                st3[*r][1] = st1[i][1];
                st3[*r][2] = st1[i][2];
                i++;
            } else {
                (*r)++;
                st3[*r][0] = st2[j][0];
                st3[*r][1] = st2[j][1];
                st3[*r][2] = st2[j][2];
                j++;
            }
        } else if (st1[i][0] < st2[j][0]) {
            (*r)++;
            st3[*r][0] = st1[i][0];
            st3[*r][1] = st1[i][1];
            st3[*r][2] = st1[i][2];
            i++;
        } else {
            (*r)++;
            st3[*r][0] = st2[j][0];
            st3[*r][1] = st2[j][1];
            st3[*r][2] = st2[j][2];
            j++;
        }
    }

    while (i <= st1[0][2]) {
        (*r)++;
        st3[*r][0] = st1[i][0];
        st3[*r][1] = st1[i][1];
        st3[*r][2] = st1[i][2];
        i++;
    }

    while (j <= st2[0][2]) {
        (*r)++;
        st3[*r][0] = st2[j][0];
        st3[*r][1] = st2[j][1];
        st3[*r][2] = st2[j][2];
        j++;
    }

    st3[0][0] = st1[0][0];  
    st3[0][1] = st1[0][1];  
    st3[0][2] = *r;         
}