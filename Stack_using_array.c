#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int *arr;
    int size;
    int top;
};

int input_data();
void display(struct Stack);
int isEmpty(struct Stack);
int isFull(struct Stack);
void push(struct Stack *,int);
int pop(struct Stack *);
int stackTop(struct Stack);
int peek(struct Stack,int);

void main(){
    struct Stack sk;
    int data,value;
    printf("Enter the size of stack : ");
    scanf("%d",&(sk.size));
    sk.arr = (int *)malloc(sk.size*sizeof(int));
    sk.top = -1;
    printf("Enter elements of stack : \n");
    while(data = input_data()){
        sk.top++;
        sk.arr[sk.top] = data;
        if(sk.top == (sk.size - 1)){
            break;
        }
    }
    display(sk);
}

int input_data(){
    int x;
    printf("Enter a value (0 to end input): ");
    scanf("%d",&x);
    return x;
}

void display(struct Stack sk){
    if(isEmpty(sk)){
        return;
    }
    int index = sk.top;
    printf("Displaying Stack : \n");
    while(index >= 0 && index < sk.size){
        printf("%d\n",sk.arr[index]);
        index--;
    }
}

int isEmpty(struct Stack sk){
    if(sk.top == -1){
        printf("Stack empty!\n");
        return 1;
    }
    return 0;
}

int isFull(struct Stack sk){
    if(sk.top == sk.size-1){
        printf("Stack full!\n");
        return 1;
    }
    return 0;
}

void push(struct Stack *p,int data){
    if(p->top == p->size-1){
        printf("Stack overflow!\n");
    }else {
        p->top++;
        p->arr[p->top] = data;
    }
}

int pop(struct Stack *p){
    int x;
    if(p->top == -1){
        printf("Stack underflow!\n");
        x = -1;
    }else {
        x = p->arr[p->top];
        p->arr[p->top] = -1;
        p->top--;
    }
    return x;
}

int stackTop(struct Stack sk){
    return sk.arr[sk.top];
}

int peek(struct Stack sk,int pos){
    int ind = sk.top - (pos-1);
    if(ind >= 0){
        return sk.arr[ind];
    }
    return -1;
}