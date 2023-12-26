#include "binarySearchTree.h"
#include "doubleLinkListQueue.h"
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
/* 比较函数 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
/* 创建新结点 */
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parent);
/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTressNode(BinarySearchTree *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwochiledrens(BSTreeNode *node);
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOnechiledren(BSTreeNode *node);
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);
/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 后序遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node);
/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node);




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
int binarySearchTreeInit(BinarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
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
        /* 钩子函数在这边赋值 */
        bstree->compareFunc = compareFunc;

        /* 钩子函数包装器 自定义打印 */
        bstree->printFunc = printFunc;
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
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
   
    *pBstree = bstree;
    return ret;

}

#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
   return val1 - val2;
}
#endif
/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwochiledrens(BSTreeNode *node)
{
    return node->left != NULL && node->right != NULL;
}

/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOnechiledren(BSTreeNode *node)
{
    return ((node->left == NULL) && (node->right != NULL)) || ((node->left != NULL) && (node->right == NULL));
}

/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    return node->left == NULL && node->right == NULL;
}

/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node)
{
    /* 度为2 */
    if (binarySearchTreeNodeHasTwochiledrens(node))
    {
        BSTreeNode *travelNode = node->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;

        }
        return travelNode;
        
    }


    /* 度为1 */

    /* 度为0 */
}

/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node)
{

}




/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
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
        cmp = pBstree->compareFunc(val, travelNode->data);

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

/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;

    }
    
    pBstree->printFunc(node->data);
    inOrderTravel(pBstree, node->left);
    
    inOrderTravel(pBstree, node->right);


}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    preOrderTravel(pBstree, pBstree->root);

    return ret;

}


/* 中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;

    }
    inOrderTravel(pBstree, node->left);
    pBstree->printFunc(node->data);
    inOrderTravel(pBstree, node->right);

}


/* 二叉搜索树的中序遍历  升序 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    inOrderTravel(pBstree, pBstree->root);

    return ret;

}



/* 后序遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;

    }
    inOrderTravel(pBstree, node->left);
    
    inOrderTravel(pBstree, node->right);

    pBstree->printFunc(node->data);

}


/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;
    postOrderTravel(pBstree, pBstree->root);
    return ret;

}

/* 二叉遍历树的层序遍历 */
int binarySearchTreeLeveOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;

    /* 初始化队列 */
    DoubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue);

    /* 将根结点入队 */
    doubleLinkListQueuePush(queue, pBstree->root);

    /* 判断队列是否为空 */
    BSTreeNode *nodeVal = NULL;
    while (doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&nodeVal);

        //printf("data:&d\n", nodeVal->data);
        pBstree->printFunc(nodeVal->data);
        doubleLinkListQueuePop(queue);

        /* 将左子树入队 */
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->left);
        }

        /* 将右子树入队 */
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->right);
        }
    }

    /* 释放队列 */
    doubleLinkListQueueDestory(queue);

    return ret;                                            

}

/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTressNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode * travelNode = pBstree->root;
    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 比较大小 */
        cmp = pBstree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return travelNode;
        }
    }
    return NULL;

}

/* 二叉搜索树是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTressNode(pBstree, val) == NULL ? 0 : 1;

}


/* 获取二叉搜索数的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree)
{

}