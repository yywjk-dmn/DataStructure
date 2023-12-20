#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE int
/* 链表结点取别名 */
typedef struct LinkList
{
    ELEMENTTYPE data;
    /* 指向下一个结点的指针 */
    struct LinkList *next;   /* 指针的类型为什么是结点 */
} LinkNode;

typedef struct  LINKLIST
{
    /* 链表的虚拟头结点 */
    LinkNode * head;

    /* 链表的长度 */
    int len;
    
} LINKLIST;

/* 链表初始化 */
int LinkListInit(LinkList **pList);

/* 链表头插 */
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val);

/* 链表尾插 */
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList *pList,int pos, ELEMENTTYPE val);

/* 链表头删 */
int LinkListHeadDel(LinkList * pList);

/* 链表尾删 */
int LinkListTailDel(LinkList * pList);

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList * pList, int pos);

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE *val);

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *psize);

/* 链表的销毁 */
int LinkListDestroy(LinkList * pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList);

#endif