#include<stdio.h>
#include<stdlib.h>
#define N 5

struct Node {
    int value;
    struct Node *next;
};

int digits(int n){
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
}

void radix_sort(int *a,int n){
    int max = a[0], digit, x = 1;
    struct Node *temp, *p;
    for(int i=0;i<n;i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    int total = digits(max);
    struct Node *radix[10];
    for(int i=0;i<10;i++){
        radix[i] = NULL;
    }
    for(int j=0;j<total;j++){
        for(int i=0;i<n;i++){
            digit = (a[i]/x) % 10;
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->value = a[i];
            temp->next = NULL;
            if(radix[digit] == NULL){
                radix[digit] = temp;
            }else {
                p = radix[digit];
                while(p->next){
                    p = p->next;
                }
                p->next = temp;
            }
        }
        int ind=0, k=0;
        while(ind < 10){
            if(radix[ind] != NULL){
                a[k++] = radix[ind]->value;
                radix[ind] = radix[ind]->next; 
            }else {
                ind++;
            }
        }
        x *= 10;
        for(int i=0;i<10;i++){
            radix[i] = NULL;
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
    int a[N] = {51,123,51,3453,2};
    display(a,N);
    radix_sort(a,N);
    display(a,N);
}