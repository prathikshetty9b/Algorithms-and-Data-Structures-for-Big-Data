#include "arrayStack.h"
#include <assert.h>


Stack stack_new(uint32_t size)
{
    size = (size > 0 && size < MAX_DEPTH)?size:MAX_DEPTH;
    Stack stk = {size,-1,{0}};
    return stk;
}

uint8_t stack_empty(Stack *stk)
{
    assert(stk != NULL);
    return(stk->top == -1);
}

uint8_t stack_full(Stack *stk)
{
    assert(stk != NULL);
    return(stk->top+1 == stk->size);
}

Stack* stack_push(Stack *stk, int element, StackResult *res)
{
    assert(stk != NULL);
    //Stack not full
    if(stk->top+1 < stk->size)
    {
        stk->data[++stk->top] = element;
        res->data = element;
        res->status = STATUS_OK;
    }
    //Stack Full
    else
    {
        res->data = element;
        res->status = STATUS_FULL;
    }
    return stk;
}

Stack* stack_pop(Stack *stk,StackResult *res)
{
    assert(stk != NULL);
    //Stack Not Empty
    if(stk->top > -1)
    {
        res->data = stk->data[stk->top];
        res->status = STATUS_OK;
        --stk->top;
    }
    //Stack Empty
    else
    {
        res->status = STATUS_EMPTY;

    }
    return stk;
}

int stack_peek(Stack *stk,StackResult *res)
{
    assert(stk != NULL);
    //Stack Not Empty
    if(stk->top > -1)
    {
        res->data = stk->data[stk->top];
        res->status = STATUS_OK;
    }
    //Stack Empty
    else
    {
        res->status = STATUS_EMPTY;

    }
    return stk->data[stk->top];
}
