#include <stdio.h>
#define MAX 50

void heapify(int a[MAX], int n) {
    int i, j, k, v, flag;
    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = a[k];
        flag = 0;
        while (!flag && 2 * k <= n) {
            j = 2 * k;
            if (j < n) {
                if (a[j] < a[j + 1])
                    j = j + 1;
            }
            if (v >= a[j]) {
                flag = 1;
            } else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

void heapsort(int a[MAX], int n) {
    int i, temp;
    for (i = n; i > 1; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a, i - 1);
    }
}

int main() {
    int i, n, a[MAX];
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    heapify(a, n);
    heapsort(a, n);

    printf("Array after performing heap sort: ");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
