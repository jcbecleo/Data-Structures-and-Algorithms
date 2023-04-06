#include <stdio.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}*BinaryTree;

//general tree functions
void initBST(BinaryTree* BST);
void insert(BinaryTree* BST, int elem);
void delete(BinaryTree* BST);
int heightBST(BinaryTree BST);

//tree traversal functions
void preorder(BinaryTree BST);
void inorder(BinaryTree BST);
void inorder(BinaryTree BST);

int main(){
    
}

void initBST(BinaryTree* BST){
    *BST = NULL;
}

void insert(BinaryTree* BST, int elem){
    if(*BST == NULL){
        (*BST)->data = elem;
        (*BST)->left = NULL;
        (*BST)->right = NULL;
    }else if(elem < (*BST)->data){
        (*BST)->left->data = elem;
    }else{
        (*BST)->right->data = elem;
    }
}