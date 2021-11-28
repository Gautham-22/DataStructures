#include<stdio.h>
#include<stdlib.h>
struct Node {
        int data;
        struct Node *next;
};
struct Node *input_data(struct Node *);
void insert_after_node(struct Node *,struct Node *);
void display(struct Node *);
struct Node *Search(struct Node **,int);
int insert(struct Node **,struct Node *,int);
int delete(struct Node **,int);
int isSorted(struct Node *);
void remove_duplicates_in_sortedList(struct Node *);
void reverse(struct Node **);
void concatenate(struct Node *,struct Node *);
struct Node *merge(struct Node *,struct Node *);
void main(){
        struct Node *first, *p, *q, *first1;
        int count = 0, key, index;
        printf("List 1 details : \n");
        while((q=input_data(q)) != NULL){
                if(count == 0){
                        p = q;
                        first = q;
                        count++;
                        continue;
                }
                insert_after_node(p,q);
                p = p->next;
                count++;
        }
        if(count == 0){
                printf("No node is created.\n");
        }else {
                display(first);
        }
        count = 0;
        printf("List 2 details : \n");
        while((q=input_data(q)) != NULL){
                if(count == 0){
                        p = q;
                        first1 = q;
                        count++;
                        continue;
                }
                insert_after_node(p,q);
                p = p->next;
                count++;
        }
        if(count == 0){
                printf("No node is created.\n");
        }else {
                display(first1);
        }
        first = merge(first,first1);
        printf("After merging : \n");
        display(first);
}
 
struct Node *input_data(struct Node *q){
        q = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value of data (0 to end input): ");
        scanf("%d",&(q->data));
        q->next = NULL;
        if(q->data == 0){
                return NULL;
        }
        return q;
}

void insert_after_node(struct Node *p,struct Node *q){
        q->next = p->next;
        p->next = q;
}

void display(struct Node *first){
        struct Node *temp = first;
        while(temp != NULL){
                printf("Node : data = %d\n",temp->data);
                temp = temp->next;
        }
}

struct Node *Search(struct Node **first,int key){
        struct Node *temp = *first, *prev = NULL, *start = *first;
        while(temp != NULL){
                if(temp->data == key){
                        *first = prev->next;
                        prev->next = temp->next;
                        temp->next = start;
                        return temp;
                }
                prev = temp;
                temp = temp->next;
        }
        return NULL;
}

int insert(struct Node **first,struct Node *new,int index){
        struct Node *temp = *first, *prev;
        int i=0;
        while(temp != NULL){
                if(i == index){
                        if(index == 0){
                                new->next = *first;
                                *first = new;
                                return 1;
                        }
                        new->next = temp;
                        prev->next = new;
                        return 1;
                }
                prev = temp;
                temp = temp->next;
                i++;
        }
        if(index == i){
                prev->next = new;
                new->next = NULL;
                return 1;
        }
        return 0;
}

int delete(struct Node **first,int index){
        int i=0;
        struct Node *temp = *first, *prev;
        if(index == 0){
                temp = temp->next;
                free(*first);
                *first = temp;
                return 1;
        }
        while(temp != NULL){
                if(index == i){
                        prev->next = temp->next;
                        free(temp);
                        return 1;
                }
                i++;
                prev = temp;
                temp = temp->next;
        }
        if(index>=i){
                return 0;
        }
}

int isSorted(struct Node *first){
    struct Node *temp = first->next, *prev = first;
    while(temp != NULL){
        if(prev->data > temp->data){
            return 0;
        }
        prev = prev->next;
        temp = temp->next;
    }
    return 1;
}

void remove_duplicates_in_sortedList(struct Node *first){
    struct Node *p = first, *q = first->next;
    while(q != NULL){
        if(p->data == q->data){
            p->next = q->next;
            free(q);
            q = p->next;
            continue;
        }
        p = p->next;
        q = q->next;
    }
}

void reverse(struct Node **first){
        struct Node *r = NULL, *q = *first, *p = (*first)->next;
        if(q == NULL || p == NULL){
                return;
        }
        while(p != NULL){
                q->next = r;
                r = q;
                q = p;
                p = p->next;
        }
        q->next = r;
        *first = q;
        return; 
}

void concatenate(struct Node *first1,struct Node *first2){
        struct Node *p = first1;
        while(p->next != NULL){
                p = p->next;
        }
        p->next = first2;
}

struct Node *merge(struct Node *first,struct Node *second){
        struct Node *start, *last;
        int count = 0;
        while(first != NULL && second != NULL){
                if(first->data <= second->data){
                        if(count == 0){
                                start = first;
                                last = first;
                                first = first->next;
                                count++;
                                continue;
                        }
                        last->next = first;
                        last = first;
                        first = first->next;
                }else {
                        if(count == 0){
                                start = second;
                                last = second;
                                second = second->next;
                                count++;
                                continue;
                        }
                        last->next = second;
                        last = second;
                        second = second->next;
                }       
                count++;
        }
        if(first == NULL){
                last->next = second;
        }
        if(second == NULL){
                last->next = first;
        }
        return start;
}