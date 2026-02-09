#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val);

int main(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
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
    l2->left=NULL;
    l2->right=NULL;
    
    l3->val=3;
    l3->left=NULL;
    l3->right=NULL;

    r1->val=7;
    r1->left=NULL;
    r1->right=NULL;

    int val=5;


    insertIntoBST(root,val);
    freeTree(root);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if(root!=NULL){
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

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

//Principais diferenças:

//      correção do erro principal: não inicialização
//      do nó no caso em que acha nulo na recursão

//      validação booleana sem sentido " if ( root->val ) "
//      q causava comportamento imprevisível


//vazamento de memória:
//      por nao mallocar sem dar free