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
