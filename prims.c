#include <stdio.h>
#define MAX 20
#define INF 999

void prims(int cost[MAX][MAX], int n) {
    int visited[MAX];
    int i, j, min, u, v;
    int mincost = 0, edge_count = 0;

    for (i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;

    printf("\nEdges in MST:\n");
    while (edge_count < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] != INF) {
                        if (min > cost[i][j]) {
                            min = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        printf("%d -> %d = %d\n", u, v, min);
        mincost += min;
        visited[v] = 1;
        edge_count++;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    int n, i, j;
    int cost[MAX][MAX];

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    prims(cost, n);
    return 0;
}
