#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int prn; // priority number
    struct node* next;
};

void insert(struct node** head, int prn, int key);
int pop(struct node** head, int* n);  
void display(struct node* head);

// highest priority implies lowest priority number
int main() {
    struct node* head = NULL;
    int choice, prn, key;

    do {
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter priority: ");
                scanf("%d", &prn);
                insert(&head, prn, key);
                break;

            case 2:
                display(head);
                break;

            case 3: {
                int b;
                if (pop(&head, &b)) {
                    printf("Deleted key with value: %d\n", b);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            }

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}

void insert(struct node** head, int prn, int key) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->key = key;
    ptr->prn = prn;
    ptr->next = NULL;

    if (*head == NULL || (*head)->prn > prn) {
        ptr->next = *head;
        *head = ptr;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL && temp->next->prn <= prn) {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("Key: %d, Priority: %d\n", temp->key, temp->prn);
        temp = temp->next;
    }
}

int pop(struct node** head, int* n) {
    if (*head == NULL) {
        return 0; 
    }
    *n = (*head)->key;
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return 1; 
}
