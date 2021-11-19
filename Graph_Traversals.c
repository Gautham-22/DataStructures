#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

/* Graph */
struct adjNode {
    int nodeValue;
    struct adjNode *next;
};

struct adjList {
    int headValue;
    struct adjNode *node;
};

struct Graph {
    int size;  /* number of nodes */
    struct adjList *list;  
};

void addEdge(int,int);
void BFS(int);
void DFS(int);

/* Queue */
struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear ;
};

int isEmpty(struct Queue *);
void enqueue(struct Queue *,int); 
int dequeue(struct Queue *); 
int first(struct Queue *);
void display(struct Queue *);

struct Graph *graph;
void main() {
    graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->size = SIZE;
    graph->list = (struct adjList *) malloc(sizeof(struct adjList));
    for(int i=0; i<SIZE; i++) {
        graph->list[i].headValue = i+1;
        graph->list[i].node = NULL;
    }
    addEdge(1,2);
    addEdge(2,1); addEdge(2,3); addEdge(2,4);
    addEdge(3,2); addEdge(3,5);
    addEdge(4,2); addEdge(4,5); addEdge(4,6);
    addEdge(5,3); addEdge(5,4); addEdge(5,6);
    addEdge(6,4); addEdge(6,5);
    printf("BFS traversal: ");
    BFS(1);
    printf("DFS traversal: ");
    DFS(1);
    printf("\n");
}

/* Graph functions */
void addEdge(int src, int dest) {
    struct adjNode *ptr = graph->list[src-1].node, *prev;
    struct adjNode *new = (struct adjNode *) malloc(sizeof(struct adjNode));
    new->nodeValue = dest;
    new->next = NULL;
    if(!ptr) {
        graph->list[src-1].node = new;
        return;
    }
    prev = ptr;
    ptr = ptr->next;
    while(ptr) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new;
}

void BFS(int rootNodeValue) {
    int visited[SIZE];
    for(int i=0; i<SIZE; i++) {
        visited[i] = 0;
    }

    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    q->front = NULL, q->rear = NULL;
    enqueue(q,rootNodeValue);
    visited[rootNodeValue - 1] = 1;

    struct adjNode *ptr;
    while(!isEmpty(q)) {
        int val = dequeue(q);
        printf("%d ",val);

        ptr = graph->list[val - 1].node;
        while(ptr) {
            if(!visited[ptr->nodeValue - 1]) {
                visited[ptr->nodeValue - 1] = 1;
                enqueue(q,ptr->nodeValue);
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void DFS(int n) {
    static int visited[SIZE] = {0};
    printf("%d ",n);
    visited[n-1] = 1;

    struct adjNode *ptr = graph->list[n-1].node;
    while(ptr) {
        if(!visited[ptr->nodeValue - 1]) {
            DFS(ptr->nodeValue);
        }
        ptr = ptr->next;
    }

}

/* Queue functions */
int isEmpty(struct Queue *q){
    if(q->front == NULL){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int x){
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Queue is Full!");
        return ;
    }
    p->data = x;
    p->next = NULL;
    if(q->front == NULL){
        q->front = p;
        q->rear = p;
    }else {
        q->rear->next = p;
        q->rear = p;
    }    
}

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!");
        return -1;
    }
    struct Node *p = q->front;
    int x = p->data;
    q->front = q->front->next;
    free(p);
    return x;   
} 

void display(struct Queue *q){
    struct Node *p = q->front;
    printf("Queue : [");
    for( ; p!=NULL ;p = p->next){
        printf("%d, ",p->data);
    }
    printf("]\n");
}

int first(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!");
        return -1;
    }
    return q->front->data;
}
