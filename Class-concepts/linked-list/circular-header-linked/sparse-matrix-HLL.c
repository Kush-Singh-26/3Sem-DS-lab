#include<stdio.h>
#include<stdlib.h>

struct data_node
{
    int rowcor;
    int colcor;
    int value;
    struct data_node* next;
};

struct head_node
{
    int row;
    int col;
    int no_ele;
    struct data_node* next;
};

void initialize(struct head_node** start_head, struct data_node** start_data,int row, int col);

void create_list (struct head_node** start_head, struct data_node** start_data, int n,int rowval,int colval);

void print_list(struct head_node** start_head, struct data_node** start_data);

int main()
{
    int row, col;
    printf("Enter the number of rows and columns of the sparse matrix : ");
    scanf("%d%d",&row,&col);
    int a[row][col];
    printf("Enter the elements of the matrix : \n");
    for(int i =0;i<row;i++)
        for(int j =0;j<col;j++)
            scanf("%d",&a[i][j]);

    printf("The matrix enetered is : \n");
    for(int i =0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }

    struct head_node* start_head = NULL;
    struct data_node* start_data = NULL;

    initialize(&start_head,&start_data,row,col);

    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            if(a[i][j] != 0)
            {
                create_list(&start_head,&start_data,a[i][j],i,j);
            }
        }
    }

    printf("Sparse Matirx is 3-tuple format : \n");
    print_list(&start_head,&start_data);
    printf("\n");

}

void initialize(struct head_node** start_head, struct data_node** start_data,int row, int col)
{
    if(*start_head == NULL)
    {
        struct head_node* ptrh = (struct head_node*) malloc(sizeof(struct head_node));
        *start_head = ptrh;
        ptrh->col = col;
        ptrh->row = row;
        ptrh->no_ele = 0;
        ptrh->next = *start_data;
    }
}

void create_list (struct head_node** start_head, struct data_node** start_data, int n,int rowval,int colval)
{
    struct data_node* ptr = (struct data_node*) malloc(sizeof(struct data_node));

    ptr->colcor = colval;
    ptr->rowcor = rowval;
    ptr->value = n;
    ptr->next = NULL;

    if(*start_data == NULL)
    {
        *start_data = ptr;
        (*start_head)->no_ele++;
        return;
    }

    struct data_node* temp = *start_data;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = ptr;
    (*start_head)->no_ele++;
}

void print_list(struct head_node** start_head, struct data_node** start_data)
{
    printf("%d %d %d\n",(*start_head)->row, (*start_head)->col,(*start_head)->no_ele);
    
    struct data_node* temp = *start_data;

    while(temp != NULL)
    {
        printf("%d %d %d\n",temp->rowcor, temp->colcor,temp->value);
        temp = temp->next;
    }

}