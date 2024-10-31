#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITY 5   
#define MAX_SIZE 5       

char queue[MAX_PRIORITY][MAX_SIZE];

int front[MAX_PRIORITY];
int rear[MAX_PRIORITY];

void initialize();
int isEmpty(int priority);
int isFull(int priority);
void enqueue(char element, int priority);
char dequeue(int priority);
void display();

int main() {
    initialize();

    enqueue('A', 1);
    enqueue('B', 2);
    enqueue('C', 2);
    enqueue('D', 4);
    enqueue('E', 4);
    enqueue('F', 5);

    display();

    dequeue(2);
    dequeue(1);

    display();

    return 0;
}


void initialize() 
{
    for (int i = 0; i < MAX_PRIORITY; i++) {
        front[i] = -1;
        rear[i] = -1;
    }
}

int isEmpty(int priority) 
{
    return front[priority] == -1;
}

int isFull(int priority) 
{
    return (rear[priority] + 1) % MAX_SIZE == front[priority];
}

void enqueue(char element, int priority) 
{
    if (isFull(priority)) {
        printf("Queue overflow at priority %d\n", priority);
        return;
    }
    if (isEmpty(priority)) {
        front[priority] = 0;
    }
    rear[priority] = (rear[priority] + 1) % MAX_SIZE;
    queue[priority][rear[priority]] = element;
    printf("Enqueued %c at priority %d\n", element, priority);
}

char dequeue(int priority) 
{
    if (isEmpty(priority)) {
        printf("Queue underflow at priority %d\n", priority);
        return '\0';
    }
    char element = queue[priority][front[priority]];
    if (front[priority] == rear[priority]) {
        front[priority] = -1;
        rear[priority] = -1;
    } else {
        front[priority] = (front[priority] + 1) % MAX_SIZE;
    }
    printf("Dequeued %c from priority %d\n", element, priority);
    return element;
}

void display() 
{
    printf("\nPriority Queue State:\n");
    for (int i = 0; i < MAX_PRIORITY; i++) {
        printf("Priority %d: ", i + 1);
        if (isEmpty(i)) {
            printf("Empty\n");
            continue;
        }
        int j = front[i];
        do {
            printf("%c ", queue[i][j]);
            j = (j + 1) % MAX_SIZE;
        } while (j != (rear[i] + 1) % MAX_SIZE);
        printf("\n");
    }
}

