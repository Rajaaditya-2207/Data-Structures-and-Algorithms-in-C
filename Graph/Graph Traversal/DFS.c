#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n; // number of vertices

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // for undirected graph
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
