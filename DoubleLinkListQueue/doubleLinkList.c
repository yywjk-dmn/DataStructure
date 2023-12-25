#include <stdio.h>
#include "doubleLinkList.h"
#include <stdlib.h>
#include <string.h>
   
/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIND,
};

/* 静态函数只在本源文件（.c）使用 */
/* 静态前置声明 */
static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList * pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));
/* 新建新结点 封装成函数  */
static int createDoubleLinkNode(ELEMENTTYPE val);


/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList ** pList)
{
    int ret = 0;
    DoubleLinkList *list = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);  //分配空间
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(DoubleLinkList) * 1);

    list->head = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);  /* 头节点需要分配空间（有指针但不一定有值) */
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清空脏数据 */
    memset(list->head, 0,sizeof(DoubleLinkNode) * 1);

    list->head->data = 0;
    list->head->next = NULL;

    /* 虚拟头节点的prev指针为null */
    list->head->prev = NULL;
    
    /* 初始化的时候，尾指针 = 头指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针*/
    *pList = list;

    return ret;

}

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, pList->len, val);
}

/* 新建新结点 封装成函数  */
static int createDoubleLinkNode(ELEMENTTYPE val)
{
    /* 封装一个结点 */
    DoubleLinkNode * newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if(newNode == NULL)
    {
        return NULL_PTR;
    }

    /* 清除脏数据 */
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);

    /* 赋值 */
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prev= NULL;

    /* 返回新节点 */
    return newNode;

}
/* 链表指定位置插 */
int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }


    /* 新建新结点 封装成函数  */
    DoubleLinkNode * newNode = createDoubleLinkNode(val);
#if 0     
    /* 封装一个结点 */
    DoubleLinkNode * newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 清除脏数据 */
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);

    /* 赋值 */
    newNode->data = val;
#endif

#if 1
    /* 头结点和虚拟头结点不一样 */
    /* 从虚拟头结点开始遍历 */
    DoubleLinkNode * travelNode = pList->head; 
#else
    DoubleLinkNode * travelNode = pList->head->next;
#endif
    /* 这种情况下需要更改尾指针 */
    int flag = 0;
    if(pos == pList->len)
    {
        travelNode = pList->tail;
        flag = 1;
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;/* 找到想要插入数据的位置 */
            pos--;
        }
        travelNode->next->prev = newNode;  //3  空链表 尾插  有点不清楚
    }   
    newNode->next = travelNode->next;  //1
    newNode->prev = travelNode;  //2
    travelNode->next = newNode;  //4
   
    if(flag)
    {
        pList->tail = newNode;
    }

    
#if 0
    /* 修改结点指向 */
    /* 先断再连，先后再前 */
    newNode->next = travelNode->next; 
    travelNode->next = newNode;
#endif
    /* 更新链表长度 */
    (pList->len)++;

    return ret;
}

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList * pList)
{
    return DoubleLinkListDelAppointPos(pList, 1);
}

/* 链表尾删*/
int DoubleLinkListTailDel(DoubleLinkList * pList)
{
    return DoubleLinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删除 */
int DoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    /* 在链表中有数据才可以删除 */
    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

#if 1
    DoubleLinkNode * travelNode = pList->head;
#else
    DoubleLinkNode * travelNode = pList->head->next;
#endif
    DoubleLinkNode * needDelNode = NULL;
    int flag = 0;
    /* 需要修改尾指针 */
    if (pos == pList->len)
    {
        flag = 1;

        /* 尾指针 */
        DoubleLinkNode * tmpNode = pList->tail;
        /* 调整尾指针 */
        pList->tail = pList->tail->prev;
        needDelNode = tmpNode;

    }
    
    while (--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
        //pos--;
    }
    //跳出循环找到的是哪一个结点
    needDelNode = travelNode->next;           //1
    travelNode->next = needDelNode->next;     //2
    needDelNode->next->prev = travelNode;     //3

    /* 释放内存 */
    if (needDelNode != NULL)
    {
        free(needDelNode); 
    }

    /* 链表长度减一 */
    (pList->len)--;
    return ret;

}

static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList * pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    /* 静态函数只给本源文件的函数用，不需要判断合法性 */
    int ret;

#if 0
    DoubleLinkList *travelNode = pList->head;
#else
    int pos = 1;
    DoubleLinkNode *travelNode = pList->head->next;     //两者的区别
#endif

    int cmp = 0;
    while (travelNode != NULL)
    {
        #if 0
        if (travelNode->data == val)     //在链表中找想要的数据
        {
            /* 解引用 */
            *pPos = pos;
            return pos;
        }
        #else
        cmp = compareFunc(val, travelNode->data);
        if (cmp == 0)
        {
            /* 解引用 */
            *pPos = pos;
            return pos;
        }
        #endif
        travelNode = travelNode->next;
        pos++;
    }
    *pPos = NOT_FIND;
    return NOT_FIND;
}
/* 链表删除指定数据 */
int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    int ret = 0;

    /* 元素在链表中的位置 */
    int pos = 0;
    /* 链表的长度 */
    int size = 0;
    while (DoubleLinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        /* 根据指定的元素得到在链表中所在的位置 */
        int pos = 0;
        DoubleLinkListAccordAppointValGetPos(pList, val, &pos, compareFunc);
        DoubleLinkListDelAppointPos(pList, pos);
    }
    return ret;
   
}

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList * pList, int *pSize)
{

    if(pList == NULL)
    {
        return NULL_PTR;
    }
    if(pSize)
    {
        *pSize = pList->len;
    }

    /* 返回链表的长度 */
    return pList->len;
}

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList * pList)
{
    int ret = 0;
    /* 使用头删，循环删除头指针，释放链表 */
    int size = 0;
    while (DoubleLinkListGetLength(pList, &size))
    {
        DoubleLinkListHeadDel(pList);
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        /* 指针置为NULL */
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ret;

}
/* 链表的遍历 */
int DoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    /* travelNode 指向虚拟头结点 */ 
    DoubleLinkNode * travelNode = pList->head;
     while (travelNode != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:\n", travelNode->data);
    }
#else
    DoubleLinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        #if 0
        printf("travelNode->data:%d\n", travelNode->data);
        #else
        /* 包装器，钩子，回调函数 */
        printFunc(travelNode->data);
        #endif
        travelNode = travelNode->next;
    }

    // printFunc1(travelNode->data,travelNode->next->data);

#endif
    return ret;
}

/* 链表的逆序遍历 */
int DoubleLinkListReverseForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    DoubleLinkNode * travelNode = pList->tail;
    while (travelNode != pList->head)
    {
        /* 包装器，钩子，回调函数 */
        printFunc(travelNode->data);

        /* 移动前指针 */
        travelNode = travelNode->prev;
    }

    return ret;

}

/* 获取链表 头位置的值 */
int DoubleLinkListGetHeadVal(DoubleLinkList * pList, ELEMENTTYPE *val)
{
    #if 0
    return DoubleLinkListGetAppointPosVal(pList, 0, pVal);
    #else
    
    #endif

}

/* 获取链表 尾位置的值 */
int DoubleLinkListGetTailVal(DoubleLinkList * pList, ELEMENTTYPE *val)
{

}

/* 获取链表指定位指的值 */
int DoubleLinkListGetAppointPosVal(DoubleLinkList * pList,int pos, ELEMENTTYPE *pVal)
{

}