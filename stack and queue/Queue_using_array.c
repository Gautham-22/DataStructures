#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int *Q;
    int front;
    int rear;
};

void display(struct Queue);
int input_data(struct Queue);
int isFull(struct Queue);
int isEmpty(struct Queue);
void enqueue(struct Queue *,int);
int dequeue(struct Queue *);
int first(struct Queue);
int last(struct Queue);

void main(){
    int x, count = 0;
    struct Queue q;
    printf("Enter the size of queue : ");
    scanf("%d",&(q.size));
    q.Q = (int *)malloc(q.size*sizeof(int));
    q.front = -1;
    q.rear = -1;
    printf("Enter the elements of queue : \n");
    while(count!=q.size && (x = input_data(q))){
        enqueue(&q,x);
        count++;
    }
    display(q);
}

void display(struct Queue q){
    printf("Queue : [ ");
    for(int i=q.front+1;i<=q.rear;i++){
        printf("%d, ",q.Q[i]);
    }
    printf("]\n");
}

int input_data(struct Queue q){
    int x;
    printf("Enter data (0 to end input) : ");
    scanf("%d",&x);
    if(x == 0){
        return 0;
    }
    return x;
}

int isFull(struct Queue q){
    if(q.rear == q.size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue q){
    if(q.rear == q.front){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q,int x){
    if(isFull(*q)){
        printf("Queue full !");
        return;
    }
    q->rear++;
    q->Q[q->rear] = x;
};

int dequeue(struct Queue *q){
    int x = -1;
    if(isEmpty(*q)){
        printf("Queue empty !");
        return x;
    }
    q->front++;
    x = q->Q[q->front];
    q->Q[q->front] = -1;
    if(q->front == q->rear && q->rear!=-1){
        q->rear = -1;
        q->front = -1;
    }
    return x;
};

int first(struct Queue q){
    if(isEmpty(q)){
        return -1;
    }
    return q.Q[q.front+1];
}

int last(struct Queue q){
    if(isEmpty(q)){
        return -1;
    }
    return q.Q[q.rear];
}