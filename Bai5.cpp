#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX], recursionStack[MAX];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

int hasCycleDFS(int vertex) {
    visited[vertex] = 1;
    recursionStack[vertex] = 1;

    Node* temp = adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex] && hasCycleDFS(adjVertex)) {
            return 1;
        } else if (recursionStack[adjVertex]) {
            return 1;
        }
        temp = temp->next;
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
        if (!visited[i] && hasCycleDFS(i)) {
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

    for (int i = 0; i < v; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    if (hasCycle(v)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}

