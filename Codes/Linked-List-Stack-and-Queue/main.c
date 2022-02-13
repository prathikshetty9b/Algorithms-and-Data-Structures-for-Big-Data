#include "slist.h"

void test_stack()
{
    Stack stack = stack_new();
    Stack *stk = &stack;

    //test stack_new()
    assert(stk->count == 0 && stk->status == EMPTY && stk->top == NULL);

    //test stack_empty()
    assert(stack_empty(stk) == 1);

    //test push operation
    stack_push(stk,20);
    stack_push(stk,30);
    stack_push(stk,40);

    assert(stk->top->data == 40);
    assert(stk->top->next->data == 30);
    assert(stk->count == 3);
    assert(stk->status == OK);
    assert(stack_empty(stk) == 0);

    //test pop operation

    stack_pop(stk);
    assert(stk->count == 2);
    assert(stk->status == OK);

    stack_pop(stk);
    assert(stk->count == 1);
    assert(stk->status == OK);

    stack_pop(stk);
    assert(stk->count == 0);
    assert(stk->status == OK);

    stack_pop(stk);
    assert(stk->count == 0);
    assert(stk->status == EMPTY);

    //test peek operation
    assert(stack_peek(stk) == EMPTY);

    stack_push(stk,20);
    stack_push(stk,30);
    stack_push(stk,40);

    assert(stack_peek(stk) == 40);


}

void test_queue()
{
    Queue queue = queue_new();
    Queue *q = &queue;

    //test new queue
    assert(q->front == q->rear && q->count == 0 &&q->front == NULL && queue_empty(q) == 1);

    //Add operation
    queue_add(q,20);
    queue_add(q,30);
    queue_add(q,40);
    queue_add(q,50);

    assert(q->front->data == 20 && q->rear->data == 50 && q->count == 4 && q->status == OK);

    //Delete operation
    queue_delete(q);
    assert(q->front->data == 30 && q->rear->data == 50 && q->count == 3 && q->status == OK);

    queue_delete(q);
    assert(q->front->data == 40 && q->rear->data == 50 && q->count == 2 && q->status == OK);

    queue_delete(q);
    assert(q->front->data == 50 && q->rear->data == 50 && q->count == 1 && q->status == OK);

    queue_delete(q);
    assert(q->front == NULL  && q->rear == NULL && q->count == 0 && q->status == OK);

    queue_delete(q);
    assert(q->front == NULL  && q->rear == NULL && q->count == 0 && q->status == EMPTY);

}

int main()
{
    test_stack();
    test_queue();
    return 0;
}
