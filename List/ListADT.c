#include <stdio.h>
#define MAX 100

int list[MAX];
int size = 0;

void insertEnd(int value) {
    if (size >= MAX)
        printf("List Overflow\n");
    else {
        list[size] = value;
        size++;
    }
}

void insertAt(int pos, int value) {
    if (size >= MAX)
        printf("List Overflow\n");
    else if (pos < 0 || pos > size)
        printf("Invalid Position\n");
    else {
        for (int i = size; i > pos; i--)
            list[i] = list[i - 1];
        list[pos] = value;
        size++;
    }
}

void deleteAt(int pos) {
    if (size == 0)
        printf("List Underflow\n");
    else if (pos < 0 || pos >= size)
        printf("Invalid Position\n");
    else {
        for (int i = pos; i < size - 1; i++)
            list[i] = list[i + 1];
        size--;
    }
}

int search(int value) {
    for (int i = 0; i < size; i++) {
        if (list[i] == value)
            return i;
    }
    return -1;
}

void display() {
    if (size == 0)
        printf("List is empty\n");
    else {
        printf("List elements: ");
        for (int i = 0; i < size; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- List ADT Operations ---\n");
        printf("1. Insert at End\n2. Insert at Position\n3. Delete at Position\n4. Search\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter position to insert (0-based): ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAt(pos, value);
                break;
            case 3:
                printf("Enter position to delete (0-based): ");
                scanf("%d", &pos);
                deleteAt(pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(value);
                if (pos != -1)
                    printf("Element found at position %d\n", pos);
                else
                    printf("Element not found\n");
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
