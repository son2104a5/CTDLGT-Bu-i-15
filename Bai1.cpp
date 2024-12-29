#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX];
int front = 0, rear = -1;

void bfs(int start, int v) {
    printf("Thu tu duyet BFS: ");
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < v; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int v, e, start;
    printf("So dinh: ");
    scanf("%d", &v);
    printf("So canh: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Dinh bat dau: ");
    scanf("%d", &start);

    bfs(start, v);

    return 0;
}

