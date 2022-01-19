#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "slist.h"

void test_bst()
{
    //Create new tree
    BST bst = bst_new();
    BST *tree = &bst;

    assert(tree->root == NULL && tree->mass == 0);

    //Add elements to tree
    bst_add(tree, 50);
    bst_add(tree, 40);
    bst_add(tree , 30);
    bst_add(tree, 60);
    bst_add(tree, 80);
    bst_add(tree, 55);

    assert(tree->mass == 6 && bst_count(tree) == 6);
    assert(tree->root->data == 50 && tree->root->left->data == 40 && tree->root->right->data == 60);

    //Tree lookup
    assert(bst_lookup(tree,50) == 1);
    assert(bst_lookup(tree,30) == 1);
    assert(bst_lookup(tree,80) == 1);
    assert(bst_lookup(tree,54) == 0);

    //Delete elements
    bst_delete(tree, 55);
    assert(bst_lookup(tree, 55) == 0 && bst_count(tree) == 5);
    bst_delete(tree,50);
    assert(bst_lookup(tree,50 ) == 0 && tree->root->data == 60);


    //Pre-order Post-order and inorder
    bst_add(tree, 50);
    bst_add(tree, 90);
    bst_add(tree, 70);

    printf("\n\n\tInorder \n\n\t");
    bst_inorder(tree);

    printf("\n\n\tPreorder \n\n\t");
    bst_preorder(tree);

    printf("\n\n\tPostorder \n\n\t");
    bst_postorder(tree);

    //Level Order
    printf("\n\n\tLevel Order\n\n\t");
    bst_levelorder(tree);


}

int main()
{
    test_bst();
    return 0;
}
