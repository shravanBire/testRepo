#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

typedef struct tree tree;

tree* create(int data) {
    struct tree* newnode = malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

tree* put(tree* root, int data) {
    if (root == NULL) {
        root = create(data);
        return root;
    } else {
        if (data <= root->data) {
            root->left = put(root->left, data);
        } else {
            root->right = put(root->right, data);
        }
        return root;
    }
}

void show(tree* root) {
    if (root != NULL) {
        show(root->left);
        printf("%d ", root->data);
        show(root->right);
    }
}

int main() {
    tree* root = NULL;
    root = put(root, 7);
    put(root, 1);
    put(root, 4);
    put(root, 6);
    put(root, 3);
    put(root, 8);
    put(root, 0);
    put(root, 29);
    put(root, 11);
    put(root, 23);

    show(root);  

    return 0;
}


