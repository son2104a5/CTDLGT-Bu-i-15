#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX];

void dfs(int vertex, int v) {
    visited[vertex] = 1;
    for (int i = 0; i < v; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, v);
        }
    }
}

int main() {
    int v, e;

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

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    dfs(0, v);

    int isConnected = 1;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            isConnected = 0;
            break;
        }
    }

    if (isConnected) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}

