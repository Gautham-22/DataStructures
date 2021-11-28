#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Element {
    struct Node *data;
    struct Element *next;
};

struct Element *front = NULL, *rear = NULL;

int isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

int isFull(){
    struct Element *p;
    p = (struct Element *)malloc(sizeof(struct Element));
    if(p == NULL){
        return 1;
    }
    return 0;
}

void enqueue(struct Node *x){
    struct Element *p;
    p = (struct Element *)malloc(sizeof(struct Element));
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

struct Node *dequeue(){
    if(isEmpty()){
        printf("Queue is Empty!");
        return NULL;
    }
    struct Element *p = front;
    struct Node *x = p->data;
    front = front->next;
    free(p);
    return x;   
} 

void pre_order(struct Node *);
void in_order(struct Node *);
void post_order(struct Node *);
void level_order(struct Node *);
int count_nodes(struct Node *);
int count_leaf_nodes(struct Node *);
int height(struct Node *);

void main(){
    int flag = 0;
    struct Node *root, *p, *t;
    root = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data of root node of a tree : ");
    scanf("%d",&(root->data));
    enqueue(root);
    while(!isEmpty()){
        p = dequeue();
        printf("Do this node(with value %d) have left node (1 for yes, 0 for no)? : ",p->data);
        scanf("%d",&flag);
        if(flag){
            t = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the data : ");
            scanf("%d",&(t->data));
            p->left = t;
            enqueue(p->left);
        }else {
            p->left = NULL;
        }
        printf("Do this node(with value %d) have right node (1 for yes, 0 for no)? : ",p->data);
        scanf("%d",&flag);
        if(flag){
            t = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the data : ");
            scanf("%d",&(t->data));
            p->right = t;
            enqueue(p->right);
        }else {
            p->right = NULL;
        }
    }
    printf("Height of tree : %d",height(root));
}

void pre_order(struct Node *t){
    if(t == NULL){
        return;
    }
    printf("%d ",t->data);
    pre_order(t->left);
    pre_order(t->right);
}

void in_order(struct Node *t){
    if(t == NULL){
        return;
    }
    in_order(t->left);
    printf("%d ",t->data);
    in_order(t->right);
}
void post_order(struct Node *t){
    if(t == NULL){
        return;
    }
    post_order(t->left);
    post_order(t->right);
    printf("%d ",t->data);
}

void level_order(struct Node *t){
    struct Node *temp;
    enqueue(t);
    while(!isEmpty()){
        temp = dequeue();
        printf("%d ",temp->data);
        if(temp->left){
            enqueue(temp->left);
        }
        if(temp->right){
            enqueue(temp->right);
        }
    }
}

int count_nodes(struct Node *t){
    int count = 0;
    struct Node *temp;
    enqueue(t);
    while(!isEmpty()){
        temp = dequeue();
        if(temp){
            count++;
        }
        if(temp->left){
            enqueue(temp->left);
        }
        if(temp->right){
            enqueue(temp->right);
        }
    }
    return count;
}

int count_leaf_nodes(struct Node *t){
    int count = 0;
    struct Node *temp;
    enqueue(t);
    while(!isEmpty()){
        temp = dequeue();
        if(temp->left){
            enqueue(temp->left);
        }
        if(temp->right){
            enqueue(temp->right);
        }
        if(!temp->left && !temp->right){
            count++;
        }
    }
    return count;
}

int height(struct Node *t){
    if(t != NULL){
        int x = height(t->left);
        int y = height(t->right);
        if(x > y){
            return x + 1;
        }else {
            return y + 1;
        }
    }
    return 0;
}