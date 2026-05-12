
#include <stdio.h>

int a[20][20], visited[20], q[20];
int n, f = 0, r = -1;

// BFS Function
void bfs(int start) {
    int i;

    // Enqueue starting node
    q[++r] = start;
    visited[start] = 1;

    while (f <= r) {
        int v = q[f++];

        printf("%d\t", v);

        for (i = 1; i <= n; i++) {
            if (a[v][i] == 1 && !visited[i]) {
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;
    int allVisited = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize visited array
    for (i = 1; i <= n; i++) { 
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nBFS Traversal:\n");
    bfs(start);

    // Reachable nodes
    printf("\n\nReachable Nodes:\n");

    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("%d\t", i);
        }
    }

    // Unreachable nodes
    printf("\n\nUnreachable Nodes:\n");

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("%d\t", i);
            allVisited = 0;
        }
    }

    // Check whether BFS is possible for all nodes
    if (allVisited) {
        printf("\n\nBFS is possible. Graph is connected.\n");
    } else {
        printf("\n\nBFS is NOT possible for all nodes. Graph is disconnected.\n");
    }

    return 0;
}
