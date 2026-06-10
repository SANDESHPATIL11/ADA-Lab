#include <stdio.h>

int main() {
    int i, j, n;
    float capacity, temp;
    float w[50], p[50], r[50];
    float TotProfit = 0;

    printf("Enter no. of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &w[i]);

    printf("Enter profits of items:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
        r[i] = p[i] / w[i];

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (r[i] < r[j]) {
                temp = r[i]; r[i] = r[j]; r[j] = temp;
                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (w[i] > capacity)
            break;
        else {
            TotProfit = TotProfit + p[i];
            capacity = capacity - w[i];
        }
    }

    if (i < n)
        TotProfit = TotProfit + (r[i] * capacity);

    printf("Maximum profit = %.2f\n", TotProfit);
    return 0;
}
