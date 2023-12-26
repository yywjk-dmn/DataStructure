#include "dynamicArrayStack.h"
#include "dynamicArray.h"
#define DEFAULIT_SIZE 10

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStack *pStack)
{
    return dynamicArrayInit(pStack, DEFAULIT_SIZE);
}

/* 压栈 */
int dynamicArrayStackPush(dynamicArrayStack *pStack, ELEMENTTYPE val)
{
    /* 调用动态数组的尾插 */
    return (pStack, val);
}

/* 查看栈顶元素 */
int dynamicArrayStackTop(dynamicArrayStack *pStack, ELEMENTTYPE *pVal)
{
    /* 调用动态数组的获取指定位置的数据接口 */
    return dynamicArrayGetAppointPosVal(pStack, pStack->len - 1, pVal);

}

/* 出栈 */
int dynamicArrayStackPop(dynamicArrayStack *pStack)
{
    return dynamicArrayDeleteData(pStack); 


}

/* 判断栈是否为空 */
int dynamicArrayStackIsEmpty(dynamicArrayStack *pStack)
{
    int size = 0;
    dynamicArrayGetSize(pStack, &size);
    return size == 0 ? 1 : 0;

}

/* 获得栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStack *pStack, int *pSize)
{
    #if 1
    return dynamicArrayGetSize(pStack, pSize);
    #else
    dynamicArrayGetSize(pStack, pSize);
    if (pSize)
    {
        return *pSize;
    }

    #endif

}

/* 栈的销毁 */
int dynamicArrayStackDestory(dynamicArrayStack *pStack)
{
    return dynamicArrayDestroy(pStack);
}
