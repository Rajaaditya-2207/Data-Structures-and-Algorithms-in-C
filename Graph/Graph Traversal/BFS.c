#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n; // number of vertices

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

void BFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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
        graph[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(start);
    printf("\n");

    return 0;
}
