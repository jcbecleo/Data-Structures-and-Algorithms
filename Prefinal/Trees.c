#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef Node* BinaryTree;

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BinaryTree insert(BinaryTree root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

BinaryTree delete(BinaryTree root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

Node* search(BinaryTree root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int height(BinaryTree root) {
    if (root == NULL) {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

void print_tree(BinaryTree root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    BinaryTree root = NULL;

    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 14);

    printf("Tree: ");
    print_tree(root);
    printf("\n");

    root = delete(root, 12);

    printf("Tree after deleting 12: ");
    print_tree(root);
    printf("\n");

    Node* result = search(root, 6);
    printf("Search result: %d\n", result != NULL ? result->data : -1);

    printf("Height of the tree: %d\n", height(root));

    return 0;
}