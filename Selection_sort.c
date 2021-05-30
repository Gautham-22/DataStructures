#include<stdio.h>

void display(int *,int);
void selection_sort(int *,int);

void main(){
    int n;
    printf("Enter total number of elements : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter a value : ");
        scanf("%d",&(a[i]));
    }
    display(a,n);
    selection_sort(a,n);
    printf("After sorting : \n");
    display(a,n);
}

void display(int *a,int n){
    printf("Array : [ ");
    for(int i=0;i<n;i++){
        printf("%d, ",*(a+i));
    }
    printf("]\n");
}

void selection_sort(int *a,int n){
    int j, k, min, count = 0;
    for(int i=0;i<n-1;i++){
        k = i;
        for(j=i+1;j<n;j++){
            if(*(a+j) < *(a+k)){
                k = j;
            }
        }
        min = *(a+k);
        *(a+k) = *(a+i);
        *(a+i) = min;
        if(k == i){
            count++;
        }
    }
    if(count == n-1){
        printf("Already sorted !\n");
    }
}