#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;
int isEmpty();
int isFull();
int input_data();
void enqueue(int); 
int dequeue(); 
void display();
int first();
int last();

void main(){
    struct Node *p;
    int x;
    printf("Enter elements of queue : \n");
    while(x=input_data()){
        enqueue(x);  
    }
    display();
    printf("First element : %d.\n",first());
    printf("Last element : %d.\n",last());
}

int isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

int isFull(){
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    return 0;
}

int input_data(){
    int x;
    struct Node *p;
    printf("Enter a data (0 to end input) : ");
    scanf("%d",&x);
    return x;   
}

void enqueue(int x){
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Queue is Full!");
        return ;
    }
    p->data = x;
    p->next = NULL;
    if(front == NULL){
        front = p;
        rear = p;
    }else {
        rear->next = p;
        rear = p;
    }    
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is Empty!");
        return -1;
    }
    struct Node *p = front;
    int x = p->data;
    front = front->next;
    free(p);
    return x;   
} 

void display(){
    struct Node *p = front;
    printf("Queue : [");
    for( ; p!=NULL ;p = p->next){
        printf("%d, ",p->data);
    }
    printf("]\n");
}

int first(){
    if(isEmpty()){
        printf("Queue is Empty!");
        return -1;
    }
    return front->data;
}

int last(){
    if(isEmpty()){
        printf("Queue is Empty!");
        return -1;
    }
    return rear->data;
}