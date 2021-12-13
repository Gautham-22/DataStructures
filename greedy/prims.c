#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 999
#define V 4

int minkey(int key[], bool mstset[]) {
    int min = INT_MAX, min_index;

    for(int v=0; v < V; v++) {
        if(mstset[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for(int i=1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void prims(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstset[V];

    for(int i=0; i<V; i++) {
        key[i]= INT_MAX;
        mstset[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++) {
        int u = minkey(key, mstset);
        mstset[u] = true;

        for(int v=0; v < V; v++) {
            if(graph[u][v] && mstset[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main() {
    printf("Number of vertices:");
    int v;
    scanf("%d", &v);

    int graph[v][v];
    for(int i=0; i<v; ++i) {
        for(int j=0; j<v; ++j) {
            if(i == j) {
                graph[i][j] = 0;	
            } else {
                graph[i][j] = MAX;
            }
        }
    }

    printf("Enter the number of edges:");
    int e;
    scanf("%d", &e);
    for(int i=0; i<e; ++i) {
        int v1, v2, cost;
        printf("Enter the vertices v1, v2 and their cost:");
        scanf("%d %d %d", &v1, &v2, &cost);
        graph[v1][v2] = cost;
        graph[v2][v1] = cost;
    }

    prims(graph);
    return 0;
}