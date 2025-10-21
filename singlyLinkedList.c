#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// Insert at beginning
void insertAtStart(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at any position
void insertAtPosition(int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtStart(value);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range, inserting at end.\n");
        insertAtEnd(value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from start
void deleteFromStart() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted first node.\n");
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node, list is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Deleted last node.\n");
}

// Delete from any position
void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteFromStart();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Deleted node at position %d.\n", pos);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count elements
int count() {
    int cnt = 0;
    struct Node *temp = head;
    while (temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n1. Insert at Start\n2. Insert at End\n3. Insert at any Position\n");
        printf("4. Delete from Start\n5. Delete from End\n6. Delete from any Position\n");
        printf("7. Display\n8. Count\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtStart(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteFromStart();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Number of elements: %d\n", count());
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
