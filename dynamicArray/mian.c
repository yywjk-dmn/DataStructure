#include <stdio.h>
#include "dynamicArray.h"
#include <string.h>

#define BUFFER_SIZE 20
#define DEFAULT_NUM 6

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

int compareData(void *arg1, void *arg2)
{
    int num1 = *(int *)arg1;
    int num2 = *(int *)arg2;

    return num1 == num2 ? 1:0;
}

int main()
{
    dynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array, BUFFER_SIZE);
    #if 1
    /* 模块化 */
    {
        /* 插入数据 */
        for (int idx = 1; idx <= DEFAULT_NUM; idx++)
        {
            dynamicArrayInsertData(&array, idx);
        }

    }

    /* 模块化 */
    {
        /* 获取动态数组的大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        printf("size:%d\n", size);
    }

    {
        /* 获取动态数组的大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        int val = 0;
        for (int idx = 0 ;idx < size; idx++)
        {
            dynamicArrayGetAppointPosVal(&array, idx, &val);
            printf("val:%d\t", val);
        }
        printf("\n");
    }

    #endif



    return 0;
}