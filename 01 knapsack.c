#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackDP(int n, int M, int w[], int P[]) {
    int i, j;
    int Table[n + 1][M + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                Table[i][j] = 0;
            else if (w[i - 1] <= j)
                Table[i][j] = max(P[i - 1] + Table[i - 1][j - w[i - 1]], Table[i - 1][j]);
            else
                Table[i][j] = Table[i - 1][j];
        }
    }

    int res = Table[n][M];
    printf("Maximum Profit = %d\n", res);

    int sol_vector[n];
    for (i = 0; i < n; i++)
        sol_vector[i] = 0;

    int cur_cap = M;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == Table[i - 1][cur_cap]) {
            sol_vector[i - 1] = 0;
        } else {
            sol_vector[i - 1] = 1;
            res -= P[i - 1];
            cur_cap -= w[i - 1];
        }
    }

    printf("Solution vector = ");
    for (i = 0; i < n; i++)
        printf("%d ", sol_vector[i]);
    printf("\n");
}

int main() {
    int n, M;
    printf("Enter no of items: ");
    scanf("%d", &n);
    int w[n], P[n];
    printf("Enter weights of items: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &P[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);

    knapsackDP(n, M, w, P);
    return 0;
}
