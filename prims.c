#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int selected[MAX] = {0};
    int mincost = 0;
    int edges = 0;
    char input[10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 'X' for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%s", input);
            if (strcmp(input, "X") == 0 || strcmp(input, "x") == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = atoi(input);

            // No self-loop
            if (i == j) cost[i][j] = INF;
        }
    }

    // Start from the first vertex
    selected[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF;
        int x = -1, y = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            printf("(%d, %d) -> Cost: %d\n", x + 1, y + 1, cost[x][y]);
            mincost += cost[x][y];
            selected[y] = 1;
            edges++;
        }
    }

    printf("Total cost of Minimum Spanning Tree: %d\n", mincost);

    return 0;
}
