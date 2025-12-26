#include "../include/dsa.h"

typedef struct BSTNode {
    int key; struct BSTNode *left, *right;
} BSTNode;

BSTNode* bst_new_node(int k) {
    BSTNode* n = malloc(sizeof(BSTNode));
    n->key = k; n->left = n->right = NULL; return n;
}

BSTNode* bst_insert(BSTNode* root, int k) {
    if (!root) return bst_new_node(k);
    if (k < root->key) root->left = bst_insert(root->left, k);
    else if (k > root->key) root->right = bst_insert(root->right, k);
    return root;
}

BSTNode* bst_min(BSTNode* node) {
    BSTNode* cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

BSTNode* bst_delete(BSTNode* root, int k) {
    if (!root) return NULL;
    if (k < root->key) root->left = bst_delete(root->left, k);
    else if (k > root->key) root->right = bst_delete(root->right, k);
    else {
        if (!root->left) { BSTNode* r = root->right; free(root); return r; }
        else if (!root->right) { BSTNode* l = root->left; free(root); return l; }
        BSTNode* succ = bst_min(root->right);
        root->key = succ->key;
        root->right = bst_delete(root->right, succ->key);
    }
    return root;
}

void bst_inorder(BSTNode* root) {
    if (!root) return; bst_inorder(root->left); printf("%d ", root->key); bst_inorder(root->right);
}

void bst_free(BSTNode* root) {
    if (!root) return; bst_free(root->left); bst_free(root->right); free(root);
}
