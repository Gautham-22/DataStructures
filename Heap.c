#include<stdio.h>
#include<stdlib.h>
#define Max_Heap_Size 20

// max heap
struct Heap {
    int a[Max_Heap_Size];
    int heap_end;
    int current_end;
};

int input_data();
void insert(struct Heap *,int);
void display(struct Heap *);
void delete(struct Heap *); // deletes max element
void heap_sort(struct Heap *);

void main(){
    int x, i = 0, count = 0;
    struct Heap *h;
    h = (struct Heap *)malloc(sizeof(struct Heap));
    h->heap_end = 1;
    h->current_end = 0;
    h->a[i++] = 0; 
    while(x = input_data()){
        h->a[i++] = x;
        count++;
        h->current_end++;
    }
    for(int j=2;j<=count;j++){
        insert(h,j);
    }
    display(h);
    heap_sort(h);
    printf("After heap sort : \n");
    display(h);
}

int input_data(){
    int x;
    printf("Enter a data (0 to end input): ");
    scanf("%d",&x);
    return x;
}

void display(struct Heap *h){
    printf("Heap (level order traversal) : [ ");
    for(int i=1;i<=h->heap_end;i++){
        printf("%d, ",h->a[i]);
    }
    printf("]\n");
}

void insert(struct Heap *h,int i){
    int temp;
    while(i>1 && h->a[i/2] < h->a[i]){
        temp = h->a[i];
        h->a[i] = h->a[i/2];
        h->a[i/2] = temp;
        i = i/2;
    }
    h->heap_end++;
}

void delete(struct Heap *h){
    int x = h->a[1], i = 1, j = 2*i, temp; 
    h->a[1] = h->a[h->heap_end];
    h->heap_end--;
    while(j <= h->heap_end){
        if(j+1 <= h->heap_end && h->a[j+1] > h->a[j]){
            j = j+1;
        }
        if(h->a[i] < h->a[j]){
            temp = h->a[i];
            h->a[i] = h->a[j];
            h->a[j] = temp;
            i = j;
            j = 2*i;
        }else {
            break;
        }
    }
    h->a[h->heap_end+1] = x;
}

void heap_sort(struct Heap *h){
    while(h->heap_end != 1){
        delete(h);
    }
    h->heap_end = h->current_end;
}