#include"slist.h"
//Stack
static Node* _get_new_node_(int32_t element)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = element;
    newnode->next = NULL;
    return newnode;
}

Stack stack_new()
{
    Stack stack = {NULL,0,EMPTY};
    return stack;
}

uint8_t stack_empty(Stack *stk)
{
    assert(stk != NULL);
    return(stk->count == 0);
}

Stack* stack_push(Stack *stk, int32_t element)
{
    assert(stk != NULL);
    Node *newnode = _get_new_node_(element);
    //if elements are already present in th stack.
    if(stk->count > 0)
    {
        newnode->next = stk->top;
        stk->top = newnode;
    }
    //First element in the stack
    else
    {
        stk->top = newnode;
    }
    stk->status = OK;
    ++stk->count;

    return stk;
}

Stack* stack_pop(Stack *stk)
{
    assert(stk != NULL);
    Node *pop = stk->top;

    if(stk->count > 0)
    {
        stk->top = stk->top->next;
        --stk->count;
        stk->status = OK;
    }
    else
    {
        stk->status = EMPTY;
    }
    free(pop);

    return stk;
}

int32_t stack_peek(Stack *stk)
{
    assert(stk != NULL);
    if(stk->count > 0)
    {
        return(stk->top->data);
    }
    else
    {
        return 0;
    }
}
//Queue
Queue queue_new()
{
    Queue q = {NULL,NULL,0,EMPTY};
    return q;
}

uint8_t queue_empty(Queue *q)
{
    assert(q != NULL);
    return(q->count == 0);
}

Queue* queue_add(Queue *q, int32_t element,QueueResult *res)
{
    assert(q != NULL);
    Node *newnode = _get_new_node_(element);
    if(q->count > 0)
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    else
    {
        q->rear = q->front = newnode;
    }
    q->status = OK;
    res->data = element;
    res->status = OK;
    ++q->count;

    return q;
}

Queue* queue_delete(Queue *q,QueueResult *res)
{
    assert(q != NULL);
    Node *del = q->front;
    if(q->count > 0)
    {
        q->front = q->front->next;
        --q->count;
        //if queue had only one element
        if(q->count == 0)
            q->rear = NULL;

        q->status = OK;
        res->data = del->data;
        res->status = OK;

    }
    else
    {
        q->status = EMPTY;
        res->status =EMPTY;
    }

    free(del);
    return q;
}


