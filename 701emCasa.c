#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val);

int main(){
    struct TreeNode *root = (struct TreeNode *                  )malloc(sizeof(struct TreeNode));
    struct TreeNode *l1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *l2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *l3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *r1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root->val=4;
    root->left=l1;
    root->right=r1;

    l1->val=2;
    l1->left=l2;
    l1->right=l3;

    l2->val=1;
    l2->val=3;
    r1->val=7;

    int val=5;


    insertIntoBST(root,val);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if(root!=NULL){
        if(root->val){
            if(root->val > val){
                if(root->left == NULL){
                struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->left = newNode;
                newNode->val=val;
                newNode->right=NULL;
                newNode->left=NULL;
                return root;
            }
            insertIntoBST(root->left,val);
        }
        if(root->val < val){
            if(root->right==NULL){
                struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->right = newNode;
                newNode->val=val;
                newNode->right=NULL;
                newNode->left=NULL;
                return root;
            }
            insertIntoBST(root->right,val);

        }
        }
    }else{
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val=val;
        newNode->right=NULL;
        newNode->left=NULL;
        root = newNode;
        return root;
    }

    return root;
}