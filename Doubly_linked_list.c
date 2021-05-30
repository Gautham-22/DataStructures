#include<stdio.h>
#include<stdlib.h>
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *input_node();
void insert_node(struct Node *,struct Node *);
void display(struct Node *);
void insert_after(struct Node *,struct Node *,int);
void delete(struct Node **,int);
void reverse(struct Node **);

void main(){
    struct Node *first, *p, *q, *temp;
    int count = 0, data;
    while(q=input_node()){
        if(count == 0){
                p = q;
                first = q;
                count++;
                continue;
        }
        insert_node(p,q);
        p = p->next;
        count++;
    }
    if(count == 0){
        first = NULL;
    }
    display(first);
}

struct Node *input_node(){
    struct Node *q;
    int data;
    printf("Enter data of a node (0 to end) : ");
    scanf("%d",&data);
    if(data == 0){
        return NULL;
    }
    q = (struct Node *)malloc(sizeof(struct Node));
    q->prev = NULL;
    q->data = data;
    q->next = NULL;
    return q;
}

void insert_node(struct Node *p,struct Node *q){
    q->next = p->next;
    if(p->next != NULL){
        (p->next)->prev = q;  
    }
    p->next = q;
    q->prev = p;
}

void insert_after(struct Node *first,struct Node *new,int key){
    struct Node *p = first;
    while(p != NULL){
        if(p->data == key){
            insert_node(p,new);
            break;
        }
        p = p->next;
    }
}

void display(struct Node *first){
    if(first == NULL){
        printf("No nodes.\n");
        return;
    }
    printf("List details : \n");
    struct Node *p = first, *q;
    while(p != NULL){
        printf("Node's data : %d\n",p->data);
        q = p;
        p = p->next;
    }
    printf("List details in reverse: \n");
    while(q != NULL){
        printf("Node's data : %d\n",q->data);
        q = q->prev;
    }
}

void delete(struct Node **first,int data){
    struct Node *p = *first;
    while(p != NULL){
        if(p->data == data){
            if(p->next==NULL && p->prev==NULL){
                free(p);
                *first = NULL;
                break;
            }
            if(p->next){
                (p->next)->prev = p->prev;
            }
            if(p->prev){
                (p->prev)->next = p->next;
            }else {
                *first = p->next;
            }
            free(p);
            break;
        }
        p = p->next;
    }
}

void reverse(struct Node **first){
    struct Node *p = *first, *temp, *q;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        q = p;
        p = p->prev;
    }
    *first = q;
}