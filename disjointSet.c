#include <stdio.h>

#define MAX_SIZE 8

int parent[MAX_SIZE];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  
    return parent[x];
}

void unionSets(int x, int y) {
    int u = find(x);
    int v = find(y);
    if (u != v) {
        parent[v] = u;
    }
}

int main() {
    int n, unions, finds;
    int x, y;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    makeSet(n);
    printf("Enter number of union operations: ");
    scanf("%d", &unions);
    printf("Enter %d pairs for union:\n", unions);
    for (int i = 0; i < unions; i++) {
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < n && y >= 0 && y < n) {
            unionSets(x, y);
        } 
        else {
            printf("Invalid elements: %d %d\n", x, y);
        }
    }
    printf("Enter number of find operations: ");
    scanf("%d", &finds);
    printf("Enter %d elements to find their set representative:\n", finds);
    for (int i = 0; i < finds; i++) {
        scanf("%d", &x);
        if (x >= 0 && x < n) {
            printf("Representative of %d is %d\n", x, find(x));
        } else {
            printf("Invalid element: %d\n", x);
        }
    }
    return 0;
}

