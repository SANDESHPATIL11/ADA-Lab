#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int m, int p) {
    int v = a[m];
    int i = m;
    int j = p;

    while (i < j) {
        while (a[i] <= v && i <= p - 1)
            i++;
        while (a[j] > v && j >= m + 1)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[m], &a[j]);
    return j;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int s = partition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}

int main() {
    int a[100], n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

// ==============================
// 5. HEAP SORT
// ==============================
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
