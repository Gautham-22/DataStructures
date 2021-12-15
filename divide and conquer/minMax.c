#include<Stdio.h>

struct result {
    int min, max;
};

struct result minMax(int a[], int low, int high) {
    struct result res, leftResult, rightResult;
    int mid;
    if(low == high) {
        res.min = a[low];
        res.max = a[low];
        return res;
    }
    if(high == low + 1) {
        if(a[low] < a[high]) {
            res.min = a[low];
            res.max = a[high];
        } else {
            res.min = a[high];
            res.max = a[low];
        }
        return res;
    } 
    mid = (low + high) / 2;
    leftResult = minMax(a,low,mid);
    rightResult = minMax(a,mid+1,high);

    if(leftResult.min < rightResult.min) {
        res.min = leftResult.min;
    } else {
        res.min = rightResult.min;
    }
    if(leftResult.max > rightResult.max) {
        res.max = leftResult.max;
    } else {
        res.max = rightResult.max;
    }
    return res;
}

void main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of array: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    struct result res = minMax(a,0,n-1);
    printf("Min: %d, Max: %d\n",res.min,res.max);
}