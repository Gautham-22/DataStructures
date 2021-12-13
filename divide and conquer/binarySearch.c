#include<stdio.h>

int binarySearch(int *a, int l, int h, int x) {
    if(l <= h) {
        int mid = l + (h - l)/2;
        if(a[mid] == x) {
            return mid;
        } else if(x < a[mid]) {
            return binarySearch(a,l,mid-1,x);
        } else {
            return binarySearch(a,mid+1,h,x);
        }
    }
    return -1;
}

void main() {
    int n, k, res;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d",&k);
    res = binarySearch(a,0,n-1,k);
    if(res == -1) {
        printf("Not found!\n");
    } else {
        printf("%d is at index position %d\n",k,res);
    }
}