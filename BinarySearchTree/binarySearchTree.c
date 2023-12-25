#include "binarySearchTree.h"
#include <stdlib.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIND,
};

/* 静态函数的前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

/* 创建结点 */
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parent);

/* 创建结点 */
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parent)
{
    /* 分配根结点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode) *1);
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }

    /* 赋值 */
    newBstNode->data = val;

    newBstNode->parent = parent;
    return newBstNode;

}


/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree)
{
    int ret = 0;
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);

    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
    }
    
#if 0
    /* 分配根节点 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;

    }
    /* 清除脏数据 */
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);

    /* 初始化根节点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;

    }
#endif
    bstree->root = createBSTreeNewNode(0, NULL);
   

    *pBstree = bstree;
    return ret;

}

#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
   return val1 - val2;
}
#endif

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;
    /* 判断是否是空树 */
    if (pBstree->size== 0)
    {
        (pBstree->size)++;

        pBstree->root->data = val;
        return ret;

    }

    /* travelNode  指向根节点 */
    BSTreeNode * travelNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;

    /* 确定符号到底放在左边还是右边 */
    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 标记父结点 */
        parentNode = travelNode;
        cmp = compareFunc(val, travelNode->data);

        /* 插入元素 < 遍历到的结点 */
        if (val < travelNode->data)
        {
            travelNode = travelNode->left;
        }
        /* 插入元素 > 遍历到的结点 */
        else if (val > travelNode->data)
        {
            travelNode = travelNode->right;
        }
        /* 插入元素 = 遍历到的结点 */
        else
        {
            return ret;
        }

    }
    
    #if 0
    /* 分配根结点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode) *1);
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 新结点赋值 */
    newBstNode->data = val;
    #endif

    BSTreeNode * newBstNode = createBSTreeNewNode(val, parentNode);


    /* 挂在左子树 */
    if (cmp < 0)
    {
        parentNode->left = newBstNode;

    }
    /* 挂在右子树 */
    else 
    {
        parentNode->right = newBstNode;
    }

    /* 维护新结点的父结点 */
    newBstNode->parent = parentNode;

    /* 树的大小更新 */
    (pBstree->size)++;



    return ret;


}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉遍历树的层序遍历 */
int binarySearchTreeLeveOrderTravel(BinarySearchTree *pBstree)
{
    
}
