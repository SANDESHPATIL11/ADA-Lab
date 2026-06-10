/ ==============================
// 1. TOPOLOGICAL SORT
// ==============================
#include <stdio.h>
#define MAX 100

int main() {
    int n, graph[MAX][MAX];
    int indegree[MAX], queue[MAX], topo[MAX];
    int front = 0, rear = -1, count = 0;
    int i, j, vertex;

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        indegree[i] = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (graph[i][j] == 1)
                indegree[j]++;

    for (i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;

    while (front <= rear) {
        vertex = queue[front++];
        topo[count++] = vertex;

        for (i = 0; i < n; i++) {
            if (graph[vertex][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (count == n) {
        printf("Topological ordering:\n");
        for (i = 0; i < count; i++)
            printf("%d ", topo[i]);
        printf("\n");
    } else {
        printf("Graph has cycle, topological order not possible.\n");
    }

    return 0;
}

// ==============================
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

// ==============================
// 3. MERGE SORT
// ==============================
#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int b[50];
    int i = low, j = mid + 1, k = low;
    int l;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        b[k++] = a[i];
        i++;
    }
    while (j <= high) {
        b[k++] = a[j];
        j++;
    }
    for (l = low; l <= high; l++) {
        a[l] = b[l];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int a[50];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

// ==============================
// 4. QUICK SORT
// ==============================
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

// ==============================
// 6. 0/1 KNAPSACK (DYNAMIC PROGRAMMING)
// ==============================
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

// ==============================
// 7. FLOYD'S ALGORITHM (ALL PAIRS SHORTEST PATH)
// ==============================
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
}

// ==============================
// 8. PRIM'S ALGORITHM (MST)
// ==============================
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

// ==============================
// 9. KRUSKAL'S ALGORITHM (MST)
// ==============================
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

// ==============================
// 10. FRACTIONAL KNAPSACK (GREEDY)
// ==============================
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

// ==============================
// 11. DIJKSTRA'S ALGORITHM
// ==============================
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

// ==============================
// 12. N-QUEENS PROBLEM (BACKTRACKING)
// ==============================
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

// ==============================
// 15. BRUTE FORCE STRING MATCHING
// ==============================
#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[100];
    int n, m, i, j;

    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            return 0;
        }
    }

    printf("Pattern not found\n");
    return 0;
}

// ==============================
// 17. ASSIGNMENT PROBLEM
// ==============================
#include <stdio.h>
#define INF 9999

int n, cost[10][10], min_cost = INF;
int assigned[10];

void assign(int person, int current_cost) {
    if (person == n) {
        if (current_cost < min_cost)
            min_cost = current_cost;
        return;
    }
    for (int job = 0; job < n; job++) {
        if (!assigned[job]) {
            assigned[job] = 1;
            assign(person + 1, current_cost + cost[person][job]);
            assigned[job] = 0;
        }
    }
}

int main() {
    printf("Enter number of persons/jobs: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
        assigned[i] = 0;
    }

    assign(0, 0);

    printf("Minimum assignment cost is: %d\n", min_cost);
    return 0;
}

// ==============================
// 17. ASSIGNMENT PROBLEM
// ==============================
#include <stdio.h>
#define INF 9999

int n, cost[10][10], min_cost = INF;
int assigned[10];

void assign(int person, int current_cost) {
    if (person == n) {
        if (current_cost < min_cost)
            min_cost = current_cost;
        return;
    }
    for (int job = 0; job < n; job++) {
        if (!assigned[job]) {
            assigned[job] = 1;
            assign(person + 1, current_cost + cost[person][job]);
            assigned[job] = 0;
        }
    }
}

int main() {
    printf("Enter number of persons/jobs: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
        assigned[i] = 0;
    }

    assign(0, 0);

    printf("Minimum assignment cost is: %d\n", min_cost);
    return 0;
}

// ==============================
// 18. KNAPSACK EXHAUSTIVE SEARCH
// ==============================
#include <stdio.h>

int n, capacity, max_profit = 0;
int w[20], p[20];

void knapsackExhaustive(int i, int current_weight, int current_profit) {
    if (current_weight > capacity) return;
    if (i == n) {
        if (current_profit > max_profit) max_profit = current_profit;
        return;
    }
    knapsackExhaustive(i + 1, current_weight + w[i], current_profit + p[i]);
    knapsackExhaustive(i + 1, current_weight, current_profit);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    printf("Enter profits: ");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    printf("Enter capacity: ");
    scanf("%d", &capacity);

    knapsackExhaustive(0, 0, 0);

    printf("Maximum profit: %d\n", max_profit);
    return 0;
}

// ==============================
// 19. WARSHALL ALGORITHM (TRANSITIVE CLOSURE)
// ==============================
#include <stdio.h>

int main() {
    int n, a[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }

    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// ==============================
// 20. COIN ROW PROBLEM
// ==============================
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int c[n + 1], F[n + 1];
    c[0] = 0;
    F[0] = 0;

    printf("Enter values of coins: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    F[1] = c[1];
    for (int i = 2; i <= n; i++) {
        F[i] = max(c[i] + F[i - 2], F[i - 1]);
    }

    printf("Maximum value is: %d\n", F[n]);
    return 0;
}

// ==============================
// 21. COIN CHANGE / CHANGE MAKING
// ==============================
#include <stdio.h>
#define INF 9999

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int d[n];
    printf("Enter denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    int F[amount + 1];
    F[0] = 0;

    for (int i = 1; i <= amount; i++) {
        F[i] = INF;
        for (int j = 0; j < n; j++) {
            if (i >= d[j]) {
                F[i] = min(F[i], F[i - d[j]] + 1);
            }
        }
    }

    if (F[amount] == INF)
        printf("Change not possible\n");
    else
        printf("Minimum coins needed: %d\n", F[amount]);

    return 0;
}

// ==============================
// 22. COIN COLLECTION PROBLEM
// ==============================
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, m;
    printf("Enter dimensions (n m): ");
    scanf("%d %d", &n, &m);

    int c[n + 1][m + 1], F[n + 1][m + 1];
    printf("Enter grid values:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &c[i][j]);
            F[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; i++) F[i][0] = 0;
    for (int j = 0; j <= m; j++) F[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + c[i][j];
        }
    }

    printf("Maximum coins collected: %d\n", F[n][m]);
    return 0;
}

// ==============================
// 23. RUSSIAN PEASANT MULTIPLICATION
// ==============================
#include <stdio.h>

int main() {
    int n, m, res = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);

    while (n > 0) {
        if (n % 2 != 0) {
            res += m;
        }
        n = n / 2;
        m = m * 2;
    }

    printf("Product is: %d\n", res);
    return 0;
}

// ==============================
// 24. MEDIAN SELECTION
// ==============================
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int quickselect(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return quickselect(arr, l, index - 1, k);
        return quickselect(arr, index + 1, r, k - index + l - 1);
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = (n / 2) + 1;
    int median = quickselect(arr, 0, n - 1, k);

    printf("Median is: %d\n", median);
    return 0;
}
