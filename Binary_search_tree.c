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

void pre_order(struct Node *);
void in_order(struct Node *);
void post_order(struct Node *);
void level_order(struct Node *);
int search(struct Node *,int);
void insert(struct Node *,int);
int isEmpty();
int isFull();
void enqueue(struct Node *x);
struct Node *dequeue();
struct Node *minValueNode(struct Node *);
struct Node *deleteNode(struct Node *,int);

void main(){
    int n, x;
    struct Node *root;
    printf("Enter the total number of data : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter the data : ");
        scanf("%d",&(a[i]));
    }
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = a[0];
    root->left = NULL;
    root->right = NULL;
    for(int i=1;i<n;i++){
        insert(root,a[i]);
    }
    in_order(root);
    printf("\nEnter a data to be searched : ");
    scanf("%d",&x);
    if(search(root,x)){
        printf("%d is found in the tree. After deleting %d : \n",x,x);
        deleteNode(root,x);
        in_order(root);
    }else {
        printf("%d is not found in the tree.\n",x);
    }
    
}

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

int search(struct Node *t,int data){
    while(t!=NULL){
        if(t->data == data){
            return 1;
        }else if(data < t->data){
            t = t->left;
        }else {
            t = t->right;
        }
    }
    return 0;
}

void insert(struct Node *t,int data){
    struct Node *r, *new;
    if(search(t,data)){
        printf("%d is already in the tree.\n",data);
        return;
    }
    while(t!=NULL){
        r = t;
        if(data < t->data){
            t = t->left;
        }else {
            t = t->right;
        }
    }   
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->left= NULL;
    new->right = NULL;
    if(data < r->data){
        r->left = new;
    }else {
        r->right = new;
    }
}

// recursive manner 

// int search(struct Node *t,int data){
//     if(t == NULL){
//         return 0;
//     }
//     if(t->data == data){
//         return 1;
//     }else if(data < t->data){
//         return search(t->left,data);
//     }else {
//         return search(t->right,data);
//     }
// }

// void insert(struct Node *t,int data){
//     static struct Node *r, *new;
//     if(t == NULL){
//         new = (struct Node *)malloc(sizeof(struct Node));
//         new->data = data;
//         new->left= NULL;
//         new->right = NULL;
//         if(data < r->data){
//             r->left = new;
//         }else {
//             r->right = new;
//         }
//         return ;
//     }
//     if(t->data == data){
//         printf("%d is already in the tree .\n",data);
//         return;
//     }else if(data < t->data){
//         r = t;
//         return insert(t->left,data);
//     }else {
//         r = t;
//         return insert(t->right,data);
//     }
// }

struct Node *minValueNode(struct Node *node)
{
 
    /* loop down to find the leftmost leaf */
    while (node && node->left != NULL){
        node = node->left;
    }
    return node;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct Node *deleteNode(struct Node *root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}