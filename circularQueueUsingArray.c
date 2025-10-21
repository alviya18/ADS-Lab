#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Function to insert (enqueue) element
void enqueue(int value) {
    if ((rear + 1) % SIZE == front)
        printf("Queue Full!\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Function to delete (dequeue) element
void dequeue() {
    if (front == -1)
        printf("Queue Empty!\n");
    else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

// Function to display queue
void display() {
    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
}

// Function to count total elements
int count() {
    if (front == -1)
        return 0;
    if (rear >= front)
        return rear - front + 1;
    else
        return SIZE - (front - rear - 1);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Count\n5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Current count: %d\n", count());
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
