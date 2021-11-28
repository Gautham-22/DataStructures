#include<stdio.h>
#define N 9

void Count_Sort(int *a,int n){
    int max = a[0];
    for(int i=0;i<n;i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    int count[max+1];
    for(int i=0;i<max+1;i++){
        count[i] = 0;
    }
    for(int i=0;i<n;i++){
        count[a[i]] += 1;
    }
    int i=0, k = 0;
    while(i < max+1){
        if(count[i] > 0){
            a[k++] = i;
            count[i]--;
        }else {
            i++;
        }
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
    int a[N] = {1,2,3,4,5,6,7,8,8};
    display(a,N);
    Count_Sort(a,N);
    display(a,N);
}