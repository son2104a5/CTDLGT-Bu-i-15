#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX];

void dfs(int vertex, int v) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < v; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, v);
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
        int u, w;
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }

    printf("Dinh bat dau: ");
    scanf("%d", &start);

    printf("Thu tu duyet DFS: ");
    dfs(start, v);

    return 0;
}

