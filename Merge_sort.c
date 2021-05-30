#include<stdio.h>

void merge(int *a,int l,int mid,int h){
    if(l == h){
        return;
    }
    int b[h-l+1];
    int i = l, j = mid+1, k=0;
    while(i<=mid && j<=h){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }else {
            b[k++] = a[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++] = a[i];
    }
    for(;j<=h;j++){
        b[k++] = a[j];
    }
    k = 0;
    for(int ind=l;ind<=h;ind++){
        a[ind] = b[k++];
    }
}

void MergeSort(int *a,int l,int h){
    if(l < h){
        int mid = (l + h)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);

        merge(a,l,mid,h);
    }
}


void display(int *a,int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        printf("%d, ",a[i]);
    }
    printf("]\n");
}

void main() {
    int a[9] = {5,6,7,8,9,1,2,3,4};
    int l = 0, n = 9, h = n-1;
    display(a,n);
    MergeSort(a,l,h);
    display(a,n);
}