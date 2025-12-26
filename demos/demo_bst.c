#include "../include/dsa.h"

extern BSTNode* bst_insert(BSTNode* root, int k);
extern void bst_inorder(BSTNode* root);
extern BSTNode* bst_delete(BSTNode* root, int k);
extern void bst_free(BSTNode* root);

int main(void) {
    BSTNode* root = NULL;
    int vals[] = { 8, 3, 10, 1, 6, 14 };
    for (int i=0;i<6;i++) root = bst_insert(root, vals[i]);
    printf("Inorder: "); bst_inorder(root); printf("\n");
    root = bst_delete(root, 3);
    printf("After deleting 3: "); bst_inorder(root); printf("\n");
    bst_free(root);
    return 0;
}
