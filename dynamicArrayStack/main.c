#include "dynamicArrayStack.h"
#include <stdio.h>

#define BUFFER_SIZE 5
int main()
{
    dynamicArrayStack stack;

    /* 怎么解决套壳问题 */
    dynamicArrayStackInit(&stack);

    int buffer[BUFFER_SIZE] = {5, 21, 5, 4, 24};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        dynamicArrayStackPush(&stack, &buffer[idx]);
    }
    int size = 0;
    dynamicArrayStackGetSize(&stack, &size);
    printf("size :%d\n", size);

    int *val = NULL;
    while (!dynamicArrayStackIsEmpty(&stack))
    {
        dynamicArrayStackTop(&stack, (void **)&val);
        printf("val:%d\n", *val);
        dynamicArrayStackPop(&stack);
    }

    /* 栈的销毁 */
    dynamicArrayStackDestory(&stack);

    return 0;
}