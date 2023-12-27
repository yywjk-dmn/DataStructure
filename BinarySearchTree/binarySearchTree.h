#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE void* 
typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;  /* 左子树 */
    struct BSTreeNode *right;  /* 右子树 */
    #if 1
    struct BSTreeNode *parent;  /* 父节点 */
    #endif

} BSTreeNode;

typedef struct BinarySearchTree
{
    /* 根结点 */
    BSTreeNode * root;
    /* 树的结点个数 */
    int size;
    // /* 树的高度 */
    // int height;
    /* 钩子函数比较器 放到结构体 */
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);

    /* 钩子函数 包装器实现自定义打印函数接口 */
    int (*printFunc)(ELEMENTTYPE val);

    /* 把队列的属性放在结构体里 */
} BinarySearchTree;

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree);

/* 二叉遍历树的层序遍历 */
int binarySearchTreeLeveOrderTravel(BinarySearchTree *pBstree);

/* 获取二叉搜索数的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight);

/* 二叉搜索树的删除 */
int binarySearchTreeDelste(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的销毁 */
int binarySearchTreeDestory(BinarySearchTree *pBstree);


#endif