#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL)
        rear = newNode;
    else
        front->prev = newNode;

    front = newNode;
}

void insertRear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;

    rear = newNode;
}

void deleteFront() {
    if (front == NULL) {
        printf("Dequeue is empty\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Dequeue is empty\n");
        return;
    }

    struct Node* temp = rear;
    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Dequeue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Dequeue Using Doubly Linked List ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
