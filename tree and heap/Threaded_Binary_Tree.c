#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data, lthread, rthread;
    struct Node *left, *right;
};

void insert(int);
void in_order(struct Node *);
struct Node *inorderSuccessor(struct Node *);

struct Node *root = NULL;

int main() {
    int n, data;
    printf("Enter total number of nodes in a tree: ");
    scanf("%d",&n);
    printf("Enter the data of nodes: ");    
    for(int i=0; i<n; i++) {
        scanf("%d",&data);
        insert(data);
    }
    in_order(root);
    return 0;
}

void insert(int key) {
    struct Node *parent = NULL, *ptr = root, *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL, node->right = NULL;
    node->lthread = 1, node->rthread = 1;
    while(ptr) {
        parent = ptr;
        if(key < ptr->data) {
            if(ptr->lthread) {
                break;
            }
            ptr = ptr->left;
        } else {
            if(ptr->rthread) {
                break;
            }
            ptr = ptr->right;
        }
    }
    if(!parent) {
        root = node;
        return;
    }
    if(key < parent->data) {
        node->left = parent->left;
        node->right = parent;
        parent->lthread = 0;
        parent->left = node;
    } else {
        node->right = parent->right;
        node->left = parent;
        parent->rthread = 0;
        parent->right = node;
    }
}

struct Node *inorderSuccessor(struct Node *ptr) {
    /* if it is threaded, then returns right pointer */
    if(ptr->rthread) {
        return ptr->right;
    }
    /* else returns left most element of right subtree */
    ptr = ptr->right;
    while(ptr && ptr->lthread == 0 && ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

void in_order(struct Node *ptr) {
    if(!ptr) {
        printf("Tree is empty!\n");
        return;
    }
    printf("Inorder traversal: ");
    // to reach left most node
    while(ptr && ptr->lthread == 0 && ptr->left) {
        ptr = ptr->left;
    }
    while(ptr) {
        printf("%d ",ptr->data); // 2
        ptr = inorderSuccessor(ptr);
    }
    printf("\n");
}

// #define SIZE 9

// struct Node {
//     char data;
//     int isthreaded;
//     struct Node *left, *right;
// };

// struct Node *convert(struct Node *);
// void in_order(struct Node *);
// struct Node *inorderSuccessor(struct Node *);

// struct Node *root = NULL;

// int main() {
//     /* driver code providing binary tree */
//     root = (struct Node *)malloc(sizeof(struct Node));
//     root->data = 'A', root->isthreaded = 0;
//     struct Node *nodes[SIZE];
//     for(int i=0;i<SIZE;i++) {
//         nodes[i] = (struct Node *)malloc(sizeof(struct Node));
//         nodes[i]->isthreaded = 0, nodes[i]->data = 'B' + i;
//         nodes[i]->left = NULL, nodes[i]->right = NULL;
//     }
//     root->left = nodes[0], root->right = nodes[1];
//     nodes[0]->left = nodes[2], nodes[0]->right = nodes[3];
//     nodes[1]->left = nodes[4], nodes[1]->right = nodes[5];
//     nodes[2]->left = nodes[6], nodes[2]->right = nodes[7];
//     nodes[4]->right = nodes[8];

//     convert(root);
//     in_order(root);
//     return 0;
// }

// struct Node *convert(struct Node *ptr) {
    
//     if(!ptr || (ptr->left == NULL && ptr->right == NULL)) {
//         return ptr;
//     }

//     if(ptr->left != NULL) {
//         struct Node *temp = convert(ptr->left);
//         temp->right = ptr;
//         temp->isthreaded = 1;
//     }
    
//     if(ptr->right == NULL) {
//         return ptr;
//     }

//     return convert(ptr->right);
// }
