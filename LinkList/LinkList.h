#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE int
/* 链表结点取别名 */
typedef struct LinkLinst
{
    ELEMENTTYPE data;
    /* 指向下一个结点的指针 */
    struct LinkLinst *next;   /* 指针的类型为什么是结点 */
} LinkNode;

typedef struct  LINKLIST
{
    /* 链表的虚拟头结点 */
    LinkNode * head;

    /* 链表的长度 */
    int len;
    
} LINKLIST;

/* 链表初始化 */
int LinkListInit();

/* 链表头插 */
int LinkListHeadInsert();

/* 链表尾插 */
int LinkListTailInsert();

/* 链表指定位置插入 */
int LinkListAppointPosInsert();

/* 链表头删 */
int LinkListHeadDel();

/* 链表尾删 */
int LinkListTailDel();

/* 链表指定位置删除 */
int LinkListDelAppointPos();

/* 链表删除指定数据 */
int LinkListDelAppointData();

/* 获取链表的长度 */
int LinkListGetLength();

/* 链表的销毁 */
int LinkListDestroy();

#endif