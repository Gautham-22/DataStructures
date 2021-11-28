#include<stdio.h>
#include<stdlib.h>
#define N 5

struct Node {
    int value;
    struct Node *next;
};

void bin_sort(int *a,int n){
    int max = a[0];
    struct Node *temp, *p;
    for(int i=0;i<n;i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    struct Node *bin[max+1];
    for(int i=0;i<max+1;i++){
        bin[i] = NULL;
    }
    for(int i=0;i<n;i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = a[i];
        temp->next = NULL;
        if(bin[a[i]] == NULL){
            bin[a[i]] = temp;
        }else {
            p = bin[a[i]];
            while(p->next){
                p = p->next;
            }
            p->next = temp;
        }
    }
    int i=0, k=0;
    while(i < max+1){
        if(bin[i] != NULL){
            a[k++] = bin[i]->value;
            bin[i] = bin[i]->next; 
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

void main(){
    int a[N] = {5,1,5,1,2};
    display(a,N);
    bin_sort(a,N);
    display(a,N);
}