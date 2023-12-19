#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROE,
    INVALID_ACCESS,
};

#define DEFAULIT_SIZE 10

/* 静态函数前置声明 */
static int expandDynamicCapacity(dynamicArray *pArray);


/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 避免传入非法值 */
    if (capacity < 0)
    {
        capacity = DEFAULIT_SIZE;
    }

    /* 分配空间 */
    pArray->data =(ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROE;
    }
    /* 清除脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    /* 初始化动态数组的参数属性 */
    pArray->data = NULL;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}

/* 动态数组插入数据:默认插到数组的末尾 */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    return dynamicArrayAppointPosInsertData(pArray, pArray->len, val);
}
/* 动态数组扩容 */
static expandDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;

    /* 备份指针 */
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROE;
    }

    /* 把之前的数据全部拷贝过来 */
    for (int idx = 0;idx < pArray; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 释放之前的内存 避免内存泄漏 */
    if (tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    /* 更新动态数组的数量 */
    pArray->capacity = needExpandCapacity;
    
    return ret;
}

/* 动态数组插入数据，在指定位置插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if (pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }
    #if 1
    /* 数组扩容的临界值是：数组的大小的1.5倍 >= 数组容量 */
    if (pArray->len + (pArray->len >> 1) >= pArray->capacity)
    {
        /* 开始扩容 */ 
        expandDynamicCapacity(pArray);
    }
    #else
    if (pArray->len == pArray->capacity)
    {
         /* 开始扩容 */ 
        expandDynamicCapacity(pArray);
    }
    #endif
    

#if 1
    /* 数据后移 流出pos位置插入 */
    for (int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
#else
    for (int idx = pos; idx < pArray->len;idx++)
    {
        pArray->data[idx + 1] = pArray->data[idx];
    }
#endif
    /* 找到对应的值 写入到数组中 */
    pArray->data[pos] = val;
    /* 数组的大小加一 */
    (pArray->len)++;
    return ON_SUCCESS;
}

/* 动态数组修改指定位置的数据 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（默认情况下删除最末尾的数据）*/
int dynamicArrayDeleteData(dynamicArray *pArray);

/* 动态数组删除指定位置数据 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos);

/* 动态数组删除指定的元素 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组的销毁 */
int dynamicArrayDestroy(dynamicArray *pArray, int pos);

/* 获取数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

/* 获取数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);