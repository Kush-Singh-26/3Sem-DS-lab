#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 3 

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int count;   
} Queue;

void initializeQueue(Queue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == q->size;
}

int enqueue(Queue queues[], int person, int queueSize) {
    for (int i = 0; i < MAX_QUEUES; i++) {
        if (!isFull(&queues[i])) {
            queues[i].rear = (queues[i].rear + 1) % queueSize;
            queues[i].arr[queues[i].rear] = person;
            queues[i].count++;
            printf("Person %d added to Queue %d.\n", person, i + 1);
            return 1;
        }
    }
    printf("No space available to add more people.\n");
    return 0;
}

int dequeue(Queue queues[], int queueSize) {
    for (int i = 0; i < MAX_QUEUES; i++) {
        if (!isEmpty(&queues[i])) {
            int person = queues[i].arr[queues[i].front];
            queues[i].front = (queues[i].front + 1) % queueSize;
            queues[i].count--;
            printf("Person %d has been vaccinated and removed from Queue %d.\n", person, i + 1);
            return person;
        }
    }
    printf("No one is present to get the vaccine.\n");
    return -1;
}

void moveForward(Queue queues[], int queueSize) {
    for (int i = 0; i < MAX_QUEUES - 1; i++) {
        if (!isEmpty(&queues[i + 1]) && !isFull(&queues[i])) {
            queues[i].rear = (queues[i].rear + 1) % queueSize;
            queues[i].arr[queues[i].rear] = queues[i + 1].arr[queues[i + 1].front];
            queues[i].count++;
            queues[i + 1].front = (queues[i + 1].front + 1) % queueSize;
            queues[i + 1].count--;
            printf("Person moved from Queue %d to Queue %d.\n", i + 2, i + 1);
        }
    }
}

int main() {
    int queueSize, choice, person = 1;
    printf("Enter the size of each queue: ");
    scanf("%d", &queueSize);

    Queue queues[MAX_QUEUES];
    for (int i = 0; i < MAX_QUEUES; i++) {
        initializeQueue(&queues[i], queueSize);
    }

    while (1) {
        printf("\n1. Add Person to Queue\n");
        printf("2. Vaccinate and Remove Person\n");
        printf("3. Move All Forward\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(queues, person++, queueSize);
                break;
            case 2:
                dequeue(queues, queueSize);
                break;
            case 3:
                moveForward(queues, queueSize);
                break;
            case 4:
                printf("Exiting program.\n");
                for (int i = 0; i < MAX_QUEUES; i++) {
                    free(queues[i].arr);
                }
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}