#include <stdio.h>
#define INF 9999

void dijkstra(int c[][20], int n, int s, int d[]) {
    int v[20];
    int i, j, u, min;

    for (i = 0; i < n; i++) {
        d[i] = c[s][i];
        v[i] = 0;
    }

    v[s] = 1;
    d[s] = 0;

    for (i = 0; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;

        for (j = 0; j < n; j++) {
            if (v[j] == 0 && (d[u] + c[u][j] < d[j])) {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}

int main() {
    int n, i, j, s;

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    int c[20][20], d[20];

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    dijkstra(c, n, s, d);

    printf("Shortest distance from vertex %d:\n", s);
    for (i = 0; i < n; i++)
        printf("To %d: %d\n", i, d[i]);

    return 0;
}
