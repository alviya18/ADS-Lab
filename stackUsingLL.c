#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow.\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    struct Node *temp = top;
    int count = 0;
    if (!temp) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int count() {
    struct Node *temp = top;
    int count = 0;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                count();
                printf("No: of items in stack is : ",count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
