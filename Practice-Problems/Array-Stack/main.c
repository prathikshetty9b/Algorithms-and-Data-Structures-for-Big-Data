#include "arrayStack.h"
#include<assert.h>

void test_array_stack()
{
    Stack stack = stack_new(2);
    Stack *stk = &stack;

    StackResult result = {0,STATUS_OK};
    StackResult *res = &result;


    //Test stack_new
    assert(stk->size == 2);
    assert(stk->top == -1);

    //Test stack_empty
    assert(stack_empty(stk) == 1);

    //Test push operation
    stack_push(stk,20,res);

    assert(res->status == STATUS_OK);
    assert(res->data == 20);
    assert(stk->data[stk->top] == 20);

    stack_push(stk,30,res);

    assert(res->status == STATUS_OK);
    assert(res->data == 30);
    assert(stk->data[stk->top] == 30);

    stack_push(stk,40,res);

    assert(res->status == STATUS_FULL);
    assert(res->data == 40);
    assert(stk->data[stk->top] == 30);

    //test stack_full

    assert(stack_full(stk) == 1);

    //Test pop operation
    stack_pop(stk,res);

    assert(res->status == STATUS_OK);
    assert(res->data == 30);
    assert(stk->data[stk->top] == 20);

    stack_pop(stk,res);

    assert(res->status == STATUS_OK);
    assert(res->data == 20);
    assert(stk->top == -1);

    stack_pop(stk,res);

    assert(res->status == STATUS_EMPTY);
    assert(stk->top == -1);

    //Test peek operation
    stack_push(stk,30,res);
    assert(stack_peek(stk,res) == 30);



}

int main()
{
    test_array_stack();

    return 0;
}

