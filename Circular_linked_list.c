#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *input_node();
void insert_node(struct Node *,struct Node *);
void display(struct Node *);
void insert_after(struct Node *,struct Node *,int);
void delete(struct Node **,int);

void main(){
    struct Node *head, *p, *q, *temp;
    int count = 0, data;
    while(q=input_node()){
        if(count == 0){
            p = q;
            head = q;
            count++;
            continue;
        }
        insert_node(p,q);
        p = p->next;
        count++;
    }
    if(count == 0){
        printf("No node details entered.");
    }else {
        p->next = head;
        display(head);
    }
    printf("Enter a node's data which needs to be deleted : ");
    scanf("%d",&data);
    delete(&head,data);
    printf("After deleting : \n");
    display(head);
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
    q->data = data;
    q->next = NULL;
    return q;
}

void insert_node(struct Node *p,struct Node *q){
    q->next = p->next;
    p->next = q;
}

void display(struct Node *head){
    struct Node *p = head;
    do{
        printf("Node data : %d\n",p->data);
        p = p->next;
    }while(p != head);
}

void insert_after(struct Node *head,struct Node *new,int key){
    struct Node *p = head;
    do{
        if(p->data == key){
            insert_node(p,new);
            break;
        }
        p = p->next;
    }while(p != head);
}

void delete(struct Node **head,int data){
    struct Node *p = *head, *q;
    int flag = 0;
    if(data == p->data){
        flag = 1;
    }
    do{
        if(p->data == data && flag==0){
            q->next = p->next;
            free(p);
            break;
        }
        q = p;
        p = p->next;
    }while(p != (*head));
    if(flag == 1){
        q->next = p->next;
        free(p);
        *head = q->next;
    }
}