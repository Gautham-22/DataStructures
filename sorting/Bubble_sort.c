#include<stdio.h>
#include<stdlib.h>

void display(int *,int);
void bubble_sort(int *,int);

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
    bubble_sort(a,n);
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

void bubble_sort(int *a,int n){
    int temp, flag = 0;
    for(int i=0;i<n-1;i++){
        flag = 0;
        for(int j=0;j<n-1-i;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}