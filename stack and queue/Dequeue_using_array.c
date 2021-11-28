#include<stdio.h>
#include<stdlib.h>

struct Dequeue {
    int size;
    int *Q;
    int front;
    int rear;
};

void display(struct Dequeue);
int input_data();
void enqueue1(struct Dequeue *,int);
int dequeue1(struct Dequeue *);
void enqueue2(struct Dequeue *,int);
int dequeue2(struct Dequeue *);
int isEmpty(struct Dequeue);
int isFull(struct Dequeue);
int first(struct Dequeue);
int last(struct Dequeue);

void main(){
    int n, x, count = 0;
    struct Dequeue dq;
    printf("Enter the size of dequeue : ");
    scanf("%d",&n);
    dq.size = n+1;
    dq.front = 0;
    dq.rear = 0;
    dq.Q = (int *)malloc(dq.size*sizeof(int));
    while(count!=dq.size-1 && (x=input_data())){
        enqueue1(&dq,x);
        count++;
    }
    display(dq);
    printf("Element removed : %d.\n",dequeue1(&dq));
    printf("Element removed : %d.\n",dequeue1(&dq));
    display(dq);
    enqueue1(&dq,10);
    enqueue1(&dq,20);
    display(dq);
    printf("Element removed : %d.\n",dequeue2(&dq));
    printf("Element removed : %d.\n",dequeue2(&dq));
    display(dq);
    enqueue2(&dq,100);
    enqueue2(&dq,200);
    display(dq);
}

int isEmpty(struct Dequeue q){
    if(q.rear == q.front){
        return 1;
    }
    return 0;
}

int isFull(struct Dequeue q){
    if( (((q.rear)+1) % q.size) == q.front){
        return 1;
    }
    return 0;
}

void display(struct Dequeue q){
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

int input_data(){
    int x;
    printf("Enter the data (0 to end input): ");
    scanf("%d",&x);
    return x;
}

void enqueue1(struct Dequeue *dq,int x){
    if(isFull(*dq)){
        printf("Queue is full !\n");
        return ;
    }
    dq->rear = (dq->rear+1) % dq->size;
    dq->Q[dq->rear] = x;
}

int dequeue1(struct Dequeue *dq){
    int x = -1;
    if(isEmpty(*dq)){
        printf("Queue empty !");
        return x;
    }
    dq->front = ((dq->front)+1) % dq->size;
    x = dq->Q[dq->front];
    dq->Q[dq->front] = -1;
    return x;
}

void enqueue2(struct Dequeue *dq,int x){
    if(isFull(*dq)){
        printf("Queue is full !\n");
        return ;
    }
    dq->Q[dq->front] = x;
    if(((dq->front)-1) < 0){
        dq->front = dq->size -1;
    }else {
        dq->front = ((dq->front)-1);
    }
}

int dequeue2(struct Dequeue *dq){
    int x = -1;
    if(isEmpty(*dq)){
        printf("Queue empty !");
        return x;
    }
    x = dq->Q[dq->rear];
    dq->Q[dq->rear] = -1;
    if(((dq->rear)-1) < 0){
        dq->rear = dq->size -1;
    }else {
        dq->rear = ((dq->rear)-1);
    }
    return x;
}

int first(struct Dequeue q){
    if(isEmpty(q)){
        return -1;
    }
    return q.Q[((q.front)+1) % q.size];
}

int last(struct Dequeue q){
    if(isEmpty(q)){
        return -1;
    }
    return q.Q[q.rear];
}