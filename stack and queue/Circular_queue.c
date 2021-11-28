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
void enqueue(struct Queue *,int);
int dequeue(struct Queue *);
int isEmpty(struct Queue);
int isFull(struct Queue);
int first(struct Queue);
int last(struct Queue);

void main(){
    int x, count = 0, n;
    struct Queue q;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    q.size = n+1;
    q.Q = (int *)malloc((q.size)*sizeof(int));
    q.front = 0;
    q.rear = 0;
    printf("Enter the elements of queue : \n");
    while(count!=q.size-1 && (x = input_data(q))){
        enqueue(&q,x);
        count++;
    }
    display(q);
}

int isEmpty(struct Queue q){
    if(q.rear == q.front){
        return 1;
    }
    return 0;
}

int isFull(struct Queue q){
    if( (((q.rear)+1) % q.size) == q.front){
        return 1;
    }
    return 0;
}

void display(struct Queue q){
    if(isEmpty(q)){
        printf("Queue empty !");
        return;
    }
    printf("Queue : [ ");
    for(int i=((q.front)+1) % q.size;;i = (i+1)%q.size){
        printf("%d, ",q.Q[i]);
        if(i == q.rear){
            break;
        }
    }
    printf("]\n");
    printf("This queue's first element : %d, last element : %d\n",first(q),last(q));
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

void enqueue(struct Queue *q,int x){
    int ind;
    if(isFull(*q)){
        printf("Queue full !");
        return;
    }
    q->rear = ((q->rear)+1) % q->size;
    q->Q[q->rear] = x;
}

int dequeue(struct Queue *q){
    int x = -1;
    if(isEmpty(*q)){
        printf("Queue empty !");
        return x;
    }
    q->front = ((q->front)+1) % q->size;
    x = q->Q[q->front];
    q->Q[q->front] = -1;
    return x;
}

int first(struct Queue q){
    if(isEmpty(q)){
        return -1;
    }
    return q.Q[((q.front)+1) % q.size];
}

int last(struct Queue q){
    if(isEmpty(q)){
        return -1;
    }
    return q.Q[q.rear];
}