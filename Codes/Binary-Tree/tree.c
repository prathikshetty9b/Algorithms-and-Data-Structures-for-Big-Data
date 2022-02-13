#include "tree.h"
#include "slist.h"


//Create Tree Node
static TreeNode* _get_new_node_(int32_t element)
{
    TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = element;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BST bst_new()
{
    BST bst = {NULL,0};
    return bst;
}

uint32_t bst_count(BST *tree)
{
    assert(tree != NULL);
    return tree->mass;
}

BST* bst_add(BST *tree, int32_t element)
{
    assert(tree != NULL);
    TreeNode *cur,*parent;
    cur = parent = tree->root;

    //To find the location where new node will be added
    while(cur != NULL && cur->data != element)
    {
        parent = cur;
        if(element < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    //Adding new node to tree
    if(cur == NULL)
    {
        TreeNode *new_node = _get_new_node_(element);
        //No Node
        if(parent == NULL)
            tree->root = new_node;
        //Left
        else if(element < parent->data)
            parent->left = new_node;
        //Right
        else
            parent->right = new_node;

        ++tree->mass;
    }

    return tree;

}



//Private Function

static TreeNode* _findMin_(TreeNode *node)
{
    if(node->left == NULL)
    {
        return node;
    }
    else
    {
        return _findMin_(node->left);
    }
}

static TreeNode* _delete_(BST *tree, TreeNode *node, int32_t element)
{
    assert(tree != NULL);
    if(node == NULL)
    {
        return node;
    }
    else if(element < node->data)
    {
        node->left = _delete_(tree,node->left,element);
    }
    else if(element > node->data)
    {
        node->right = _delete_(tree,node->right,element);
    }
    else if(node->left && node->right )
    {
        TreeNode *temp = _findMin_(node->right);
        node->data = temp->data;
        node->right = _delete_(tree,node->right,node->data);
    }
    else
    {
        TreeNode *temp = node;
        if(node->left == NULL)
            node = node->right;
        else
            node = node->left;

        free(temp);
        --tree->mass;
    }
    return node;

}



BST* bst_delete(BST *tree, int32_t element)
{
    assert(tree != NULL);
    tree->root = _delete_(tree,tree->root,element);
    return tree;
}


static void _inorder_(TreeNode *node)
{
    if(node != NULL)
    {
        _inorder_(node->left);
        printf("%d\t", node->data);
        _inorder_(node->right);
    }
}

void bst_inorder(BST *tree)
{
    assert(tree != NULL);
    _inorder_(tree->root);
}

static void _preorder_(TreeNode *node)
{
    if(node != NULL)
    {
        printf("%d\t",node->data);
        _preorder_(node->left);
        _preorder_(node->right);
    }
}

void bst_preorder(BST *tree)
{
    assert(tree != NULL);
    _preorder_(tree->root);
}

static void _postorder_(TreeNode *node)
{
    if(node != NULL)
    {
        _postorder_(node->left);
        _postorder_(node->right);
        printf("%d\t",node->data);
    }
}
void bst_postorder(BST *tree)
{
    assert(tree != NULL);
    _postorder_(tree->root);
}


void bst_levelorder(BST *tree)
{
    assert(tree != NULL);
    Queue q1 = queue_new();
    Queue *q = &q1;
    QueueResult res;

    TreeNode *node = tree->root;

    queue_add(q,node,&res);

    while(!queue_empty(q))
    {
        queue_delete(q,&res);
        node = (TreeNode*)res.data;
        printf("%d\t",node->data);
        if(node->left)
            queue_add(q,node->left,&res);
        if(node->right)
            queue_add(q,node->right,&res);
    }

}
uint8_t bst_lookup(BST *tree,int32_t key)
{
    assert(tree != NULL);
    TreeNode *cur = tree->root;
    while( cur != NULL && cur->data != key)
    {
        if(key > cur->data)
            cur = cur->right;
        else
            cur = cur->left;

    }

   return(cur != NULL);
}

