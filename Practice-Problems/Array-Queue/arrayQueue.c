#include "arrayQueue.h"

Queue queue_new(uint32_t size)
{
    size = (size > 0 && size < MAX_DEPTH)?size:MAX_DEPTH;
    Queue queue = {size,0,0,0,{0}};
    return queue;
}

uint8_t queue_empty(Queue *q)
{
    assert(q != NULL);
    return(q->count == 0);
}

uint8_t queue_full(Queue *q)
{
    assert(q != NULL);
    return(q->count == q->size);
}

Queue* queue_add(Queue *q, int element, QueueResult *res)
{
    assert(q != NULL);
    //Queue not full
    if(q->count < q->size)
    {
        q->data[q->rear] = element;
        q->rear = (q->rear+1)%q->size;
        ++q->count;
        res->data = element;
        res->status = QUEUE_OK;
    }
    //queue full
    else
    {
        res->data = element;
        res->status = QUEUE_FULL;
    }
    return q;
}

Queue* queue_delete(Queue *q,QueueResult *res)
{
    assert(q != NULL);
    //Elements are present
    if(q->count > 0)
    {
        res->data = q->data[q->front];
        q->front = (q->front+1)%q->size;
        --q->count;
        res->status = QUEUE_OK;

    }
    //Empty queue
    else
    {
        res->status = QUEUE_EMPTY;
    }
    return q;
}
