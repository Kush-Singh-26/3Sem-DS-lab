#include<stdio.h>
#include<stdlib.h>

struct node
{
    int PID;
    int CPU_time;
    struct node* next;
};

struct node* create_node(int PID, int CPU_time);
void create_list(struct node** head, int PID, int CPU_time);
void round_robin(struct node** head, int quatum);

int main()
{
    struct node* head = NULL;
 
    int choice, pid, cputime, quantum;

    printf("1. Add a new process\n");
    printf("2. Start Round Robin Scheduling\n");
    printf("0. EXIT\n");

    do
    {
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter PID and CPU_TIME : ");
                scanf("%d%d",&pid,&cputime);
                create_list(&head,pid,cputime);
                break;
            
            case 2:
                printf("Enter time quantum T : ");
                scanf("%d",&quantum);
                round_robin(&head,quantum);
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice\n");
        }
    }while(choice != 0);

    return 0;
}

struct node* create_node(int PID, int CPU_time)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->CPU_time = CPU_time;
    ptr->PID = PID;
    ptr->next = NULL;
    return ptr;
}

void create_list(struct node** head, int PID, int CPU_time)
{
    struct node* new_process = create_node(PID,CPU_time);
    if(*head == NULL)
    {
        *head = new_process;
        new_process->next = new_process;
    }
        
    else
    {
        struct node* temp = *head;
        while(temp->next != *head)
            temp = temp->next;
        temp->next = new_process;
        new_process->next = *head;
    }
}

void round_robin(struct node** head, int quantum)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;

    while(*head != NULL)
    {
        printf("Process %d executed for %d units of time\n",temp->PID,(temp->CPU_time > quantum) ? quantum : temp->CPU_time);
        temp->CPU_time -= quantum;

        if(temp->CPU_time <= 0)
        {
            if(temp->next == temp)
            {
                free(temp);
                *head = NULL;
                temp = NULL;
            }

            else
            {
                struct node* prev = *head;
                while(prev->next != temp)
                    prev = prev->next;
                prev->next = temp->next;

                if(*head == temp)
                    *head = temp->next;
                struct node* temp1 = temp;
                temp = temp->next;
                free(temp1);
            }
        }

        else
        {
            *head = temp->next;
            temp = temp->next;
        }
    }

    printf("\nALL proceses are completed \n");
}