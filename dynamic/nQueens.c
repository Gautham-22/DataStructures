#include<stdio.h>
#define N 8

void print(int [N][N]);
int findPositions(int [N][N], int);
int validPosition(int [N][N],int , int);

int main() {
    int chessBoard[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            chessBoard[i][j] = 0;
        }
    }
    if(findPositions(chessBoard,0)) {
        print(chessBoard);
    } else {
        printf("Cannot find solution for %d queen problem\n",N);
    }
    return 0;
}

void print(int a[N][N]) {
    printf("Solution of %d queen problem: \n",N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int validPosition(int a[N][N],int row, int col) {
    for(int i=0; i<col; i++) {
        if(a[row][i]) return 0;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--,j--) {
        if(a[i][j]) return 0;
    }
    for(int i=row, j=col; i<N && j>=0; i++,j--) {
        if(a[i][j]) return 0;
    }
    return 1;
}

int findPositions(int a[N][N], int col) {
    if(col >= N) return 1;
    for(int row=0; row<N; row++) {
        if(validPosition(a,row,col)) {
            a[row][col] = 1;
            if(findPositions(a,col+1)) {
                return 1;
            }
            a[row][col] = 0;
        }

    }
    return 0;
}