#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

//Headers
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//Data Structures
typedef struct _treenode_ TreeNode;
struct _treenode_{
    int32_t data;
    TreeNode *left;
    TreeNode *right;

};

typedef struct _bst_ BST;
struct _bst_{
    TreeNode *root;
    uint32_t mass;
};


//User Defined Functions
BST bst_new();
uint32_t bst_count(BST *tree);
BST* bst_add(BST *tree, int32_t element);
BST* bst_delete(BST *tree, int32_t element);
void bst_inorder(BST *tree);
void bst_preorder(BST *tree);
void bst_postorder(BST *tree);
void bst_levelorder(BST *tree);
uint8_t bst_lookup(BST *tree,int32_t key);



#endif // TREE_H_INCLUDED
