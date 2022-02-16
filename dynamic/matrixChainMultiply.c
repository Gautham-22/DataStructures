// Minimum no. of multiplications required for a matrix chain multiplication.

#include<stdio.h>

int minMultiply(int *dim, int size);

int main() {
    // Matrix A, B, C with dimensions 1x2, 2x3, 3x4 respectively
    int dim[] = { 5, 4, 6, 2, 7 };
    int size = sizeof(dim) / sizeof(dim[0]);

    int result = minMultiply(dim, size);
    printf("Minimum %d multiplications required.",result);

    return 0;
}

int minMultiply(int *dim, int n) {
    int tab[n][n], val;
    for(int i=1; i<n; i++) {
        tab[i][i] = 0;
    }

    // l - length of chain
    for(int l=2; l<n; l++) {
        for(int i=1; i<=n-l; i++) {
            int j = i + l - 1;
            tab[i][j] = __INT_MAX__;
            for(int k=i; k<j; k++) {
                val = tab[i][k] + tab[k+1][j] + dim[i-1]*dim[k]*dim[j];
                if(val < tab[i][j]) {
                    tab[i][j] = val;
                }
            }
        }
    }

    return tab[1][n-1];
}
