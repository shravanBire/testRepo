#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* node_ = (struct node*)malloc(sizeof(struct node));
    node_->data = data;
    node_->left=NULL;
    node_->right=NULL;
    return node_;
}

struct node* insert(struct node* node_,int data){
    if(node_==NULL){
        return newnode(data);
    }

    if (data < node_->data){
        node_->left = insert(node_->left, data);
    }
    else if (data >= node_->data){
        node_->right = insert(node_->right, data);
    }

    return node_;

}

struct node* createBST(int arr[],int size,struct node* root){
    for(int i=0;i<size;i++){
        root = insert(root,arr[i]);
    }
    return root;
}

int check;
bool end=0;
void checkBST(struct node* root){
    if(check > root->data){
        end=1;
        return;
    }
    if(root!=NULL){
        check=root->data;
        checkBST(root->left);
        checkBST(root->right);
    }
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void main() {
    int arr[10]={2,4,7,5,8,9,2,4,11,89};
    struct node* root = NULL;
    root=createBST(arr,10,root);
    if(end){
        printf("Not a BST\n");
    }
    inorderTraversal(root);
}