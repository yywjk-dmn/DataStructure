#ifndef __DoubleLinkListQueue_H
#define __DoubleLinkListQueue_H

/* 队列的初始化 */
int doubleLinkListQueueInit();

/* 队列入队 */
int doubleLinkListQueuePush();

/* 查看队头元素 */
int doubleLinkListQueueTop();

/* 队尾元素 */
int doubleLinkListQueueRear();

/* 队列出队 */
int doubleLinkListQueuePop();

/* 队列长度，大小 */
int doubleLinkListQueueGetSize();

/* 队列是否为空 */
int doubleLinkListQueueIsEmpty();

/* 队列销毁 */
int doubleLinkListQueueDestory();
#endif