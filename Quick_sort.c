#include<stdio.h>

void display(int *a,int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        printf("%d, ",a[i]);
    }
    printf("]\n");
}

int partition(int *a,int l,int h){
    int i=l, j=h, pivot = a[l], temp;
    while(i<j){
        while(a[i] <= pivot && i<=h){
            i++;
        }
        while(a[j] > pivot && j>=l){
            j--;
        }
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // pivot's sorted position is j
    temp = a[j];
    a[j] = pivot;
    a[l] = temp;
    return j;
}

void quick_sort(int *a,int l,int h){
    int j;

    if(l < h){
        j = partition(a,l,h);
        quick_sort(a,l,j);
        quick_sort(a,j+1,h);
    }
}

void main(){
    int a[5] = {5,4,3,2,1};
    printf("Before sorting : ");
    display(a,5);
    quick_sort(a,0,4);
    printf("After sorting : ");
    display(a,5);
}