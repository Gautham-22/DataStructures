/* 0|1 knapsack problem */

#include<stdio.h>

int knapsack(int *, int *, int, int);
int max(int, int);

int main() {
    int capacity, n;
    printf("Enter the number of weights: ");
    scanf("%d",&n);
    int weights[n], values[n];
    printf("Enter %d weights with corresponding profits: \n",n);
    for(int i=0; i<n; i++) {
        scanf("%d %d",&weights[i],&values[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d",&capacity);
    printf("Max value|profit possible: %d\n",knapsack(weights,values,n,capacity));
    return 0;
}

// recursive way
int knapsack(int *wts, int *values, int n, int capacity) {
    if(n == 0 || capacity == 0) return 0;

    if(wts[n-1] > capacity) {
        return knapsack(wts,values,n-1,capacity);
    }

    return max(values[n-1] + knapsack(wts,values,n-1,capacity-wts[n-1]),knapsack(wts,values,n-1,capacity));

}

int max(int a, int b) {
    if(a < b) return b;
    return a;
}