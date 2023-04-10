#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    struct cell *LC;
    struct cell *RC;
    int data;
} ctype, *BST;

/* Helper function to create new node */
BST newNode(int data) {
    BST temp = (BST)malloc(sizeof(ctype));
    temp->data = data;
    temp->LC = temp->RC = NULL;
    return temp;
}

/* Member using pointer to pointer to node */
int member(BST root, int data) {
    while (root != NULL && root->data != data) {
        root = root->data > data ? root->LC : root->RC;
    }
    return root == NULL ? 0 : 1;
}

/* Member using recursion */
int memberR(BST root, int data) {
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (root->data > data)
        return member(root->LC, data);
    return member(root->RC, data);
}

/* Insert using pointer to pointer to node */
void insert(BST *root, int data) {
    while (*root != NULL) {
        root = (*root)->data > data ? &(*root)->LC : &(*root)->RC; 
    }
    *root = newNode(data);
}

/* Insert using recursion */
BST insertR(BST root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->LC = insertR(root->LC, data);
    } else {
        root->RC = insertR(root->RC, data);
    }
    return root;
}

/* Delete iteratively */
void delete(BST *root, int data) {
    while (*root != NULL && (*root)->data != data) {
        root = data > (*root)->data ? &(*root)->RC : &(*root)->LC;
    }
    if (*root != NULL) {
        if ((*root)->LC == NULL || (*root)->RC == NULL) {
            BST newNext, temp;  
            if ((*root)->LC == NULL) {
                newNext = (*root)->RC;
            } else {
                newNext = (*root)->LC;
            }
            temp = *root;
            *root = newNext;
            free(temp);
        } else {
            BST *temp = &(*root)->RC;
            while ((*temp)->LC != NULL) {
                *temp = (*temp)->LC;
            }
            (*root)->data = (*temp)->data;
            free(*temp);
            *temp = NULL;
        }
    }
}

/* Delete using recrusion */
BST deleteR(BST root, int data) {
    if (root == NULL)  {
    }
}

/* Find minimum element iteratively */
int findMin(BST root){
    if(root == NULL){
        printf("Tree is empty");
        return -1;
    }
    while(root->LC != NULL){
        root = root->LC;
    }
    return root->data;    
}

/* Find minimum element recursively */
int findMin(BST root){
    if(root == NULL){
        printf("Tree is empty");
        return -1;
    }
    while(root->LC != NULL){
        return root->data;
    }
    return findMin(root->LC);
}

/* Find maximum element iteratively */
int findMax(BST root){
    if(root == NULL){
        printf("Tree is empty");
        return -1;
    }
    while(root->RC != NULL){
        root = root->RC;
    }
    return root->data;    
}

/* Find maximum element recursively */
int findMax(BST root){
    if(root == NULL){
        printf("Tree is empty");
        return -1;
    }
    while(root->RC != NULL){
        return root->data;
    }
    return findMax(root->RC);
}

/* Traversal inorder */
void printInorder(BST root) {
    if (root == NULL)
        return;
    printInorder(root->LC);
    printf("%d ", root->data);
    printInorder(root->RC);
}

void main() {
    BST root = newNode(15);
    insertR(&root, 14);
    insertR(&root, 18);
    insertR(&root, 5);
    insertR(&root, 10);
    insertR(&root, 7);
    insertR(&root, 12);
    printf("%d\n", member(root, 15));
    printf("%d\n", member(root, 14));
    printf("%d\n", member(root, 1));
    printInorder(root);
}