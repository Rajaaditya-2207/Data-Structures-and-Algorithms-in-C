#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n; // number of vertices

void addEdge(int u, int v) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        graph[u][v] = 1;
        graph[v][u] = 1; // for undirected graph
    }
}

void removeEdge(int u, int v) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        graph[u][v] = 0;
        graph[v][u] = 0;
    }
}

void displayGraph() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int choice, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    while (1) {
        printf("\n--- Graph Operations ---\n");
        printf("1. Add Edge\n2. Remove Edge\n3. Display\n4. DFS\n5. BFS\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                addEdge(u, v);
                break;
            case 2:
                printf("Enter edge to remove (u v): ");
                scanf("%d %d", &u, &v);
                removeEdge(u, v);
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                for (int i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &start);
                printf("DFS traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 5:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &start);
                printf("BFS traversal: ");
                BFS(start);
                printf("\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
