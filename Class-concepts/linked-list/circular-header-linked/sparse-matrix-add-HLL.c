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

void add(struct head_node** start_head1,struct data_node** start_data1,struct head_node** start_head2,struct data_node** start_data2,struct head_node** start_head3,struct data_node** start_data3);

int main()
{
    int row1, col1;
    printf("Enter the number of rows and columns of the sparse matrix 1 : ");
    scanf("%d%d",&row1,&col1);
    int a[row1][col1];
    printf("Enter the elements of the matrix 1 : \n");
    for(int i =0;i<row1;i++)
        for(int j =0;j<col1;j++)
            scanf("%d",&a[i][j]);

    int row2, col2;
    printf("Enter the number of rows and columns of the sparse matrix 2 : ");
    scanf("%d%d",&row2,&col2);
    int b[row2][col2];
    printf("Enter the elements of the matrix 2 : \n");
    for(int i =0;i<row2;i++)
        for(int j =0;j<col2;j++)
            scanf("%d",&b[i][j]);

    struct head_node* start_head1 = NULL;
    struct data_node* start_data1 = NULL;

    struct head_node* start_head2 = NULL;
    struct data_node* start_data2 = NULL;

    struct head_node* start_head3 = NULL;
    struct data_node* start_data3 = NULL;

    initialize(&start_head1,&start_data1,row1,col1);
    initialize(&start_head2,&start_data2,row2,col2);
    initialize(&start_head3,&start_data3,row2,col2);


    for(int i =0;i<row1;i++)
    {
        for(int j =0;j<col1;j++)
        {
            if(a[i][j] != 0)
            {
                create_list(&start_head1,&start_data1,a[i][j],i,j);
            }
        }
    }

    printf("Sparse Matirx 1 in 3-tuple format : \n");
    print_list(&start_head1,&start_data1);
    printf("\n");


    for(int i =0;i<row2;i++)
    {
        for(int j =0;j<col2;j++)
        {
            if(b[i][j] != 0)
            {
                create_list(&start_head2,&start_data2,b[i][j],i,j);
            }
        }
    }

    printf("Sparse Matirx 2 in 3-tuple format : \n");
    print_list(&start_head2,&start_data2);
    printf("\n");


    add(&start_head1,&start_data1,&start_head2,&start_data2,&start_head3,&start_data3);

    printf("Added Matirx in 3-tuple format : \n");
    print_list(&start_head3,&start_data3);
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

void add(struct head_node** start_head1,struct data_node** start_data1,struct head_node** start_head2,struct data_node** start_data2,struct head_node** start_head3,struct data_node** start_data3)
{
    if(((*start_head1)->col != (*start_head2)->col) || ((*start_head1)->row != (*start_head2)->row))
    {
        printf("Addition not possible\n");
        return;
    }

    struct data_node* t1 = *start_data1;
    struct data_node* t2 = *start_data2;
   
    while((t1 != NULL) && (t2 != NULL))
    {
        if(t1->rowcor == t2->rowcor)
        {
            if(t1->colcor == t2->colcor)
            {
                create_list(start_head3,start_data3,t1->value+t2->value,t1->rowcor,t1->colcor);
                t1 = t1->next;
                t2= t2->next;
            }
            else
            {
                if(t1->colcor < t2->colcor)
                {
                    create_list(start_head3,start_data3,t1->value,t1->rowcor,t1->colcor);
                    t1 = t1->next;
                }

                else
                {
                    create_list(start_head3,start_data3,t2->value,t2->rowcor,t2->colcor);
                    t2 = t2->next;
                }
            }
        }

        else
        {
            if(t1->rowcor< t2->rowcor)
            {
                create_list(start_head3,start_data3,t1->value,t1->rowcor,t1->colcor);
                t1 = t1->next;
            }
            else
            {
                create_list(start_head3,start_data3,t2->value,t2->rowcor,t2->colcor);
                t2 = t2->next;
            }
        }
    }

    while(t1 != NULL)
    {
        create_list(start_head3,start_data3,t1->value,t1->rowcor,t1->colcor);
        t1 = t1->next;
    }

    while(t2 != NULL)
    {
        create_list(start_head3,start_data3,t2->value,t2->rowcor,t2->colcor);
        t2 = t2->next;
    }
}