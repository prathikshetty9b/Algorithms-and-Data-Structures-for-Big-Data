#include "adaptive.h"
#include <assert.h>

void test_queue()
{
    Queue queue = queue_new(3);
    Queue *q = &queue;

    QueueResult result = {0,QUEUE_OK};
    QueueResult *res = &result;


    assert(q->size == 3);
    assert(q->front == q->rear);
    assert(q->count == 0);

    //Test empty queue
    assert(queue_empty(q) == 1);

    //Test adding element to queue
    queue_add(q,10,res);

    assert(q->data[q->front] == 10);
    assert(q->count == 1);

    queue_add(q,20,res);

    assert(q->data[q->front+1] == 20);
    assert(q->count == 2);

    queue_add(q,30,res);

    assert(q->data[q->front+2] == 30);
    assert(q->data[q->rear] == 10);
    assert(q->count == 3);

    //test queue full
    assert(queue_full(q) == 1);

    //Test deleting element from queue
    queue_delete(q,res);

    assert(res->status = QUEUE_OK);
    assert(q->count == 2);

    queue_delete(q,res);
    queue_delete(q,res);

    assert(q->count == 0);

    queue_delete(q,res);

    assert(res->status == QUEUE_EMPTY);


}

int main()
{
    test_queue();
    return 0;
}

