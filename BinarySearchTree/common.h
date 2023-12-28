#ifndef __COMMON_H
#define __COMMON_H


#define ELEMENTTYPE void*
/* 链表结点 取别名*/
typedef struct DoubleLinkNode
{
    /* 指针的内容 */
    ELEMENTTYPE data;
    
    struct DoubleLinkNode * prev;
    /* 指向下一个结点的指针 */
    struct DoubleLinkNode *next;   /* 指针类型 */

} DoubleLinkNode;



/* 链表 */
typedef struct DoubleLinkList
{
    DoubleLinkNode * head;  /* 链表的虚拟头结点 */
    DoubleLinkNode * tail;  /* 为什么尾指针不需要分配空间 */

    int len;         /* 链表长度 */

} DoubleLinkList;

#endif
