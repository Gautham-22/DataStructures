#include<stdio.h>
#include<stdlib.h>
#define V 5

void hamCycle(int [V][V]);
int hamUtils(int [V][V], int [V], int);
int isSafe(int [V][V], int [V], int, int);
void printResult(int [V]);

int count = 0;
int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
    };
    hamCycle(graph);
    // this has no hamiltonian cycles
    // {{0, 1, 0, 1, 0},
    // {1, 0, 1, 1, 1},
    // {0, 1, 0, 0, 1},
    // {1, 1, 0, 0, 0},
    // {0, 1, 1, 0, 0}}
    return 0;
}

void hamCycle(int graph[V][V]) {
    int *path = (int *)malloc(V * sizeof(int));
    for(int i=0; i<V; i++) {
        path[i] = -1;
    }

    path[0] = 0;
    hamUtils(graph, path, 1);
    if(!count) {
        printf("No hamiltonian cycle possible with starting vertex as 0!");
    }
}

int hamUtils(int graph[V][V], int path[V], int pos) {
    if(pos == V) {
        if(graph[path[V-1]][path[0]]) {
            count++;
            printResult(path);
            return 1;
        }
        return 0;
    }

    for(int i=1; i<V; i++) {
        if(isSafe(graph, path, pos, i)) {
            path[pos] = i;
            if(!hamUtils(graph, path, pos+1)) {
                path[pos] = -1;
            }
        }
    }
    return 0;
}

int isSafe(int graph[V][V], int path[V], int pos, int vertex) {
    if(graph[path[pos-1]][vertex] == 0) {
        return 0;
    }
    for(int i=0; i<pos; i++) {
        if(path[i] == vertex) return 0;
    }
    return 1;
}

void printResult(int path[V]) {
    printf("[ ");
    for(int i=0; i<V; i++) {
        printf("%d, ",path[i]);
    }
    printf("%d ",path[0]);
    printf("]\n");
}