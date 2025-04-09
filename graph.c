#include <stdio.h>
#define MAX_NODES 50

int n, m;
int g[MAX_NODES][MAX_NODES]; // Adjacency matrix
int x[MAX_NODES];            // Color assignment for each node
int count = 0;

// Check if it's safe to assign 'color' to node 'k'
int issafe(int k, int color) {
    for (int i = 1; i <= n; i++) {
        if (g[k][i] == 1 && x[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Recursive function for graph coloring
void graphcoloring(int k) {
    if (k > n) { // All vertices are colored
        for (int i = 1; i <= n; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
        count++;
        return;
    }

    for (int color = 1; color <= m; color++) {
        if (issafe(k, color)) {
            x[k] = color;
            graphcoloring(k + 1);
            x[k] = 0; // Backtrack
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    // Initialize color array
    for (int i = 1; i <= n; i++)
        x[i] = 0;

    printf("Possible solutions:\n");
    graphcoloring(1);

    printf("Total solutions found: %d\n", count);

    return 0;
}
