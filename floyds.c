#include <stdio.h>
#define MAX 100
#define INF 9999

void floyd(int n, int W[MAX][MAX]) {
    int D[MAX][MAX];
    int i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            D[i][j] = W[i][j];

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }

    printf("\nThe shortest distance matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", D[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, W[MAX][MAX];
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter weight matrix (use 9999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &W[i][j]);

    floyd(n, W);
    return 0;
