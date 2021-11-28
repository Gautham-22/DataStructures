#include<stdio.h>

void display(int *,int);
void insertion_sort(int *,int);
void shell_sort(int *,int);

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
    shell_sort(a,n);
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

void shell_sort(int *a,int n){
    int j, temp;
    for(int gap=n/2; gap >= 1; gap /= 2){
        for(int i=gap;i<n;i++){
            temp = a[i];
            j = i - gap;
            while(j>=0 && a[j]>temp){
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = temp;
        }
    }
}