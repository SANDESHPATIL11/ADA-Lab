#include <stdio.h>
#include <stdlib.h>

int x[10], n;

int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void queen(int k) {
    int i, j;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (j = 1; j <= n; j++)
                    printf("%d\t", x[j]);
                printf("\n");
            } else {
                queen(k + 1);
            }
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);
    queen(1);
    return 0;
}

// ==============================
// 13. EUCLID GCD
// ==============================
#include <stdio.h>

int main() {
    int m, n, r;
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("GCD is: %d\n", m);
    return 0;
}

// ==============================
// 14. CONSECUTIVE INTEGER GCD
// ==============================
#include <stdio.h>

int main() {
    int m, n, min, gcd = 1;
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);

    min = (m < n) ? m : n;

    for (int i = min; i >= 1; i--) {
        if (m % i == 0 && n % i == 0) {
            gcd = i;
            break;
        }
    }

    printf("GCD is: %d\n", gcd);
    return 0;
}
