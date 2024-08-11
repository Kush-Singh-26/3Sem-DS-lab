//Create a menu driven program to input an array of 10 integers and then input or delete or search an element or reverse the array.
#include <stdio.h>

void insert(int a[],int n, int j, int k);
void delete(int a[],int n, int j);
int search(int a[],int n, int k);
void reverse(int a[],int n);
void print(int a[], int n);

int main()
{
	
	int a[11];
	int n =10;
    printf("Enter 10 elements : \n");
	for(int i = 0;i<10;i++)
		scanf("%d",&a[i]);
	
    
        printf("Enter your choice : \n");
        printf("1 - Insert an integer at any position\n");
        printf("2 - Delete an integer at any position\n");
        printf("3 - Search a particular element\n");
        printf("4 - Reverse the array\n");

        int choice;
        scanf("%d", &choice);
			int j,k;
        switch (choice)
        {
        case 1:
            printf("Enter the position and element to be inserted : ");
            
            scanf("%d %d", &j, &k);
            insert(a,n,j,k);
            print(a,n+1);
            break;

        case 2:
            printf("Enter the position to be deleted : ");

            scanf("%d", &j);
            delete(a,n,j);
            print(a,n-1);
            break;

        case 3:
            printf("Enter the element to be searched : ");

            scanf("%d", &k);
            int x = search(a,n,k);
            if(x == -1) printf("Not found");
            else printf("Found at position  : %d\n",x+1);
            printf("\n");
            break;


        case 4:
            
            reverse(a,n);
            print(a,n);
            break;

        default:
            printf("Wrong input\n");
            break;
        }

        
    

    return 0;
}


void insert(int a[],int n, int j, int k){
	for(int i =n-1;i>=j-1;i--)
	{
		a[i+1] = a[i];
	}
	a[j-1] = k; 
}
void delete(int a[],int n, int j)
{
	for(int i = j-1;i<n-1;i++)
		a[i] = a[i+1];
}

int search(int a[],int n, int k)
{
	for(int i =0;i<n;i++)
        if(a[i] == k) return i;
	return -1;
}

void reverse(int a[],int n)
{
	for(int i =0;i<n/2;i++){
		int temp = a[i];
		a[i] = a[n-1-i];
		a[n-i-1] = temp;
		}
}
void print(int a[], int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
    printf("\n");
}
