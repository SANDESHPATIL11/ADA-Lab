#include <stdio.h>

int cost[10][10], parent[10];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, n, ne = 1;
    int min, mincost = 0;

    printf("\nKruskal's Algorithm\n");
    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (Enter 999 for no edge/self-loop):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nThe edges of Minimum cost spanning Tree are:\n");
    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("\nEdge %d: (%d, %d) cost: %d", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMinimum cost of spanning tree is %d\n", mincost);
    return 0;
}
