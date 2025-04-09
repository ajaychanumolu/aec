#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_idx = -1;
    for (int i = 0; i < V; i++)
        if (!mstSet[i] && key[i] < min)
            min = key[i], min_idx = i;
    return min_idx;
}

void primMST(int g[V][V]) {
    int parent[V], key[V];
    bool mstSet[V] = { false };
    
    for (int i = 0; i < V; i++) key[i] = INT_MAX;
    key[0] = 0, parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (g[u][v] && !mstSet[v] && g[u][v] < key[v])
                parent[v] = u, key[v] = g[u][v];
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, g[parent[i]][i]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
    return 0;
}