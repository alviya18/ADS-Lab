#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL, *tail = NULL;

// Insert at end
void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail) tail->next = newNode;
    else head = newNode;
    tail = newNode;
}

// Insert at start
void insertStart(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    else tail = newNode;
    head = newNode;
}

// Delete from end
void deleteEnd() {
    if (!tail) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = tail;
    printf("Deleted from end: %d\n", temp->data);
    tail = tail->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    free(temp);
}

// Delete from start
void deleteStart() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Deleted from start: %d\n", temp->data);
    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;
    free(temp);
}

// Display forward
void displayForward() {
    struct Node *temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

// Display backward
void displayBackward() {
    struct Node *temp = tail;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Backward: ");
    while (temp) {
        printf("%d-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
}

int count(){
    struct Node *temp = head;
    int count=0;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;   
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Insert at Start\n2.Insert at End\n3.Delete from Start\n4.Delete from End\n");
        printf("5.Forward Traversal\n6.Backward Traversal\n7.Count\n8.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertStart(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                deleteStart();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                count();
                printf("No: of elements of list is : ",count);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
