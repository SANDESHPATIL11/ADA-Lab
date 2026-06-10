// 2. JOHNSON-TROTTER ALGORITHM
// ==============================
#include <stdio.h>
#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", perm[i]);
    printf("\n");
}

int getLargestMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[perm[i] - 1] == LEFT && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile)
                mobile = perm[i];
        }
        if (dir[perm[i] - 1] == RIGHT && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile)
                mobile = perm[i];
        }
    }
    return mobile;
}

void JohnsonTrotter(int n) {
    int perm[n];
    int dir[n];
    int i, pos, temp;

    for (i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printf("Permutations using Johnson-Trotter Algorithm:\n");
    printPermutation(perm, n);

    while (1) {
        int mobile = getLargestMobile(perm, dir, n);
        if (mobile == 0)
            break;

        for (i = 0; i < n; i++) {
            if (perm[i] == mobile) {
                pos = i;
                break;
            }
        }

        if (dir[mobile - 1] == LEFT) {
            temp = perm[pos];
            perm[pos] = perm[pos - 1];
            perm[pos - 1] = temp;
            pos = pos - 1;
        } else {
            temp = perm[pos];
            perm[pos] = perm[pos + 1];
            perm[pos + 1] = temp;
            pos = pos + 1;
        }

        for (i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[perm[i] - 1] = -dir[perm[i] - 1];
        }
        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    JohnsonTrotter(n);
    return 0;
}
