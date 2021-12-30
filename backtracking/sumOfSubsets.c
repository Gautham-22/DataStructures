#include<stdio.h>
#include<stdlib.h>

int sumOfSubsets(int *, int, int, int, int);
void printSolution();

int *subset, n;
int main() {
    /* input array should contain unique & non-negative values */
    int targetSum, sum = 0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    subset = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) {
        subset[i] = 0;
        scanf("%d",&a[i]);
        sum += a[i];
    }
    printf("Enter the value of sum: ");
    scanf("%d",&targetSum);
    if(sumOfSubsets(a, 0, 0, sum, targetSum)) {
        printf("Target sum can be generated from the subset: [");
        for(int i=0; i<n; i++) {
            if(subset[i]) {
                printf("%d, ",a[i]);
            }
        }
        printf("]\n");
    } else {
        printf("Target sum cannot be found from the subsets of given array\n");
    }
    return 0;
}

int sumOfSubsets(int *a, int start, int currentSum, int sum, int targetSum) {
    if(sum <= 0 || currentSum > targetSum) return 0;
    if(currentSum == targetSum) {
        return 1;
    }
    for(int i=start; i<n; i++) {
        subset[i] = 1;
        currentSum += a[i];
        if(!sumOfSubsets(a,i+1,currentSum,sum - a[i],targetSum)) {
            subset[i] = 0;
            currentSum -= a[i];
        } else {
            return 1;
        }
    }
    return 0;
}