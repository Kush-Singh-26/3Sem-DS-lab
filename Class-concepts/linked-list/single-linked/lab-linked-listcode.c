#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL; 
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Add a node\n");
        printf("2. Display all nodes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}