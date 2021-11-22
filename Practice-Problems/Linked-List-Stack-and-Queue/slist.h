
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include<stdint.h>
#include<assert.h>
#include<stdlib.h>

/*----Data Structures---*/
#define OK 1
#define EMPTY 0
#define FULL 4


//Node
typedef struct _node_ Node;
struct _node_{
    int32_t data;
    Node *next;
};

//Stack
typedef struct _stack_ Stack;
struct _stack_{
    Node *top;
    uint32_t count;
    uint8_t status;
};

//Queue
typedef struct _queue_ Queue;
struct _queue_{
    Node *front;
    Node *rear;
    uint32_t  count;
    uint8_t status;
};

//Stack Functions
Stack stack_new();
uint8_t stack_empty(Stack *stk);
Stack* stack_push(Stack *stk, int32_t element);
Stack* stack_pop(Stack *stk);
int32_t stack_peek(Stack *stk);

//Queue Functions
Queue queue_new();
uint8_t queue_empty(Queue *q);
Queue* queue_add(Queue *q, int32_t element);
Queue* queue_delete(Queue *q);
#endif // SLIST_H_INCLUDED
