#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* buildTree() {
    char str[10];
    scanf("%s", str);
    
    if (str[0] == '#') {
        return NULL;
    }
    
    int value = atoi(str);
    TreeNode* root = createNode(value);
    root->left = buildTree();
    root->right = buildTree();
    
    return root;
}

void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d\n", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    
    TreeNode* root = buildTree();
    preorderTraversal(root);
    freeTree(root);
    
    return 0;
}