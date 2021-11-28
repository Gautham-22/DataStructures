#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int input_data();
void push(int);
int pop();
void display(struct Node *);
int isEmpty(struct Node *);
int isFull();
int stackTop();
int peek(int);

struct Node *top = NULL;

void main(){    
    struct Node *p;
    int data, value;
    printf("Enter the data : \n");
    while(data = input_data()){
        push(data);
    }
    display(top);
    printf("Enter a position : ");
    scanf("%d",&data);
    if((value = peek(data)) != -1){
        printf("%d is found at position %d.\n",value,data);
    }else {
        printf("Invalid position!");
    }
}

int input_data(){
    int x;
    printf("Enter a value (0 to end input) : ");
    scanf("%d",&x);
    return x;
}

void push(int data){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Stack full!");
        return;
    }
    p->data = data;
    p->next = top;
    top = p;
}

int pop(){
    int x = -1;
    if(isEmpty(top)){
        return x;
    }
    x = top->data;
    struct Node *p = top;
    top = top->next;
    free(p);
    return x;
}

int isEmpty(struct Node *p){
    if(p == NULL){
        printf("Stack empty!\n");
        return 1;
    }
    return 0;
}

int isFull(){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    return 0;
}

int stackTop(){
    if(isEmpty(top)){
        return -1;
    }
    return top->data;
}

int peek(int pos){
    struct Node *p = top;
    for(int i=1;p!=NULL && i!=pos;i++){
        p = p->next;
    }
    if(p == NULL){
        return -1;
    }
    return p->data;
}

void display(struct Node *ptr){
    if(isEmpty(ptr)){
        return;
    }
    struct Node *p = ptr;
    printf("Displaying Stack : \n");
    while(p){
        printf("Node data = %d\n",p->data);
        p = p->next;
    }
}
