#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, *right;
} *Node;

typedef struct tree {
    Node root;
} *Tree;

Tree InitTree() {
    Tree tree = (Tree)malloc(sizeof(struct tree));
    tree->root = NULL;
    return tree;
}

Node CreateNode(int val) {
    Node node = (Node)malloc(sizeof(struct node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Tree tree = InitTree();
    int a, b ,c; scanf("%d%d%d", &a, &b, &c);
    tree->root = CreateNode(a);
    tree->root->left = CreateNode(b);
    tree->root->right = CreateNode(c);
    printf("root data = %d\nleft child data = %d\nright child data = %d", c, a ,b);
    return 0;
}