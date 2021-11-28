#include<stdio.h>

void display(int *,int);
void insertion_sort(int *,int);

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
    insertion_sort(a,n);
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

void insertion_sort(int *a,int n){
    int j, new;
    for(int i=1;i<n;i++){
        new = *(a+i);
        j = i - 1;
        while(j>=0 && (*(a+j))>new){
            *(a+j+1) = *(a+j);
            j--;
        }
        *(a+j+1) = new;
    }
}