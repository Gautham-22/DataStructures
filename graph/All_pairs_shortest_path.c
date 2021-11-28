/* Floyd Warshall Algorithm */ 

#include<stdio.h>
#define MAX 100000
#define N 4

int min(int a, int b) {
    if(a < b) {
        return a;
    }
    return b;
}

void find_shortest_paths(int a[][N]) {
    
    for(int k=0; k<N; k++) { 
        // matrix value changes to minimum of previous value and path going through kth vertex
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

}

void main() {
    // a matrix representing weight of edge between the vertices (cost/length of edge)
    // MAX - indicates no path
    int graph[N][N] = {
        {0,3,MAX,7},
        {8,0,2,MAX},
        {5,MAX,0,1},
        {2,MAX,MAX,0},
    };
    
    find_shortest_paths(graph);

    // shortest path between any pair of vertices
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(graph[i][j] == MAX) {
                printf("NA ");
            } else {
                printf("%d ",graph[i][j]);
            }
        }
        printf("\n");
    }
}