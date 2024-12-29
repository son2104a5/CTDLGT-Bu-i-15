#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], recursionStack[MAX];

int hasCycleDFS(int vertex, int v) {
    visited[vertex] = 1;
    recursionStack[vertex] = 1;

    for (int i = 0; i < v; i++) {
        if (graph[vertex][i]) {
            if (!visited[i] && hasCycleDFS(i, v)) {
                return 1;
            }
            if (recursionStack[i]) {
                return 1;
            }
        }
    }

    recursionStack[vertex] = 0;
    return 0;
}

int hasCycle(int v) {
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        recursionStack[i] = 0;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i] && hasCycleDFS(i, v)) {
            return 1;
        }
    }
    return 0;
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
    }

    if (hasCycle(v)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}

